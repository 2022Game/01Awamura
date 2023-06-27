#include "CXPlayer.h"

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
	mColSphereBody.Matrix(&mpCombinedMatrix[8]);
	//頭
	mColSphereHead.Matrix(&mpCombinedMatrix[11]);
	//剣
	mColSphereSword.Matrix(&mpCombinedMatrix[21]);
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

	if (mInput.Key('A'))
	{
		//Y軸の回転値を減少
		mRotation = mRotation + ROTATION2_YV;
	}
	if (mInput.Key('D'))
	{
		//Y軸の回転値を減少
		mRotation = mRotation - ROTATION2_YV;
	}
	if (mInput.Key('W'))
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
	//自身のコライダタイプの判定
	switch (m->Type()) {
	//case CCollider::ESPHERE:
	//	if (o->Tag() == CCollider::ETag::ESWORD)
	//	{
	//		//相手のコライダが三角コライダの時
	//		if (o->Type() == CCollider::ESPHERE) {
	//			ChangeAnimation(11, false, 30);
	//		}
	//	}
	//	break;
	}
}