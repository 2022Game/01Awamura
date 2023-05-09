#ifndef CPLAYER_H
#define CPLAYER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"
#include "CInput.h"
#include "CBullet.h"
#include "CColliderLine.h"

/*
�v���C���[�N���X
�L�����N�^�N���X���p��
*/
class CPlayer : public CCharacter3
{
private:
	//float mVy;	//Y�����x
	CInput mInput;
	CColliderLine mLine; //�����R���C�_
	CColliderLine mLine2;
	CColliderLine mLine3;
	//�v���C���[�̃C���X�^���X
	static CPlayer* spInstance;
public:
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