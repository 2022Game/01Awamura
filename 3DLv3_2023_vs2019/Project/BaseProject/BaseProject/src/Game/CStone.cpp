#include "CStone.h"
#include "Maths.h"
#include "CCollider.h"

#define ROTATE_Y -0.1f

#include <stdlib.h>

#include "time.h"

CStone::CStone(CModel* model, const CVector& pos, const CVector& scale, float rotateSpeedY)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
	, mRotateSpeedY(rotateSpeedY)
	, mMoveDir(0.0f, 0.0f, 0.0f)
	,mMoveSpeed(0.0f,0.0f,0.0f)
	,mKillCount(0)
	,randpos(0)
	,randx(0)
{
	mKillCount = 600;
	//Math::Rand(0, 5);
	mpColliderSphere = new CColliderSphere(this, ELayer::eStone, 1.0f, false,100.0f);
	Position(mDefaultPos);
	Scale(scale);

	mpColliderSphere->SetCollisionLayers({ ELayer::eField,ELayer::eClearObject,ELayer::eObject,ELayer::eWarpObject,ELayer::eSlopeField,ELayer::ePlayer,ELayer::eStone});
}

CStone::~CStone()
{
	SAFE_DELETE(mpColliderSphere);
}

void CStone::Update()
{
	/*float per = mElapsedTime / mMoveTime;*/
	//移動

	//移動方向に加速
	CVector moveSpeedXZ = mMoveSpeed;
	moveSpeedXZ.Y(0.0f);
	moveSpeedXZ += mMoveDir * 60.0f * Time::DeltaTime();
	//移動速度を最大値にクランプ
	static const float maxSpeed = 60.0f;
	if (moveSpeedXZ.Length() >= maxSpeed)
	{
		moveSpeedXZ = moveSpeedXZ.Normalized() * maxSpeed;
	}
	mMoveSpeed.X(randx);
	mMoveSpeed.Z(moveSpeedXZ.Z());

	//移動速度に合わせて岩を回転させる
	Rotate(-0.1f * moveSpeedXZ.Length(), 0.0f, 0.0f);

	//重力加算
	mMoveSpeed.Y(mMoveSpeed.Y() - 480.0f * Time::DeltaTime());

	Position(Position() + mMoveSpeed * Time::DeltaTime());

	if (mIsGrounded == false)
	{
		mKillCount--;
	}

	//Rotate(0.0f, mRotateSpeedY, 0.0f);

	/*mElapsedTime += 1.0f / 60.0f;
	if (mElapsedTime >= mMoveTime)
	{
		mElapsedTime -= mMoveTime;
	}*/

	if (mKillCount <= 0) {
		randpos = Math::Rand(-100,100);
		randx = Math::Rand(-50, 50);
		Position(CVector(randpos, 120.0f, -250.0f));
		moveSpeedXZ.Y(0.0f);
		mMoveSpeed.Y(0.0f);
		mMoveSpeed.X(10.0f);
		mMoveSpeed.Z(0.0f);
		mKillCount = 30;
	}

	mIsGrounded = false;
}

void CStone::Collision(CCollider* self, CCollider* other, const CHitInfo& hit)
{
	if (self == mpColliderSphere)
	{
		if (other->Layer() == ELayer::eStone)
		{
			Position(Position() + hit.adjust * hit.weight);
		}
		if (other->Layer() == ELayer::eSlopeField|| other->Layer() == ELayer::eField)
		{
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;
			mKillCount = 30;
			mMoveSpeed.Y(0.0f);

			//押し出される方向から、岩の移動方向を求める
			mMoveDir = hit.adjust;
			mMoveDir.Y(0.0f);
			mMoveDir.Normalize();
		}
	}
}

void CStone::Render()
{
	mpModel->Render(Matrix());
}



/*CVector normal = hit.adjust.Normalized();
		CVector gurabiteli = CVector::down;
		float dot = CVector::Dot(gurabiteli, normal);*/