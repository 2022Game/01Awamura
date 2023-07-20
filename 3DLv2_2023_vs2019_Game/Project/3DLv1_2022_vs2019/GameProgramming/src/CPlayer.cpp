//プレイヤークラスのインクルード
#include "CPlayer.h"

#include "CTaskManager.h"
#include "CApplication.h"
#include "CCollisionManager.h"

#include <stdlib.h>

#include "time.h"

#define ROTATION_YV CVector(0.0f,1.0f,0.0f) //回転速度
#define VELOCITY CVector(0.0f,0.0f,0.1f) //移動速度
#define VELOCITY1 CVector(0.0f,0.1f,0.0f) //移動速度
#define VELOCITY2 CVector(0.0f,0.05f,0.0f) //移動速度
#define VELOCITY3 CVector(0.0f,0.2f,0.0f) //移動速
#define ROTATION_XV CVector(1.0f,0.0f,0.0f) //回転速度
#define VELOCITY4 CVector(0.0f,0.01f,0.0f) //移動速
#define VELOCITY10 CVector(0.01f,0.0f,0.0f)

int rand(void);
void srand(unsigned int seed);

//CPlayer(位置、回転、スケール）
CPlayer::CPlayer(const CVector& pos, const CVector& rot, const CVector& scale)
	:CPlayer()
{
	mLastPos = pos;
	mStartPos = pos;
	CTransform::Update(pos, rot, scale);//行列の更新
}

int CPlayer::CountLine = 0;

int CPlayer::CountCraft = 0;

CPlayer::CPlayer()
:CCharacter3((int)TaskPriority::ePlayer)
, mLine(this,&Matrix(),CVector(0.0f,0.0f,0.0f),CVector(0.0f,2.0f,0.0f))
, mLine2(this, &Matrix(), CVector(-0.5f, 1.2f, 0.0f), CVector(0.5f, 1.2f, 0.0f))
, mLine3(this, &Matrix(), CVector(0.0f, 1.0f, -0.5f), CVector(0.0f, 1.0f, 0.5f))
,mGroundedMoveObjTf(nullptr)
,mIsGrounded(false)
, jc(0)
, n(0)
,jswitch(0)
,randdd(0)
,randddco(0)
,mTime(0)
,mRestart(1)
,ddStage(0)
,ccStage(0)
{
	srand((unsigned int)time(NULL));
	//インスタンスの設定
	spInstance = this;
	randdd = 0;
	randddco = 180;
	mpModel = new CModel();
	mpModel->Load("res\\Beard_man.obj", "res\\Beard_man.mtl");
}

//更新処理
void CPlayer::Update() {
	
	if (mTime >= 1000)
	{
		mState = EState::EOVER;
	}

	CTransform::Update();
	//接地している時にジャンプ可能
	if (mIsGrounded)
	{
		//頭上無限ジャンプ回避用
		if (jswitch == 0)
		{
			if (mInput.Key(VK_SPACE))
			{
				mState = EState::EJUMP;
				jc = 60;
				jswitch = 30;
			}
		}
	}
	//ジャンプ中は下降するためにカウントを下げる
	if (jc > 0)
	{
		jc--;
		//頭上無限ジャンプ回避用
		if (jswitch != 0)
		{
			jswitch--;
		}
	}
	//ジャンプ中下降し始める時間
	if (jc < 35)
	{
		Position(Position() - VELOCITY3 * MatrixRotate());
	}
	//ジャンプ開始時上昇する
	if (jc > 40 && jc <= 60)
	{
		Position(Position() + VELOCITY1 * MatrixRotate());
	}
	if (jc > 35 && jc <= 40)
	{
		Position(Position() + VELOCITY2 * MatrixRotate());
	}
	
	if (mInput.Key('O')) {
		//Y軸の回転値を減少
		jc = 60;
	}


	//Dキー入力で回転
	if (mInput.Key(VK_RIGHT) || mInput.Key('D')) {
		//Y軸の回転値を減少
		Rotation(Rotation() - ROTATION_YV);
	}
	if (mInput.Key(VK_LEFT) || mInput.Key('A') ){
		//Y軸の回転値を増し増し
		Rotation(Rotation() + ROTATION_YV);
	}
	//上キー入力で前進
	if (mInput.Key(VK_UP) || mInput.Key('W')) {
		//Z軸方向の値を回転させ移動させるnais
		Position(Position() + VELOCITY * MatrixRotate());
	}
	if (mInput.Key(VK_DOWN) || mInput.Key('S')) {
		//Z軸方向の値を回転させ移動させるmasi
		Position(Position() - VELOCITY * MatrixRotate());
	}
	//変換行列の更新
	CTransform::Update();
	//Ui設定
	if (CApplication::StageCount != 4) //テスト用
	{
		if (CApplication::StageTime == 1)
		{
			CApplication::Ui()->Time(mTime++);
		}
	}
	if (CApplication::StageCount == 4) //テスト用
	{
		CApplication::StageTime = 0;
		mTime = 0;
		mRestart = 0;
	}
	if (CApplication::Rcount == 1)
	{
		Position(mStartPos);
		CApplication::Rcount = 0;
	}
	CApplication::Ui()->PosY(Position().Y());
	CApplication::Ui()->RotX(Rotation().X());
	CApplication::Ui()->RotY(Rotation().Y());
}

