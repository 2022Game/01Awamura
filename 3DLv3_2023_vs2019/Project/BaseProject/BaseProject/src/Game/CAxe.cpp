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
	//float r = 1.0f;
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
	SAFE_DELETE(mpColliderSphere);
}

void CAxe::SetClearColor(float r, float g, float b, float a)
{
	r = 1.0f;
	g = 0.5f;
	b = 0.5f;
	a = 0.1f;
}

void CAxe::Update()
{
	SetClearColor(1.0f,1.0f,1.0f,0.1f);
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
