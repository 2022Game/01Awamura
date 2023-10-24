#include "CObstaclesManager.h"
#include "Maths.h"

CObstaclesManager::CObstaclesManager(CModel* model, const CVector& pos, const CVector& scale, const CVector& move, float moveTime)
	: mpModel(model)
	, mDefaultPos(pos)
	, mMoveVec(move)
	, mMoveTime(moveTime)
	, mElapsedTime(0.0f)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel);

	Position(mDefaultPos);
	Scale(scale);
}

CObstaclesManager::~CObstaclesManager()
{
	if (mpColliderMesh != nullptr)
	{
		delete mpColliderMesh;
		mpColliderMesh = nullptr;
	}
}

void CObstaclesManager::Update()
{
	float per = mElapsedTime / mMoveTime;
	Position(mDefaultPos + mMoveVec * sinf(M_PI * 2.0f * per));

	mElapsedTime += 1.0f / 60.0f;
	if (mElapsedTime >= mMoveTime)
	{
		mElapsedTime -= mMoveTime;
	}
}

void CObstaclesManager::Render()
{
	mpModel->Render(Matrix());
}