#include "CSidewood.h"
#include "Maths.h"
#include "CCollider.h"
#include "CCleardelta.h"
#include "CPlayer.h"

#define ROTATE_Y -0.1f

#include <stdlib.h>

#include "time.h"

CSidewood::CSidewood(CModel* model, const CVector& pos, const CVector& scale, float rotateSpeedY)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
	, mRotateSpeedY(rotateSpeedY)
	, mMoveDir(0.0f, 0.0f, 0.0f)
	, mMoveSpeed(0.0f, 0.0f, 0.0f)
	, mKillCount(0)
	, randmodelspeedY(0.0f)
	, randx(0)
	,Time(0)
	,mTime(0)
{
	mIsMove = false;
	mKillCount = 600;
	//Math::Rand(0, 5);
	mpColliderSphere = new CColliderSphere(this, ELayer::eMove, 2.0f, false, 1.0f);
	mpColliderMesh = new CColliderMesh(this, ELayer::eMoveObject, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
	randmodelspeedY = Math::Rand(-1.0f, 1.0f);
	while (randmodelspeedY < 0.5f && randmodelspeedY > -0.5f)
	{
		randmodelspeedY = Math::Rand(-1.0f, 1.0f);
	}
	mpColliderSphere->SetCollisionLayers({ ELayer::eMove});
}

CSidewood::~CSidewood()
{
	SAFE_DELETE(mpColliderMesh);
	SAFE_DELETE(mpColliderSphere);
}

void CSidewood::Update()
{
	////èdóÕâ¡éZ
	//mMoveSpeed.Y(-10.0f);

	//Position(Position() + mMoveSpeed * Time::DeltaTime());
	/*Time++;
	if (Time == 1200)
	{
		mTime++;
		Time = 0;
	}*/
	///*float per = mElapsedTime / mMoveTime;*/
	////à⁄ìÆ

	////à⁄ìÆï˚å¸Ç…â¡ë¨
	//CVector moveSpeedXZ = mMoveSpeed;
	//moveSpeedXZ.Y(0.0f);
	//moveSpeedXZ += mMoveDir * 60.0f * Time::DeltaTime();
	////à⁄ìÆë¨ìxÇç≈ëÂílÇ…ÉNÉâÉìÉv
	//static const float maxSpeed = 60.0f;
	//if (moveSpeedXZ.Length() >= maxSpeed)
	//{
	//	moveSpeedXZ = moveSpeedXZ.Normalized() * maxSpeed;
	//}
	//mMoveSpeed.X(randx);
	//mMoveSpeed.Z(moveSpeedXZ.Z());

	//âÒì]é¸âÒë¨ìx
	Rotate(0.0f,randmodelspeedY, 0.0f);

	if (mIsMove == true)
	{
		if (CCleardelta::mMoveswitch == false)
		{
			//èdóÕâ¡éZ
			mMoveSpeed.Y(-10.0f);

			Position(Position() + mMoveSpeed * Time::DeltaTime());
		}
	}

	if (CPlayer::mResetCount == true)
	{
		//mMoveSpeed.Y(0.0f);
		Position(mDefaultPos);
		mIsMove = false;
	}

	//ì|ñÿÇÃÉÇÉfÉãì«Ç›çûÇ›
	
	//if (mTime == 1 && Time == 0)
	//{
	//	/*CModel* sidewoodModel = CResourceManager::Get<CModel>("Sidewood");
	//	CSidewood* sidewood = new CSidewood(sidewoodModel,
	//		CVector(0.0f, 15.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f)
	//		, 0.0f);*/
	//	//AddTask(sidewood);
	//	mTime = 0;
	//	CModel* sidewoodModel = CResourceManager::Get<CModel>("Sidewood");
	//	CSidewood* sidewood = new CSidewood(sidewoodModel,
	//		CVector(0.0f, 15.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f)
	//		, 0.0f);
	//}

	////èdóÕâ¡éZ
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

	///*if (mKillCount <= 0) {
	//	randpos = Math::Rand(-100, 100);
	//	randx = Math::Rand(-50, 50);
	//	Position(CVector(randpos, 120.0f, -250.0f));
	//	moveSpeedXZ.Y(0.0f);
	//	mMoveSpeed.Y(0.0f);
	//	mMoveSpeed.X(10.0f);
	//	mMoveSpeed.Z(0.0f);
	//	mKillCount = 30;
	//}*/

	//mIsGrounded = false;
}

void CSidewood::Collision(CCollider* self, CCollider* other, const CHitInfo& hit)
{
	if (self == mpColliderSphere)
	{
		if (other->Layer() == ELayer::eMove)
		{
			mIsMove = true;
		}
	}
}

void CSidewood::Render()
{
	mpModel->Render(Matrix());
}



/*CVector normal = hit.adjust.Normalized();
		CVector gurabiteli = CVector::down;
		float dot = CVector::Dot(gurabiteli, normal);*/