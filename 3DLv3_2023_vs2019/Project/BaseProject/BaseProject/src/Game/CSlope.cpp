#include "CSlope.h"
#include "Maths.h"
#include "CCollider.h"

CSlope::CSlope(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eSlopeField, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
	SetColor(CColor(1.0f, 0.0f, 1.0f, 1.0f));
	SetAlpha(0.1f);
}

CSlope::~CSlope()
{
	SAFE_DELETE(mpColliderMesh);
}

void CSlope::Update()
{
	float per = mElapsedTime / mMoveTime;
	Position(mDefaultPos + mMoveVec * sinf(M_PI * 2.0f * per));

	mElapsedTime += 1.0f / 60.0f;
	if (mElapsedTime >= mMoveTime)
	{
		mElapsedTime -= mMoveTime;
	}
}

void CSlope::Render()
{
	mpModel->Render(Matrix());
}