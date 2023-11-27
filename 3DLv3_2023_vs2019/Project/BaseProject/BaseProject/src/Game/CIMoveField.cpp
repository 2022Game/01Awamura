#include "CIMoveField.h"
#include "Maths.h"
#include "CCollider.h"

CIMoveField::CIMoveField(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
}

CIMoveField::~CIMoveField()
{
	SAFE_DELETE(mpColliderMesh);
}

void CIMoveField::Update()
{
	float per = mElapsedTime / mMoveTime;
	Position(mDefaultPos + mMoveVec * sinf(M_PI * 2.0f * per));

	mElapsedTime += 1.0f / 60.0f;
	if (mElapsedTime >= mMoveTime)
	{
		mElapsedTime -= mMoveTime;
	}
}

void CIMoveField::Render()
{
	mpModel->Render(Matrix());
}