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
	CAxe(CModel* model, const CVector& pos, const CVector& scale
	,float rotateTime,float rotateAngle);
	~CAxe();

	void Update();
	void Render();

private:
	CModel* mpModel;
	CColliderMesh* mpColliderMesh;
	CColliderSphere* mpColliderSphere;

	//ƒeƒXƒgƒ‰ƒCƒ“
	CColliderLine* mpColliderLine2;
	CColliderLine* mpColliderLine3;
	CColliderLine* mpColliderLine4;
	CColliderLine* mpColliderLine22;
	CColliderLine* mpColliderLine33;
	CColliderLine* mpColliderLine44;

	CVector mDefaultPos;
	CVector mMoveVec;
	//•€‚Ì‰ñ“]‚Ì‚Pƒ‹[ƒv‚ÉŠ|‚©‚éŠÔ
	float mRotateTime;
	//•€‚Ì‰ñ“]Šp“x(-mRotateAngle`mRotateAngle‚Ü‚Å‰ñ“]j
	float mRotateAngle;
	float mElapsedTime;
};