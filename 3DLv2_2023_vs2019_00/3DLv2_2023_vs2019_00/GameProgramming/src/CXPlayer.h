#ifndef CXPLAYER_H
#define CXPLAYER_H
#include "CXCharacter.h"
#include "Cinput.h"
#include "CCollider.h"

class CXPlayer :public CXCharacter
{
public:
	void Update();
	CXPlayer();
	void Init(CModelX* model);
private:
	//�R���C�_�̐錾
	CCollider mColSphereBody; //��
	CCollider mColSphereHead; //��
	CCollider mColSphereSword; //��
	int AnimaScene; //�A�j���[�V�����ԍ�
	int AttackFrame; //�U�����̃A�j���[�V�����t���[����
	CInput mInput;
};

#endif