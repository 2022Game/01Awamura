#pragma once
#include "CRideableObject.h"
#include "CModel.h"
#include "CColliderMesh.h"

//�����鏰
class CAppearFloor :public CRideableObject
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="pos">�����ʒu</param>
	/// <param name="scale">���̃X�P�[���l</param>
	/// <param name="reactionTag">�G���Ɣ�������I�u�W�F�N�g�̃^�O</param>
	/// <param name="reactionLayer">�G���Ɣ�������R���C�_�[�̃��C���[</param>
	CAppearFloor(const CVector& pos, const CVector& scale,
		ETag reactionTag, ELayer reactionLayer);

	//�f�X�g���N�^
	~CAppearFloor();

	void Collision(CCollider* self, CCollider* other, const CHitInfo& hit)override;

	//�X�V
	void Update() override;
	//�`��
	void Render() override;

private:
	enum class EState
	{
		Idle,//�ҋ@
		Appeared, //����Ă�����
	};
	//��Ԃ�؂�ւ���
	void ChangeState(EState state);
	//�ҋ@��Ԃ̍X�V����
	void UpdateIdle();
	//����Ă����Ԃ̍X�V����
	void UpdateAppeared();

	CModel* mpModel; //�����鏰�̃��f��
	CColliderMesh* mpColliderMesh; //�����鏰�̃R���C�_�[

	EState mState; //���݂̏��
	int mStateStep; //��ԓ��̃X�e�b�v

	ETag mReactionTag; //�G�ꂽ�Ƃ��ɔ�������I�u�W�F�N�g�̃^�O
	ELayer mReactionLayer; //�G�ꂽ�Ƃ��ɔ�������R���C�_�[�̃��C��-

	float mFadeTime; //�t�F�[�h����
	float mWaitTime; //�t�F�[�h��̑ҋ@����
	bool mIsCollision; //�Փ˂��Ă��邩�ǂ���
};