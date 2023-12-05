#pragma once
#include "CRideableObject.h"
#include "CModel.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CColliderSphere.h"
#include "CColliderLine.h"
#include "System.h"

class CAxe : public CRideableObject
{
public:
	CAxe(CModel* model, const CVector& pos, const CVector& scale
	,float rotateTime,float rotateAngle);
	~CAxe();

	void Update();
	void Render();

private:
	void SetClearColor(float r, float g, float b, float a);
	/// <summary>
	/// ��ʂ̃N���A�J���[��ݒ�iCColor�j
	/// </summary>
	/// <param name="color">�ݒ肷��F</param>
	//void SetClearColor(const CColor& color);
	CModel* mpModel;
	CColliderMesh* mpColliderMesh;
	CColliderSphere* mpColliderSphere;

	//�e�X�g���C��
	CColliderLine* mpColliderLine2;
	CColliderLine* mpColliderLine3;
	CColliderLine* mpColliderLine4;
	CColliderLine* mpColliderLine22;
	CColliderLine* mpColliderLine33;
	CColliderLine* mpColliderLine44;

	CVector mDefaultPos;
	CVector mMoveVec;
	//���̉�]�̂P���[�v�Ɋ|���鎞��
	float mRotateTime;
	//���̉�]�p�x(-mRotateAngle�`mRotateAngle�܂ŉ�]�j
	float mRotateAngle;
	float mElapsedTime;
};