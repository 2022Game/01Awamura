#ifndef CPLAYER_H
#define CPLAYER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"
#include "CCharacter.h"
#include "CInput.h"
#include "CBullet.h"
#include "CColliderLine.h"

/*
�v���C���[�N���X
�L�����N�^�N���X���p��
*/
class CPlayer : public CCharacter3 ,CCharacter
{
private:
	//float mVy;	//Y�����x
	CInput mInput;
	CColliderLine mLine; //�����R���C�_
	CColliderLine mLine2;
	CColliderLine mLine3;
	int ddStage;
	int ccStage;
	//�v���C���[�̃C���X�^���X
	static CPlayer* spInstance;

	//�ڒn���Ă���ړ��I�u�W�F�N�g��Transform
	CTransform* mGroundedMoveObjTf;
	//�ڒn���Ă��邩�ǂ���
	bool mIsGrounded;

	//�X�e�[�W�N���A�p�̃I�u�W�F�N�g�ɐڒn���̏���
	void GroundedClearObj();
	//�X�e�[�W�̕ǐ����p�̃I�u�W�F�N�g�ɐڒn���̏���
	void GroundedGuardObj();
	CVector mLastPos;
public:
	static int CountLine;
	static int CountCraft;
	int mTime;
	int mRestart;
	int randddco;
	int randdd;
	int n;
	int jc;//�W�����v�J�E���g
	int jswitch;
	//�C���X�^���X�̃|�C���^�̎擾
	static CPlayer* Instance();
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);
	void Collision();
	CPlayer();
	//CPlayer(�ʒu�A��]�A�X�P�[���j
	CPlayer(const CVector& pos, const CVector& rot, const CVector& scale);
	void Update();
	//CBullet bullet;
};

#endif