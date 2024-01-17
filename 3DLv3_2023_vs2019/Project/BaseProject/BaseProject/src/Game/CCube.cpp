#include "CCube.h"
#include "Maths.h"
#include "CCollider.h"

CCube::CCube(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eObject, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
	mpColliderMesh->SetCollisionLayers({ ELayer::ePlayer });
}

CCube::~CCube()
{
	SAFE_DELETE(mpColliderMesh);
}

void CCube::Update()
{
	float per = mElapsedTime / mMoveTime;
	Position(mDefaultPos + mMoveVec * sinf(M_PI * 2.0f * per));

	mElapsedTime += 1.0f / 60.0f;
	if (mElapsedTime >= mMoveTime)
	{
		mElapsedTime -= mMoveTime;
	}
}

void CCube::Render()
{
	mpModel->SetColor(mColor);
	mpModel->Render(Matrix());
}