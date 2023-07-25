#include "CXPlayer.h"
#include "CCharacter3.h"
#include "CActionCamera.h"

#define ROTATION2_YV CVector(0.0f, 2.0f, 0.0f) //回転速度
#define VELOCITY2 CVector(0.0f, 0.0f, 0.1f) //移動速度

//コライダの初期化
CXPlayer::CXPlayer()
	:mColSphereBody(this, nullptr, CVector(), 0.5f, CCollider::ETag::EBODY)
	,mColSphereHead(this,nullptr,CVector(0.0f,5.0f,-3.0f),0.5f)
	,mColSphereSword(this,nullptr,CVector(-10.0f,10.0f,50.0f),0.3f, CCollider::ETag::ESWORD)
	, AttackFrame(0)
	, AnimaScene(0)
{
	//タグにプレイヤーを設定します
	mTag = EPLAYER;
}

void CXPlayer::Init(CModelX* model)
{
	CXCharacter::Init(model);
	//合成行列の設定
	mColSphereBody.Matrix(&mpCombinedMatrix[9]);
	//頭
	mColSphereHead.Matrix(&mpCombinedMatrix[12]);
	//剣
	mColSphereSword.Matrix(&mpCombinedMatrix[22]);
}

void CXPlayer::Update()
{
	if (AttackFrame != 0)
	{
		AttackFrame--;
	}
	if (mInput.Key(VK_SPACE))
	{
		if (AnimaScene != 4 && AnimaScene != 3)
		{
			ChangeAnimation(AnimaScene = 3, false, AttackFrame = 30);
		}
	}
	if (AnimaScene == 3 && AttackFrame <= 0)
	{
		ChangeAnimation(AnimaScene = 4, false, AttackFrame = 30);
	}
	if (AnimaScene == 4 && AttackFrame <= 0)
	{
		ChangeAnimation(AnimaScene = 0, true, 60);
	}

	//if (mInput.Key('A'))
	//{
	//	//Y軸の回転値を減少
	//	mRotation = mRotation + ROTATION2_YV;
	//}
	//if (mInput.Key('D'))
	//{
	//	//Y軸の回転値を減少
	//	mRotation = mRotation - ROTATION2_YV;
	//}
	//カメラの前方
	CVector cameraZ = CActionCamera::Instance()->VectorZ();
	//カメラの左方向
	CVector cameraX = CActionCamera::Instance()->VectorX();
	//キャラクタの前方
	CVector charZ = mMatrixRotate.VectorZ();
	//XZ平面にして正規化
	cameraZ.Y(0.0f); cameraZ = cameraZ.Normalize();
	cameraX.Y(0.0f); cameraX = cameraX.Normalize();
	charZ.Y(0.0f); charZ = charZ.Normalize();
	//移動方向の設定
	CVector move;
	if (mInput.Key('A')) {
		move = move + cameraX;
	}
	if (mInput.Key('D')) {
		move = move - cameraX;
	}
	if (mInput.Key('W')) {
		move = move + cameraZ;
	}
	if (mInput.Key('S')) {
		move = move - cameraZ;
	}
	//移動あり
	if (move.Length() > 0.0f)
	{
		//遊び
		const float MARGIN = 0.06f;
		//正規化
		move = move.Normalize();
		//自分の向きと向かせたい向きで外積
		float cross = charZ.Cross(move).Y();
		//自分の向きと向かせたい向きで内積
		float dot = charZ.Dot(move);
		//外積がプラスは左回転
		if (cross > MARGIN) {
			mRotation.Y(mRotation.Y() + 5.0f);
		}
		//外積がマイナスは右回転
		else if (cross < -MARGIN) {
			mRotation.Y(mRotation.Y() - 5.0f);
		}
		//前後の向きが同じとき内積は１．０
		else if (dot < 1.0f - MARGIN) {
			mRotation.Y(mRotation.Y() - 5.0f);
		}
		//移動方向へ移動
		//mPosition = mPosition + move * 0.1f;
		//ChangeAnimation(1, true, 60);
	}
	if (mInput.Key('W')|| mInput.Key('A')||mInput.Key('S')||mInput.Key('D'))
	{
		if(AnimaScene != 4 && AnimaScene != 3)
		{
			ChangeAnimation(AnimaScene = 1, true, 60);
			mPosition = mPosition + VELOCITY2 * mMatrixRotate;
		}
	}
	else if(AnimaScene == 1)
	{
		ChangeAnimation(0, true, 60);
	}
	CXCharacter::Update();
}

void CXPlayer::Collision(CCollider* m, CCollider* o) {
	
}