#ifndef CASoccer_H
#define CASoccer_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"
#include "CCharacter.h"
//�R���R���̃C���N���[�h
#include "CCollider.h"

/*
�G�l�~�[�N���X
�L�����N�^�N���X���p��
*/
class CASoccer : public CCharacter3 {
private:
	//�R���C�_
	//CColliderMesh mColliderMesh;
	CCollider mCollider;
	CVector mLastPos;
	int rarand;
public:
	int hdhd;
	//�Փˏ���
	//Collision(�R���C�_�P�A�R���C�_�Q�j
	void Collision(CCollider* m, CCollider* o);
	void Collision();
	//�R���X�g���N�^
	//CEnemy(���f��,�ʒu,��],�g�k�j
	CASoccer(CModel* model, const CVector& position,
		const CVector& rotation, const CVector& scale);
	//�X�V����
	void Update();
};
#endif