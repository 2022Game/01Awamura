#include "CAxe.h"
#include "Maths.h"
#include "CCollider.h"

CAxe::CAxe(CModel* model, const CVector& pos, const CVector& scale
,float rotateTime,float rotateAngle)
	: mpModel(model)
	, mDefaultPos(pos)
	,mRotateTime(rotateTime)
	,mRotateAngle(rotateAngle)
	, mElapsedTime(0.0f)
{
	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpModel);
	//mpColliderSphere->Position(0.0f, -30.0f, 0.0f);
	mpColliderSphere = new CColliderSphere
	(
		this, 
		ELayer::eBigBadObject, 
		10.0f,
		true
	);
	mpColliderSphere->Position(0.0f, -28.0f, 0.0f);
	//mpColliderSphere->Position(1.0f, 1.0f, 0.25f);
	mpColliderSphere->SetCollisionTags({ ETag::ePlayer });
	/*mpColliderLine2 = new CColliderLine(
		this, ELayer::eBadObject,
		CVector(-10.0f, -36.0f, 5.0f),
		CVector(10.0f, -36.0f, 5.0f)
	);
	mpColliderLine3 = new CColliderLine(
		this, ELayer::eBigBadObject,
		CVector(-10.0f, -40.0f, 0.0f),
		CVector(10.0f, -40.0f, 0.0f)
	);
	mpColliderLine4 = new CColliderLine(
		this, ELayer::eBadObject,
		CVector(0.0f, -36.0f, 5.0f),
		CVector(0.0f, 36.0f, 5.0f)
	);*/
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
	/*SAFE_DELETE(mpColliderLine2);
	SAFE_DELETE(mpColliderLine3);
	SAFE_DELETE(mpColliderLine4);*/
	SAFE_DELETE(mpColliderSphere);
	/*if (mpColliderSphere != nullptr)
	{
		delete mpColliderSphere;
		mpColliderSphere = nullptr;
	}*/
}

void CAxe::Update()
{
	//U‚èqA‰ñ“]‚ÌˆÚ“®
	float per = mElapsedTime / mRotateTime;
	float angle = mRotateAngle * sinf(M_PI * 2.0f * per);
	Rotation(CQuaternion(0.0f, 0.0f, angle));

	mElapsedTime += Time::DeltaTime();
	if (mElapsedTime >= mRotateTime)
	{
		mElapsedTime -= mRotateTime;
	}
}

void CAxe::Render()
{
	mpModel->Render(Matrix());
}