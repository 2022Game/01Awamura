#include "CStorn.h"
#include "Maths.h"
#include "CCollider.h"

#define ROTATE_Y -0.1f

CStorn::CStorn(CModel* model, const CVector& pos, const CVector& scale, float rotateSpeedY)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
	, mRotateSpeedY(rotateSpeedY)
{
	mpColliderSphere = new CColliderSphere(this, ELayer::eStorn, 1.0f, false,1.0f);
	Position(mDefaultPos);
	Scale(scale);

	mpColliderSphere->SetCollisionLayers({ ELayer::eField,ELayer::eClearObject,ELayer::eObject,ELayer::eWarpObject,ELayer::eSlopeField,ELayer::ePlayer});
}

CStorn::~CStorn()
{
	SAFE_DELETE(mpColliderSphere);
}

void CStorn::Update()
{
	/*float per = mElapsedTime / mMoveTime;*/
	//ˆÚ“®
	mMoveSpeed = CVector(0.0f, -0.2f, 0.0f);

	Position(Position() + mMoveSpeed);

	//Rotate(0.0f, mRotateSpeedY, 0.0f);

	/*mElapsedTime += 1.0f / 60.0f;
	if (mElapsedTime >= mMoveTime)
	{
		mElapsedTime -= mMoveTime;
	}*/
}

void CStorn::Collision(CCollider* self, CCollider* other, const CHitInfo& hit)
{
	if (self == mpColliderSphere)
	{
		if (other->Layer() == ELayer::eSlopeField || other->Layer() == ELayer::ePlayer || other->Layer() == ELayer::eField)
		{
			Position(Position() + hit.adjust);
		}
	}
}

void CStorn::Render()
{
	mpModel->Render(Matrix());
}