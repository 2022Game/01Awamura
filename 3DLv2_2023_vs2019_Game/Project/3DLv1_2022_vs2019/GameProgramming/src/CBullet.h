#ifndef CBULLET_H
#define CBULLET_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"
//�O�p�`�N���X�̃C���N���[�h
#include "CTriangle.h"
//�R���R��
#include "CCollider.h"

/*
�e�N���X
�O�p�`���΂�
*/
class CBullet :public CCharacter3 {
public:
	//�Փˏ���
	//Collision(�R���C�_�P�A�R���C�_�Q�j
	void Collision(CCollider* m, CCollider* o);
	void Collision();
	CBullet();
	//���Ɖ��s���̐ݒ�
	//Set�i���A���s�j
	void Set(float w, float d);
	//�X�V
	void Update();
	//�`��
	void Render();
private:
	//�O�p�`
	CTriangle mT;
	//��������
	int mLife;
	//�R���C��
	CCollider mCollider;
};

#endif