//ステージクリア用のオブジェクトに接地時の処理
void CPlayer::GroundedClearObj()
{
	mLastPos = Position() + (CVector(0.0f, 20.0f, 0.0f));
	if (CApplication::StageCountGuard == 0)
	{
		CApplication::StageCountGuard = 1;
	}
	if (CApplication::StageSwitch == 0)
	{
		if (CApplication::StageReset != 1)
		{
			//randddco--; //テスト用
			//CApplication::StageGuard = 0;
			if (CApplication::StageCount == 0)
			{
				//mLastPos = Position();
				CApplication::SelectStage = 1 + rand() % 5;
				ddStage = CApplication::SelectStage; //一度ddStageに入れておく
				CApplication::StageSwitch = 1;
				//randddco = 380; //テスト用
			}
			if (CApplication::StageCount == 1)
			{
				CountLine = 1;
				CountCraft = 1;
				//mLastPos = Position();
				CApplication::SelectStage = 1 + rand() % 5;
				while (CApplication::SelectStage == ddStage)
				{
					CApplication::SelectStage = 1 + rand() % 5;
				}
				ccStage = CApplication::SelectStage; //一度ccStageに入れておく
				CApplication::StageSwitch = 1;
				//randddco = 580; //テスト用
			}
			if (CApplication::StageCount == 2)
			{
				CountLine = 2;
				CountCraft = 2;
				//mLastPos = Position();
				CApplication::SelectStage = 5;// 1 + rand() % 5;
				while (ddStage == CApplication::SelectStage ||
					ccStage == CApplication::SelectStage)
				{
					CApplication::SelectStage = 1 + rand() % 5;
				}
				CApplication::StageSwitch = 1;
			}
			if (CApplication::StageCount == 3)
			{
				CApplication::StageCount = 4;
			}
		}
	}
}

//ステージの壁生成用のオブジェクトに接地の処理
void CPlayer::GroundedGuardObj()
{
	if (CApplication::StageSwitch == 1)
	{
		CApplication::StageGuard = 1;
		CApplication::StageCount++;
		CApplication::StageClearDelete++;
		CApplication::StageCountGuard = 0;
		CApplication::StageSwitch = 0; //テスト
	}
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
	case CCollider::EType::ELINE://線分コライダ
		//相手のコライダが三角コライダの時
		if (o->Type() == CCollider::EType::ETRIANGLE) {
			CVector adjust;//調整用ベクトル
			//mLastPos = Position() + (CVector(0.0f, 20.0f, 0.0f));
			//三角形と線分の衝突判定
				if (CCollider::CollisionTriangleLine(o, m, &adjust))
				{
					//位置の更新
					Position(Position() + adjust);
					//衝突したのが、移動オブジェクトであれば
					if (o->Tag() == CCharacter3::ETag::ESTAGECLEAR ||
						o->Tag() == CCharacter3::ETag::ESTAGEGUARD)
					{
						//衝突した移動オブジェクトを保持しておく
						mGroundedMoveObjTf = o->Parent();
					}

					//行列の更新
					CTransform::Update();

					//接地フラグをON
					mIsGrounded = true;

					//ジャンプや移動中に接地したらジャンプOKにする
					if (mState == EState::EJUMP || mState == EState::EMOVE)
					{
						mState = EState::EJO;
					}

					//ステージの壁生成用のコライダにヒットした場合
					if (o->Tag() == CCharacter3::ETag::ESTAGEGUARD)
					{
						/*if (mState == EState::EJUMP || mState == EState::EMOVE)
						{
							mState = EState::EJO;
						}*/
						GroundedGuardObj();
					}

					//ステージクリア用のコライダにヒットした場合
					else if (o->Tag() == CCharacter3::ETag::ESTAGECLEAR)
					{
						GroundedClearObj();
					}
					else if (o->Tag() == CCharacter3::ETag::EOBSTACLE)
					{

					}

					if (o->Layer()== CCollider::ELayer::EDEATH)
					{
						Position(mLastPos);
						CApplication::StageReset = 1;
						if (CApplication::StageCountGuard == 0)
						{
							CApplication::StageCount--;
							CApplication::StageClearDelete--;
							CApplication::StageCountGuard = 1;
						}
						if (CApplication::StageCount != 4) { //テスト用
							CApplication::Ui()->Restart(mRestart++);
						}
					}
					if (mState == EState::EOVER)
					{

					}

					//CCharacter3* parent = o->Parent();
				}
		}
		//相手のコライダが球コライダの時
		else if (o->Type() == CCollider::EType::ESPHERE && o->Layer() 
			!= CCollider::ELayer::ECOIN) {
			CVector adjust;
			if (CCollider::CollisionSphereLine(o, m, &adjust))
			{
				//位置の更新
				Position(Position() + adjust);
				//行列の更新
				CTransform::Update();
			}
		}
		break;
	}
}

//衝突処理
void CPlayer::Collision()
{
	//接地しているオブジェクトのポインタを初期化
	mGroundedMoveObjTf = nullptr;
	mIsGrounded = false;

	//コライダの優先度変更
	mLine.ChangePriority();
	mLine2.ChangePriority();
	mLine3.ChangePriority();
	//衝突処理を実行
	CCollisionManager::Instance()->Collision(&mLine, COLLISIONRANGE * 10);
	CCollisionManager::Instance()->Collision(&mLine2, COLLISIONRANGE * 10);
	CCollisionManager::Instance()->Collision(&mLine3, COLLISIONRANGE * 10);

	//接地している移動オブジェクトを親に設定
	SetParent(mGroundedMoveObjTf);
}

CPlayer* CPlayer::spInstance = nullptr;

CPlayer* CPlayer::Instance()
{
	return spInstance;
}