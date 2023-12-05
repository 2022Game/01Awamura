#include "CSidewood.h"
#include "Maths.h"
#include "CCollider.h"

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
	, randpos(0)
	, randx(0)
{
	mKillCount = 600;
	//Math::Rand(0, 5);
	mpColliderMesh = new CColliderMesh(this, ELayer::eBadObject, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
	randpos = Math::Rand(-2.0f, 2.0f);
	while (randpos == 0.5f < 0.0f && randpos == -0.5f > 0.0f)
	{
		randpos = Math::Rand(-2.0f, 2.0f);
	}
	//mpColliderSphere->SetCollisionLayers({ ELayer::eField,ELayer::eClearObject,ELayer::eObject,ELayer::eWarpObject,ELayer::eSlopeField,ELayer::ePlayer,ELayer::eSidewood });
}

CSidewood::~CSidewood()
{
	SAFE_DELETE(mpColliderMesh);
}

void CSidewood::Update()
{
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

	////移動速度に合わせて岩を回転させる
	Rotate(0.0f,randpos, 0.0f);

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
}

void CSidewood::Render()
{
	mpModel->Render(Matrix());
}



/*CVector normal = hit.adjust.Normalized();
		CVector gurabiteli = CVector::down;
		float dot = CVector::Dot(gurabiteli, normal);*/