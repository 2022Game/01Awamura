#include "CIceField.h"
#include "Maths.h"
#include "CCollider.h"

CIceField::CIceField(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eIceField, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
}

CIceField::~CIceField()
{
	SAFE_DELETE(mpColliderMesh);
}

void CIceField::Update()
{
	float per = mElapsedTime / mMoveTime;
	Position(mDefaultPos + mMoveVec * sinf(M_PI * 2.0f * per));

	mElapsedTime += 1.0f / 60.0f;
	if (mElapsedTime >= mMoveTime)
	{
		mElapsedTime -= mMoveTime;
	}
}

void CIceField::Render()
{
	mpModel->SetColor(mColor);
	mpModel->Render(Matrix());
}