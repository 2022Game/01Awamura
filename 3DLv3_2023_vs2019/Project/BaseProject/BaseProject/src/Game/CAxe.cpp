#include "CAxe.h"
#include "Maths.h"
#include "CCollider.h"

CAxe::CAxe(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
{
	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpModel);
	//mpColliderSphere = new CColliderSphere(this, ELayer::eBigBadObject, 1.0f)0.0f, -190.0f, 0.0f);
	mpColliderLine2 = new CColliderLine(
		this, ELayer::eBigBadObject,
		CVector(-10.0f, -35.0f, 0.0f),
		CVector(10.0f, -35.0f, 0.0f)
	);
	Position(mDefaultPos);
	Scale(scale);
}

CAxe::~CAxe()
{
	if (mpColliderMesh != nullptr)
	{
		delete mpColliderMesh;
		mpColliderMesh = nullptr;
	}
}

void CAxe::Update()
{
	float per = mElapsedTime / mMoveTime;
	Position(mDefaultPos + mMoveVec * sinf(M_PI * 2.0f * per));

	mElapsedTime += 1.0f / 60.0f;
	if (mElapsedTime >= mMoveTime)
	{
		mElapsedTime -= mMoveTime;
	}
}

void CAxe::Render()
{
	mpModel->Render(Matrix());
}