#pragma once
#include "CRideableObject.h"
#include "CModel.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CColliderSphere.h"
#include "CColliderLine.h"

class CCleardelta : public CRideableObject
{
public:
	CCleardelta(CModel* model, const CVector& pos, const CVector& scale);
	~CCleardelta();

	void Update();
	void Render();

	void Collision(CCollider* self, CCollider* other, const CHitInfo& hit) override;

	static bool mMoveswitch;
private:
	CModel* mpModel;
	CColliderMesh* mpColliderMesh;
	CColliderSphere* mpColliderSphere;

	CColliderLine* mpColliderLine2;

	CVector mDefaultPos;
	CVector mMoveVec;
	float mMoveTime;
	float mElapsedTime;

	float mRotateSpeedY;
	CVector mMove;
	CVector mMoveSpeed;	// ˆÚ“®‘¬“x
	CVector mMoveDir; // ˆÚ“®•ûŒü
};