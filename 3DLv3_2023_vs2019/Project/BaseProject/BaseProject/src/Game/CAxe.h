#pragma once
#include "CRideableObject.h"
#include "CModel.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CColliderSphere.h"
#include "CColliderLine.h"

class CAxe : public CRideableObject
{
public:
	CAxe(CModel* model, const CVector& pos, const CVector& scale);
	~CAxe();

	void Update();
	void Render();

private:
	CModel* mpModel;
	CColliderMesh* mpColliderMesh;
	CColliderSphere* mpColliderSphere;

	//テストライン
	CColliderLine* mpColliderLine2;
	CColliderLine* mpColliderLine3;
	CColliderLine* mpColliderLine4;
	CColliderLine* mpColliderLine22;
	CColliderLine* mpColliderLine33;
	CColliderLine* mpColliderLine44;

	CVector mDefaultPos;
	CVector mMoveVec;
	float mMoveTime;
	float mElapsedTime;
};