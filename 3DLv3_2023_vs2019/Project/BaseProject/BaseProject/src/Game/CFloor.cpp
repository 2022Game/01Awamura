#include "CFloor.h"
#include "Maths.h"
#include "CCollider.h"

CFloor::CFloor(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
}

CFloor::~CFloor()
{
	SAFE_DELETE(mpColliderMesh);
}

void CFloor::Update()
{
	float per = mElapsedTime / mMoveTime;
	Position(mDefaultPos + mMoveVec * sinf(M_PI * 2.0f * per));

	mElapsedTime += 1.0f / 60.0f;
	if (mElapsedTime >= mMoveTime)
	{
		mElapsedTime -= mMoveTime;
	}
}

void CFloor::Render()
{
	mpModel->SetColor(mColor);
	mpModel->Render(Matrix());
}