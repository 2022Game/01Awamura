#include "CClearCube.h"
#include "Maths.h"
#include "CCollider.h"

CClearCube::CClearCube(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpModel, true);

	Position(mDefaultPos);
	Scale(scale);
}

CClearCube::~CClearCube()
{
	if (mpColliderMesh != nullptr)
	{
		delete mpColliderMesh;
		mpColliderMesh = nullptr;
	}
}

void CClearCube::Update()
{
	float per = mElapsedTime / mMoveTime;
	Position(mDefaultPos + mMoveVec * sinf(M_PI * 2.0f * per));

	mElapsedTime += 1.0f / 60.0f;
	if (mElapsedTime >= mMoveTime)
	{
		mElapsedTime -= mMoveTime;
	}
}

void CClearCube::Render()
{
	mpModel->Render(Matrix());
}