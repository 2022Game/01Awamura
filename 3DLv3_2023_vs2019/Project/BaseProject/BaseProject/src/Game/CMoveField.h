#pragma once
#include "CRideableObject.h"
#include "CModel.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CColliderSphere.h"
#include "CColliderLine.h"

class CMoveField : public CRideableObject
{
public:
	CMoveField(CModel* model, const CVector& pos, const CVector& scale, float rotateSpeedY);
	~CMoveField();

	void Update();
	void Render();

private:
	int mStageNo;
	float randmodelspeedY;
	float randmodelspeedY2;
	float randmodelspeedYNo6;
	CModel* mpModel;
	CColliderMesh* mpColliderMesh;
	CColliderSphere* mpColliderSphere;

	CColliderLine* mpColliderLine2;

	CVector mDefaultPos;
	CVector mMoveVec;

	float mRotateSpeedY;
	CVector mMoveSpeed;	// ˆÚ“®‘¬“x
};