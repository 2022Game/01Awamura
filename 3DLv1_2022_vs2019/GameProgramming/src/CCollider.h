#ifndef CCOLLIDER_H
#define CCOLLIDER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"

/*
�R���C�_�N���X
�Փ˔���f�[�^
*/
class CCollisionManager;
class CCollider : public CTransform ,public CTask{
	friend CCollisionManager;
public:
	//�Փ˔���
	//Collision(�R���C�_�P�A�R���C�_�Q�j
	//retrun:true�i�Փ˂��Ă���jfalse(�Փ˂��Ă��Ȃ��j
	static bool Collision(CCollider* m, CCollider* o);
	//�R���X�g���N�^
	//CCollider(�e�A�e�s��A�ʒu�A���a�j
	CCollider(CCharacter3* parent, CMatrix* matrix,
		const CVector& position, float radius);
	//�e�|�C���^�̎擾
	CCharacter3* Parent();
	//�`��
	void Render();
	~CCollider();
protected:
	CCharacter3* mpParent;//�e
	CMatrix* mpMatrix;//�e�s��
	float mRadius; //���a
};
#endif