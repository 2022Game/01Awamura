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
	mpColliderMesh = new CColliderMesh(this, ELayer::eStorn, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);

	mpColliderMesh->SetCollisionLayers({ ELayer::eField,ELayer::eClearObject,ELayer::eObject,ELayer::eWarpObject,ELayer::eSlopeField,ELayer::ePlayer});
}

CStorn::~CStorn()
{
	SAFE_DELETE(mpColliderMesh);
}

void CStorn::Update()
{
	/*float per = mElapsedTime / mMoveTime;*/
	//�ړ�
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
	if (self == mpColliderMesh)
	{
		if (other->Layer() == ELayer::eSlopeField || other->Layer() == ELayer::ePlayer)
		{
			Position(Position() + hit.adjust);
		}
	}
}

void CStorn::Render()
{
	mpModel->Render(Matrix());
}