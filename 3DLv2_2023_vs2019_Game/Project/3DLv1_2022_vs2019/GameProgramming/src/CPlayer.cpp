//プレイヤークラスのインクルード
#include "CPlayer.h"

#include "CTaskManager.h"
#include "CApplication.h"
#include "CCollisionManager.h"

#define ROTATION_YV CVector(0.0f,1.0f,0.0f) //回転速度
#define VELOCITY CVector(0.0f,0.0f,0.1f) //移動速度
#define VELOCITY1 CVector(0.0f,0.2f,0.0f) //移動速度
#define VELOCITY2 CVector(0.0f,0.05f,0.0f) //移動速度
#define VELOCITY3 CVector(0.0f,0.2f,0.0f) //移動速
#define ROTATION_XV CVector(1.0f,0.0f,0.0f) //回転速度
#define VELOCITY4 CVector(0.0f,0.01f,0.0f) //移動速
#define VELOCITY10 CVector(0.01f,0.0f,0.0f)

//CPlayer(位置、回転、スケール）
CPlayer::CPlayer(const CVector& pos, const CVector& rot, const CVector& scale)
	: jc(0)
	, n(0)
{
	CTransform::Update(pos, rot, scale);//行列の更新
}

CPlayer::CPlayer()
: mLine(this,&mMatrix,CVector(0.0f,0.0f,0.0f),CVector(0.0f,2.0f,0.0f))
, mLine2(this, &mMatrix, CVector(-0.5f, 1.2f, 0.0f), CVector(0.5f, 1.2f, 0.0f))
, mLine3(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f))
{
	//インスタンスの設定
	spInstance = this;
	randdd = 0;
	randddco = 180;
}

//更新処理
void CPlayer::Update() {
	if (mState != EState::EJUMP)
	{
		if (mInput.Key(VK_SPACE))
		{
			mState = EState::EJUMP;
			jc = 60;
		}
	}
	if (jc > 0)
	{
		jc--;
	}
	//if (mState != EState::EJO)
	{
		if (jc < 45)
		{
			mPosition = mPosition - VELOCITY3 * mMatrixRotate;
		}
	}
	if (mState != EState::EJO)
	{
		if (jc > 50 && jc <= 60)
		{
			mPosition = mPosition + VELOCITY1 * mMatrixRotate;
		}
		if (jc > 0 && jc <= 50)
		{
			mPosition = mPosition + VELOCITY2 * mMatrixRotate;
		}
	}
	//Dキー入力で回転
	if (mInput.Key(VK_RIGHT) || mInput.Key('D')) {
		//Y軸の回転値を減少
		mRotation = mRotation - ROTATION_YV;
	}
	if (mInput.Key(VK_LEFT) || mInput.Key('A') ){
		//Y軸の回転値を増し増し
		mRotation = mRotation + ROTATION_YV;
	}
	//上キー入力で前進
	if (mInput.Key(VK_UP) || mInput.Key('W')) {
		//Z軸方向の値を回転させ移動させるnais
		mPosition = mPosition + VELOCITY * mMatrixRotate;
	}
	if (mInput.Key(VK_DOWN) || mInput.Key('S')) {
		//Z軸方向の値を回転させ移動させるmasi
		mPosition = mPosition - VELOCITY * mMatrixRotate;;
	}
	//変換行列の更新
	CTransform::Update();
	//Ui設定
	CApplication::Ui()->PosY(mPosition.Y());
	CApplication::Ui()->RotX(mRotation.X());
	CApplication::Ui()->RotY(mRotation.Y());
}

void CPlayer::Collision(CCollider* m, CCollider* o) {
	/*CVector adjust;
	if (CCollider::Collision(m,o,adjust))
	{
		mPosition = mPosition + adjust;
		CTransform::Update();
	}*/
	//自身のコライダタイプの判定
	switch (m->Type()) {
	case CCollider::ELINE://線分コライダ
		//相手のコライダが三角コライダの時
		if (o->Type() == CCollider::ETRIANGLE) {
			CVector adjust;//調整用ベクトル
			//三角形と線分の衝突判定
				if (CCollider::CollisionTriangleLine(o, m, &adjust))
				{
					if (mState == EState::EJUMP || mState == EState::EMOVE || mState == EState::EMOVE)
					{
						mState = EState::EJO;
					}
					//位置の更新(mPosition + adjust)
					mPosition = mPosition + adjust;
					//行列の更新
					CTransform::Update();
					if (CApplication::StageSwitch == 1)
					{
						CApplication::StageGuard++;
						CApplication::StageSwitch = 0; //テスト用
					}
				}
		}
		if (o->Type() == CCollider::ETRIANGLE2) {
			CVector adjust;//調整用ベクトル
			if (CCollider::CollisionTriangleLine(o, m, &adjust))
			{
				mPosition = mPosition + adjust;
				//行列の更新
				CTransform::Update();
			}
		}
		if (o->Type() == CCollider::ETRIANGLE3) {
			CVector adjust;//調整用ベクトル
			if (CCollider::CollisionTriangleLine(o, m, &adjust))
			{
				if (mState == EState::EJUMP || mState == EState::EMOVE || mState == EState::EMOVE)
				{
					mState = EState::EJO;
				}
				mPosition = mPosition + adjust;
				//行列の更新
				CTransform::Update();
				if (CApplication::StageSwitch == 0)
				{
					//randddco--; //テスト用
					if (CApplication::StageGuard == 0)
					{
						CApplication::SelectStage = 1; //後にランダム設定に変える
						CApplication::StageSwitch = 1;
						//randddco = 380; //テスト用
					}
					if (CApplication::StageGuard == 1)
					{
						CApplication::SelectStage = 2; //後にランダム設定に変える
						CApplication::StageSwitch = 1;
						//randddco = 580; //テスト用
					}
					if (CApplication::StageGuard == 2)
					{
						CApplication::SelectStage = 3; //後にランダム設定に変える
						CApplication::StageSwitch = 1;
					}
				}
			}
		}
		break;
	}
}

//衝突処理
void CPlayer::Collision()
{
	//コライダの優先度変更
	mLine.ChangePriority();
	mLine2.ChangePriority();
	mLine3.ChangePriority();
	//衝突処理を実行
	CCollisionManager::Instance()->Collision(&mLine, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mLine2, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mLine3, COLLISIONRANGE);
}

CPlayer* CPlayer::spInstance = nullptr;

CPlayer* CPlayer::Instance()
{
	return spInstance;
}