#include "CStorn.h"
#include "Maths.h"
#include "CCollider.h"

CStorn::CStorn(CModel* model, const CVector& pos, const CVector& scale,const CVector& move, float moveTime)
	: mpModel(model)
	, mDefaultPos(pos)
	, mMoveVec(move)
	, mMoveTime(moveTime)
	, mElapsedTime(0.0f)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eStorn, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
}

CStorn::~CStorn()
{
	SAFE_DELETE(mpColliderMesh);
}

void CStorn::Update()
{
	/*float per = mElapsedTime / mMoveTime;*/
	Position(mDefaultPos + mMoveVec);

	/*mElapsedTime += 1.0f / 60.0f;
	if (mElapsedTime >= mMoveTime)
	{
		mElapsedTime -= mMoveTime;
	}*/
}

void CStorn::Render()
{
	mpModel->Render(Matrix());
}