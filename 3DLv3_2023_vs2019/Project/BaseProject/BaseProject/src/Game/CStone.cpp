#include "CStone.h"
#include "Maths.h"
#include "CCollider.h"
#include "CColor.h"
#include <glut.h>

#define ROTATE_Y -0.1f

#include <stdlib.h>

#include "time.h"

CStone::CStone(CModel* model, const CVector& pos, const CVector& scale, float rotateSpeedY)
	: CObjectBase(ETag::eStone,ETaskPriority::eDefault,0,ETaskPauseType::eGame)
	,mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
	, mRotateSpeedY(rotateSpeedY)
	, mMoveDir(0.0f, 0.0f, 0.0f)
	,mMoveSpeed(0.0f,0.0f,0.0f)
	,mKillCount(0)
	,randpos(0)
	,randx(0)
{
	SetAlpha(0.1f);
	int size = ARRAY_SIZE(mDiffuse);
	for (int i = 0; i < size; i++)
	{
		mDiffuse[i] = 1.0f;
	}
	mKillCount = 600;
	//Math::Rand(0, 5);
	mpColliderSphere = new CColliderSphere(this, ELayer::eStone, 1.0f, false,100.0f);
	Position(mDefaultPos);
	Scale(scale);
	mhit = false;
	randx = Math::Rand(-50.0f, 50.0f);
	mMoveSpeed.X(randx);

	mpColliderSphere->SetCollisionLayers
	({  ELayer::eField,
		ELayer::eClearObject,
		ELayer::eObject,
		ELayer::eWarpObject,
		ELayer::eSlopeField,
		ELayer::ePlayer,
		ELayer::eStone});
}

CStone::~CStone()
{
	SAFE_DELETE(mpColliderSphere);
}

void CStone::SetClearColor(float r, float g, float b, float a)
{
	/*r = 1.0f;
	g = 0.5f;
	b = 0.5f;
	a = 0.1f;*/
}

//mDiffuse配列の取得
float* CStone::Diffuse()
{
	return mDiffuse;
}

void CStone::Update()
{
	mhit = false;
	mDiffuse[3] = 0.1f;
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	//SetClearColor(1.0f, 1.0f, 1.0f, 1.0f);
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
	mMoveSpeed.Z(moveSpeedXZ.Z());
	//mMoveSpeed.X(moveSpeedXZ.X());

	//移動速度に合わせて岩を回転させる
	CVector side = CVector::Cross(moveSpeedXZ.Normalized(), CVector::up);
	RotateAxis(side, 0.1f * moveSpeedXZ.Length());

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
		randpos = Math::Rand(-80,80);
		randx = Math::Rand(-50.0f, 50.0f);
		Position(CVector(randpos, 120.0f, -250.0f));
		moveSpeedXZ.Y(0.0f);
		mMoveSpeed.Y(0.0f);
		mMoveSpeed.X(randx);
		mMoveSpeed.Z(0.0f);
		mKillCount = 30;
	}

	mIsGrounded = false;
	mIsStone = false;
}

void CStone::Collision(CCollider* self, CCollider* other, const CHitInfo& hit)
{
	if (self == mpColliderSphere)
	{
		if (other->Layer() == ELayer::eStone)
		{
			CVector adjust = hit.adjust;
			adjust.Y(0.0f);
			Position(Position() + hit.adjust * hit.weight);

			//移動方向に押し戻す方向を加算して、移動方向を変更する
			mMoveSpeed += adjust;
		}
		if (other->Layer() == ELayer::eSlopeField|| other->Layer() == ELayer::eField)
		{
			CVector normal = hit.adjust.Normalized();
			CVector gv = CVector::down;
			float dot = CVector::Dot(gv, normal);
			if (dot <= -0.5f)
			{
				Position(Position() + hit.adjust * hit.weight);
				mIsGrounded = true;
				mIsStone = true;
				mKillCount = 30;
				mMoveSpeed.Y(0.0f);
			}
			//法線テスト
			/*if (dot >= -0.2f)
			{
				Position(Position() + hit.adjust * hit.weight);
			}*/

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