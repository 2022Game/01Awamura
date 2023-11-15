#include "CWarp.h"
#include "Maths.h"
#include "CCollider.h"

CWarp::CWarp(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eWarpObject, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
}

CWarp::~CWarp()
{
	SAFE_DELETE(mpColliderMesh);
}

void CWarp::Update()
{
	float per = mElapsedTime / mMoveTime;
	Position(mDefaultPos + mMoveVec * sinf(M_PI * 2.0f * per));

	mElapsedTime += 1.0f / 60.0f;
	if (mElapsedTime >= mMoveTime)
	{
		mElapsedTime -= mMoveTime;
	}
}

void CWarp::Render()
{
	mpModel->Render(Matrix());
}