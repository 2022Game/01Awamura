#ifndef CPLAYER_H
#define CPLAYER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"
#include "CInput.h"
#include "CBullet.h"

/*
�v���C���[�N���X
�L�����N�^�N���X���p��
*/
class CPlayer : public CCharacter3
{
private:
	//float mVy;	//Y�����x
	CInput mInput;
public:
	CPlayer(){}
	//CPlayer(�ʒu�A��]�A�X�P�[���j
	CPlayer(const CVector& pos, const CVector& rot, const CVector& scale);
	void Update();
	//CBullet bullet;
};

#endif