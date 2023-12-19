#include "CTransparentField.h"
#include "Maths.h"
#include "CCollider.h"

CTransparentField::CTransparentField(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eDead, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);

	SetColor(CColor(1.0f, 0.0f, 1.0f, 0.0f));
}

CTransparentField::~CTransparentField()
{
	SAFE_DELETE(mpColliderMesh);
}

void CTransparentField::Update()
{
	float per = mElapsedTime / mMoveTime;
	Position(mDefaultPos + mMoveVec * sinf(M_PI * 2.0f * per));

	mElapsedTime += 1.0f / 60.0f;
	if (mElapsedTime >= mMoveTime)
	{
		mElapsedTime -= mMoveTime;
	}
}

void CTransparentField::Render()
{
	mpModel->SetColor(mColor);
	mpModel->Render(Matrix());
}