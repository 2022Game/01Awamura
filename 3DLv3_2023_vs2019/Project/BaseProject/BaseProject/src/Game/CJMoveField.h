#pragma once
#include "CRideableObject.h"
#include "CModel.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CColliderSphere.h"
#include "CColliderLine.h"

class CJMoveField : public CRideableObject
{
public:
	CJMoveField(CModel* model, const CVector& pos, const CVector& scale);
	~CJMoveField();

	void Update();
	void Render();

private:
	CModel* mpModel;
	CColliderMesh* mpColliderMesh;
	CColliderSphere* mpColliderSphere;

	CColliderLine* mpColliderLine2;

	CVector mDefaultPos;
	CVector mMoveVec;
	float mMoveTime;
	float mElapsedTime;
};