#include "CSideDownwood.h"
#include "Maths.h"
#include "CPlayer.h"
#include "CCollider.h"
#include "CCleardelta.h"

#define ROTATE_Y -0.1f

#include <stdlib.h>

#include "time.h"

CSideDownwood::CSideDownwood(CModel* model, const CVector& pos, const CVector& scale, float rotateSpeedY)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
	, mRotateSpeedY(rotateSpeedY)
	, mMoveDir(0.0f, 0.0f, 0.0f)
	, mMoveSpeed(0.0f, 0.0f, 0.0f)
	, mKillCount(0)
	, randmodelspeedY(0.0f)
	, randspeedY(0.0f)
	, randx(0)
	, Time(0)
	, mTime(0)
	, mRotateCount(0)
{
	mKillCount = 10;
	//Math::Rand(0, 5);
	mpColliderMesh = new CColliderMesh(this, ELayer::eMoveObject, mpModel, true);
	mpColliderSphere = new CColliderSphere(this, ELayer::eMove, 0.5f, false, 1.0f);
	Position(mDefaultPos);
	mpColliderSphere->Position(0.0f, 5.0f, 0.0f);
	Scale(scale);
	randmodelspeedY = Math::Rand(-2.0f, 2.0f);
	while (randmodelspeedY < 0.5f && randmodelspeedY > -0.5f)
	{
		randmodelspeedY = Math::Rand(-2.0f, 2.0f);
	}

	if (CPlayer::mResetCount == true)
	{
		Position(0.0f, 0.0f, -30.0f);
		//mResetKillwood = true;
	}

	mpColliderSphere->SetCollisionLayers({ ELayer::eField});
}

CSideDownwood::~CSideDownwood()
{
	SAFE_DELETE(mpColliderMesh);
	SAFE_DELETE(mpColliderSphere);
}

void CSideDownwood::Update()
{
	//移動
	//mMoveSpeed = CVector(0.0f, -0.1f, 0.0f);

	////重力加算
	//mMoveSpeed.Y(-10.0f);

	//Position(Position() + mMoveSpeed * Time::DeltaTime());
	/*Time++;
	if (Time == 1200)
	{
		mTime++;
		Time = 0;
	}*/
	///*float per = mElapsedTime / mMoveTime;*/
	////移動

	////移動方向に加速
	//CVector moveSpeedXZ = mMoveSpeed;
	//moveSpeedXZ.Y(0.0f);
	//moveSpeedXZ += mMoveDir * 60.0f * Time::DeltaTime();
	////移動速度を最大値にクランプ
	//static const float maxSpeed = 60.0f;
	//if (moveSpeedXZ.Length() >= maxSpeed)
	//{
	//	moveSpeedXZ = moveSpeedXZ.Normalized() * maxSpeed;
	//}
	//mMoveSpeed.X(randx);
	//mMoveSpeed.Z(moveSpeedXZ.Z());

	//回転周回速度
	Rotate(0.0f, randmodelspeedY, 0.0f);

	if (CCleardelta::mMoveswitch == false)
	{
		//重力加算
		mMoveSpeed.Y(-10.0f);

		Position(Position() + mMoveSpeed * Time::DeltaTime());
	}
	//Position(Position() + mMoveSpeed);

	//倒木のモデル読み込み

	//if (mTime == 1 && Time == 0)
	//{
	//	/*CModel* sidewoodModel = CResourceManager::Get<CModel>("SideDownwood");
	//	CSideDownwood* sidewood = new CSideDownwood(sidewoodModel,
	//		CVector(0.0f, 15.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f)
	//		, 0.0f);*/
	//	//AddTask(sidewood);
	//	mTime = 0;
	//	CModel* sidewoodModel = CResourceManager::Get<CModel>("SideDownwood");
	//	CSideDownwood* sidewood = new CSideDownwood(sidewoodModel,
	//		CVector(0.0f, 15.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f)
	//		, 0.0f);
	//}

	////重力加算
	//mMoveSpeed.Y(mMoveSpeed.Y() - 480.0f * Time::DeltaTime());

	//Position(Position() + mMoveSpeed * Time::DeltaTime());

	//if (mIsGrounded == false)
	//{
	//	mKillCount--;
	//}

	////Rotate(0.0f, mRotateSpeedY, 0.0f);

	///*mElapsedTime += 1.0f / 60.0f;
	//if (mElapsedTime >= mMoveTime)
	//{
	//	mElapsedTime -= mMoveTime;
	//}*/

	if (mRotateCount < 3)
	{
		if (mKillCount <= 0) {
			randmodelspeedY = Math::Rand(-2.0f, 2.0f);
			while (randmodelspeedY < 0.5f && randmodelspeedY > -0.5f)
			{
				randmodelspeedY = Math::Rand(-2.0f, 2.0f);
			}
			Position(CVector(0.0f, 60.0f, -30.0f));
			/*mMoveSpeed.Y(0.0f);
			mMoveSpeed.X(10.0f);
			mMoveSpeed.Z(0.0f);*/
			mKillCount = 10;
			mRotateCount++;
		}
	}

	if (CPlayer::mResetCount == true)
	{
		Position(mDefaultPos);
		mRotateCount = 0;
		mKillCount = 10;
	}

	//mIsGrounded = false;
}

void CSideDownwood::Collision(CCollider* self, CCollider* other, const CHitInfo& hit)
{
	if (self == mpColliderSphere)
	{
		if (other->Layer() == ELayer::eField)
		{
			mKillCount--;
		}
	}
}

void CSideDownwood::Render()
{
	mpModel->Render(Matrix());
}



/*CVector normal = hit.adjust.Normalized();
		CVector gurabiteli = CVector::down;
		float dot = CVector::Dot(gurabiteli, normal);*/