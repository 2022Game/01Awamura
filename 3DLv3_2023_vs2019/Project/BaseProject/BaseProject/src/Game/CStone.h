#pragma once
#include "CRideableObject.h"
#include "CModel.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CColliderSphere.h"
#include "System.h"
#include "CMaterial.h"

class CStone : public CRideableObject
{
public:
	CStone(CModel* model, const CVector& pos, const CVector& scale, float rotateSpeedY);
	~CStone();

	void Update();
	void Render();

	/// <summary>
	/// �Փˏ���
	/// </summary>
	/// <param name="self">�Փ˂������g�̃R���C�_�[</param>
	/// <param name="other">�Փ˂�������̃R���C�_�[</param>
	/// <param name="hit">�Փ˂������̏��</param>
	void Collision(CCollider* self, CCollider* other, const CHitInfo& hit) override;

private:
	void SetClearColor(float r, float g, float b, float a);
	/// <summary>
	/// ��ʂ̃N���A�J���[��ݒ�iCColor�j
	/// </summary>
	/// <param name="color">�ݒ肷��F</param>
	//void SetClearColor(const CColor& color);
	bool mIsGrounded;
	int randpos;
	float randx;
	bool mhit;
	int mKillCount;
	CModel* mpModel;
	CColliderMesh* mpColliderMesh;
	CColliderSphere* mpColliderSphere;

	CVector mDefaultPos;
	CVector mMoveVec;
	float mElapsedTime;
	float mRotateSpeedY;
	CVector mMove;
	float mMoveTime;
	//CVector mDefaultPos;
	//CVector mMoveVec;
	////���̉�]�̂P���[�v�Ɋ|���鎞��
	//float mRotateTime;
	////���̉�]�p�x(-mRotateAngle�`mRotateAngle�܂ŉ�]�j
	//float mRotateAngle;
	//float mElapsedTime;
	CVector mMoveSpeed;	// �ړ����x
	CVector mMoveDir; // �ړ�����

	//�g�U���̐FRGBA
	float mDiffuse[4];
	//mDiffuse�z��̎擾
	float* Diffuse();
};