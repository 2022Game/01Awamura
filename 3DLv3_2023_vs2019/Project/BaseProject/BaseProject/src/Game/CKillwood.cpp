#include "CKillwood.h"
#include "Maths.h"
#include "CCollider.h"
#include "CPlayer.h"

#define ROTATE_Y -0.1f

#include <stdlib.h>

#include "time.h"

bool CKillwood::mResetKillwood = false;

CKillwood::CKillwood(CModel* model, const CVector& pos, const CVector& scale, float rotateSpeedY)
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
	mpColliderMesh = new CColliderMesh(this, ELayer::eObject, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);

	//mpColliderSphere->SetCollisionLayers({ ELayer::eField,ELayer::eClearObject,ELayer::eObject,ELayer::eWarpObject,ELayer::eSlopeField,ELayer::ePlayer,ELayer::eKillwood });
}

CKillwood::~CKillwood()
{
	SAFE_DELETE(mpColliderMesh);
}

void CKillwood::Update()
{
	///*float per = mElapsedTime / mMoveTime;*/
	////�ړ�

	//�ړ������ɉ���
	/*CVector moveSpeedXZ = mMoveSpeed;
	moveSpeedXZ.Y(-1.0f);
	moveSpeedXZ += mMoveDir * 60.0f * Time::DeltaTime();*/
	////�ړ����x���ő�l�ɃN�����v
	//static const float maxSpeed = 60.0f;
	//if (moveSpeedXZ.Length() >= maxSpeed)
	//{
	//	moveSpeedXZ = moveSpeedXZ.Normalized() * maxSpeed;
	//}
	/*mMoveSpeed.X(randx);
	mMoveSpeed.Z(moveSpeedXZ.Z());*/

	////�ړ����x�ɍ��킹�Ċ����]������
	Rotate(0.0f, 1.0f, 0.0f);
	Rotate(0.0f, 1.0f, 0.0f);

	//�d�͉��Z
	mMoveSpeed.Y(-10.0f);

	Position(Position() + mMoveSpeed * Time::DeltaTime());

	if (CPlayer::mResetCount == true)
	{
		Position(0.0f,0.0f,-30.0f);
		//mResetKillwood = true;
	}

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

void CKillwood::Collision(CCollider* self, CCollider* other, const CHitInfo& hit)
{
}

void CKillwood::Render()
{
	mpModel->Render(Matrix());
}



/*CVector normal = hit.adjust.Normalized();
		CVector gurabiteli = CVector::down;
		float dot = CVector::Dot(gurabiteli, normal);*/