#pragma once
//�L�����N�^�N���X�̃C���N���[�h
#include "CXCharacter.h"
#include "CColliderLine.h"
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
	//�N���オ��
	void UpdateUp();

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

private:
	// �A�j���[�V�����̎��
	enum class EAnimType
	{
		None = -1,

		eTPose,		// T�|�[�Y
		eIdle,		// �ҋ@
		eWalk,		// ���s
		eAttack,	// �U��
		eJumpStart,	// �W�����v�J�n
		eJump,		// �W�����v��
		eJumpEnd,	// �W�����v�I��
		eClear, //�N���A

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
		eUp, //�N���オ��
	};
	EState mState;	// �v���C���[�̏��

	CVector mMoveSpeed;	// �ړ����x
	bool mIsGrounded;	// �ڒn���Ă��邩�ǂ���

	CColliderLine* mpColliderLine;
	CColliderLine* mpColliderLineBody;
	CColliderLine* mpColliderLineHead;
	CColliderLine* mpColliderLineLeg;
	CTransform* mpRideObject;
	CVector mStartPos;
};
