#ifndef CAWood_H
#define CAWood_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"
#include "CCharacter.h"
//�R���R���̃C���N���[�h
#include "CCollider.h"
/*
�G�l�~�[�N���X
�L�����N�^�N���X���p��
*/
class CAWood : public CCharacter3 {
private:
	//�R���C�_
	CCollider mCollider;
	CVector mLastPos;
	CVector mStartPos;
public:
	int ha;
	int rararan;
	//�Փˏ���
	//Collision(�R���C�_�P�A�R���C�_�Q�j
	void Collision(CCollider* m, CCollider* o);
	void Collision();
	//�R���X�g���N�^
	//CEnemy(���f��,�ʒu,��],�g�k�j
	CAWood(CModel* model, const CVector& position,
		const CVector& rotation, const CVector& scale);
	//�X�V����
	void Update();
};
#endif