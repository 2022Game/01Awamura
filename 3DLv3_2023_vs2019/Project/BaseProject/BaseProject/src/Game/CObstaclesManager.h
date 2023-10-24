#pragma once
#include "CObstaclesObject.h"
#include "CModel.h"
#include "CColliderMesh.h"

class CObstaclesManager : public CObstaclesObject
{
public:
	CObstaclesManager(CModel* model, const CVector& pos, const CVector& scale, const CVector& move, float moveTime);
	~CObstaclesManager();

	void Update();
	void Render();

private:
	CModel* mpModel;
	CColliderMesh* mpColliderMesh;

	CVector mDefaultPos;
	CVector mMoveVec;
	float mMoveTime;
	float mElapsedTime;
};