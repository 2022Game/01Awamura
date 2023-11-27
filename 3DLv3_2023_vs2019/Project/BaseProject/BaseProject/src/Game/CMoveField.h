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
	CModel* mpModel;
	CColliderMesh* mpColliderMesh;
	CColliderSphere* mpColliderSphere;

	CColliderLine* mpColliderLine2;

	CVector mDefaultPos;
	CVector mMoveVec;
	//•€‚Ì‰ñ“]‚Ì‚Pƒ‹[ƒv‚ÉŠ|‚©‚éŠÔ
	float mRotateTime;
	float mRotateAngle;
	float mElapsedTime;

	float mRotateSpeedY;
	CVector mMove;
	float mMoveTime;
	//CVector mDefaultPos;
	//CVector mMoveVec;
	////•€‚Ì‰ñ“]‚Ì‚Pƒ‹[ƒv‚ÉŠ|‚©‚éŠÔ
	//float mRotateTime;
	////•€‚Ì‰ñ“]Šp“x(-mRotateAngle`mRotateAngle‚Ü‚Å‰ñ“]j
	//float mRotateAngle;
	//float mElapsedTime;
	CVector mMoveSpeed;	// ˆÚ“®‘¬“x
};