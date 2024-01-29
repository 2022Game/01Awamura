#pragma once
#include "CRideableObject.h"
#include "CModel.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CColliderSphere.h"

class CSideDownwood : public CRideableObject
{
public:
	CSideDownwood(CModel* model, const CVector& pos, const CVector& scale, float rotateSpeedY);
	~CSideDownwood();

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
	int mRotateCount;
	int mTime;
	int Time;
	bool mIsGrounded;
	float randmodelspeedY;
	float mspeedYBOX;
	float randspeedY;
	int randx;
	int mKillCount;
	CModel* mpModel;
	CColliderMesh* mpColliderMesh;
	CColliderSphere* mpColliderSphere;

	CVector mDefaultPos;
	CVector mMoveVec;
	float mElapsedTime;
	float mRotateSpeedY;
	float mRotateSpeedX;
	CVector mMove;
	//float mMoveTime;
	//CVector mDefaultPos;
	//CVector mMoveVec;
	////���̉�]�̂P���[�v�Ɋ|���鎞��
	//float mRotateTime;
	////���̉�]�p�x(-mRotateAngle�`mRotateAngle�܂ŉ�]�j
	//float mRotateAngle;
	//float mElapsedTime;
	CVector mMoveSpeed;	// �ړ����x
	CVector mMoveDir; // �ړ�����
	//�쐬�����^�X�N��ǉ�
	void AddTask(CTask* task);
};