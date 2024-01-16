#pragma once
//�L�����N�^�N���X�̃C���N���[�h
#include "CXCharacter.h"
#include "CColliderLine.h"
#include "CColliderSphere.h"
#include "CRideableObject.h"

/*
�v���C���[�N���X
�L�����N�^�N���X���p��
*/
class CPlayer : public CXCharacter
{
public:
	//�C���X�^���X�̃|�C���^�̎擾
	static CPlayer* Instance();

	// �R���X�g���N�^
	CPlayer();
	// �f�X�g���N�^
	~CPlayer();

	//��邱�Ƃ��o����I�u�W�F�N�g���폜���ꂽ���̏���
	void DeleteRideableObject(CTransform* rideObj);

	//�X�e�[�W�J�n���̈ʒu��ݒ�
	void SetStartPosition(const CVector& pos);

	//�������̏��
	void UpdateReady();
	// �ҋ@���
	void UpdateIdle();
	// �U��
	void UpdateAttack();
	// �U���I���҂�
	void UpdateAttackWait();
	// �W�����v�J�n
	void UpdateJumpStart();
	// �W�����v��
	void UpdateJump();
	// �W�����v�I��
	void UpdateJumpEnd();
	//��
	void UpdateJumpN();
	//�N���A
	void UpdateClear();
	//�N���A�I��
	void UpdateClearEnd();
	//�|���
	void UpdateDown();
	//������ѓ|���
	void UpdateBadDown();
	//�N���オ��
	void UpdateUp();
	//���Ⴊ��
	void UpdateSquat();
	//���Ⴊ�݉���
	void UpdateSquatUp();
	//���S
	void UpdateDead();

	// �X�V
	void Update();

	/// <summary>
	/// �Փˏ���
	/// </summary>
	/// <param name="self">�Փ˂������g�̃R���C�_�[</param>
	/// <param name="other">�Փ˂�������̃R���C�_�[</param>
	/// <param name="hit">�Փ˂������̏��</param>
	void Collision(CCollider* self, CCollider* other, const CHitInfo& hit) override;

	// �`��
	void Render();

	static bool mSwitchRObject;
	static bool mSwitchLObject;

	static bool mResetCount;
	static bool mDownSwitch;

private:
	CPlayer* player;
	// �A�j���[�V�����̎��
	enum class EAnimType
	{
		None = -1,

		eIdle,		// �ҋ@
	//	eSuperJump,
		eSlowRun,
		eJumpUp,
		eJumpDown2,
		eJumpDown3,
	//	eRun,
		eJumpN,
		eDown,
		eUp,
		eClear,
		eSquat,
		eSquatUp,

		Num
	};
	// �A�j���[�V�����؂�ւ�
	void ChangeAnimation(EAnimType type);

	// �v���C���[�̃C���X�^���X
	static CPlayer* spInstance;

	// �A�j���[�V�����f�[�^
	struct AnimData
	{
		std::string path;	// �A�j���[�V�����f�[�^�̃p�X
		bool loop;			// ���[�v���邩�ǂ���
		float frameLength;	// �A�j���[�V�����̃t���[����
	};
	// �A�j���[�V�����f�[�^�̃e�[�u��
	static const AnimData ANIM_DATA[];

	// �v���C���[�̏��
	enum class EState
	{
		eReady, //������
		eIdle,		// �ҋ@
		eAttack,	// �U��
		eAttackWait,// �U���I���҂�
		eJumpStart,	// �W�����v�J�n
		eJump,		// �W�����v��
		eJumpEnd,	// �W�����v�I��
		eJumpN, //��
		eClear, //�N���A
		eClearEnd, //�N���A�I��
		eDown, //�|���
		eBadDown, 
		eUp, //�N���オ��
		eSquat, //���Ⴊ��
		eSquatUp, //���Ⴊ��
		eDead, //���S
	};
	//���݂̏�Ԃ�؂�ւ�
	void ChangeState(EState state);

	EState mState;	// �v���C���[�̏��
	int mStateStep; //��ԓ��̃X�e�b�v

	CVector mColliderSpeed;

	CVector mMoveSpeed;	// �ړ����x
	bool mIsGrounded;	// �ڒn���Ă��邩�ǂ���
	bool mCollisionSwitch; //�����蔻��쓮�p
	int mStageNoBox; //�X�e�[�W�i���o�[�ۊǗp

	CColliderLine* mpColliderLine;
	CColliderSphere* mpColliderSphere;
	CColliderLine* mpColliderLineBody;
	CColliderLine* mpColliderLineBody2;
	CColliderLine* mpColliderLineBodyHalf;
	CColliderLine* mpColliderLineBodyHalf2;
	CColliderLine* mpColliderLineHead;
	CColliderLine* mpColliderLineHead2;
	CColliderLine* mpColliderLineLeg;
	CColliderLine* mpColliderLineLeg2;
	CColliderLine* mpColliderLineLegHalf;
	CColliderLine* mpColliderLineLegHalf2;
	CTransform* mpRideObject;
	CVector mStartPos;
	CVector mClearPos;
	int mDowncount;
	CVector mColliderPos;
	CVector mColliderPos2;
	CVector mColliderPos3;
	CVector mColliderPos4;
};
