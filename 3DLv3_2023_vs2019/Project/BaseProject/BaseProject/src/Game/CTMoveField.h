#pragma once
#include "CRideableObject.h"
#include "CModel.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CColliderSphere.h"
#include "CColliderLine.h"

class CTMoveField : public CRideableObject
{
public:
	CTMoveField(CModel* model, const CVector& pos, const CVector& scale, float rotateSpeedY);
	~CTMoveField();

	void Update();
	void Render();

private:
	float randmodelspeedY;
	float randmodelspeedY2;
	CModel* mpModel;
	CColliderMesh* mpColliderMesh;
	CColliderSphere* mpColliderSphere;

	CColliderLine* mpColliderLine2;

	CVector mDefaultPos;
	CVector mMoveVec;
	float mMoveTime;
	float mElapsedTime;
	float mRotateSpeedY;
};