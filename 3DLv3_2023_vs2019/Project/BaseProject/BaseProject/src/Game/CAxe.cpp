#include "CAxe.h"
#include "Maths.h"
#include "CCollider.h"

CAxe::CAxe(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
{
	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpModel);
	//mpColliderSphere->Position(0.0f, -30.0f, 0.0f);
	mpColliderSphere = new CColliderSphere
	(
		this, 
		ELayer::eBigBadObject, 
		10.0f
	);
	mpColliderSphere->Position(0.0f, -28.0f, 0.0f);
	//mpColliderSphere->Position(1.0f, 1.0f, 0.25f);
	mpColliderSphere->SetCollisionTags({ ETag::eEnemy });
	mpColliderLine2 = new CColliderLine(
		this, ELayer::eBadObject,
		CVector(-10.0f, -36.0f, 5.0f),
		CVector(10.0f, -36.0f, 5.0f)
	);
	mpColliderLine2 = new CColliderLine(
		this, ELayer::eBigBadObject,
		CVector(-10.0f, -40.0f, 0.0f),
		CVector(10.0f, -40.0f, 0.0f)
	);
	mpColliderLine2 = new CColliderLine(
		this, ELayer::eBadObject,
		CVector(0.0f, -36.0f, 5.0f),
		CVector(0.0f, 36.0f, 5.0f)
	);
	Position(mDefaultPos);
	Scale(scale);
}

CAxe::~CAxe()
{
	/*if (mpColliderMesh != nullptr)
	{
		delete mpColliderMesh;
		mpColliderMesh = nullptr;
	}*/
	if (mpColliderLine2 != nullptr)
	{
		delete mpColliderLine2;
		mpColliderLine2 = nullptr;
	}
	if (mpColliderSphere != nullptr)
	{
		delete mpColliderSphere;
		mpColliderSphere = nullptr;
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