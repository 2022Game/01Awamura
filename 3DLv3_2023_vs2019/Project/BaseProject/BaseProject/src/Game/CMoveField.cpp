#include "CMoveField.h"
#include "Maths.h"
#include "CCollider.h"

CMoveField::CMoveField(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
}

CMoveField::~CMoveField()
{
	SAFE_DELETE(mpColliderMesh);
}

void CMoveField::Update()
{
	float per = mElapsedTime / mMoveTime;
	Position(mDefaultPos + mMoveVec * sinf(M_PI * 2.0f * per));

	mElapsedTime += 1.0f / 60.0f;
	if (mElapsedTime >= mMoveTime)
	{
		mElapsedTime -= mMoveTime;
	}
}

void CMoveField::Render()
{
	mpModel->Render(Matrix());
}