#include "CJMoveField.h"
#include "Maths.h"
#include "CCollider.h"

CJMoveField::CJMoveField(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
}

CJMoveField::~CJMoveField()
{
	SAFE_DELETE(mpColliderMesh);
}

void CJMoveField::Update()
{
	float per = mElapsedTime / mMoveTime;
	Position(mDefaultPos + mMoveVec * sinf(M_PI * 2.0f * per));

	mElapsedTime += 1.0f / 60.0f;
	if (mElapsedTime >= mMoveTime)
	{
		mElapsedTime -= mMoveTime;
	}
}

void CJMoveField::Render()
{
	mpModel->Render(Matrix());
}