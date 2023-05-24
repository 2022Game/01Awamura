#ifndef CAHamah_H
#define CAHamah_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"
#include "CCharacter.h"
//�R���R���̃C���N���[�h
#include "CCollider.h"
#include "CColliderMesh1.h"
#include "CColliderTriangle.h"
#include "CColliderLine.h"
/*
�G�l�~�[�N���X
�L�����N�^�N���X���p��
*/
class CAHamah : public CCharacter3{
private:
	//�R���C�_
	CCollider mCollider1;
	CCollider mCollider2;
	CCollider mCollider3;
	CColliderMesh1 mColliderMesh2;
public:
	static int hn;
	//�Փˏ���
	//Collision(�R���C�_�P�A�R���C�_�Q�j
	void Collision(CCollider* m, CCollider* o);
	void Collision();
	//�R���X�g���N�^
	//CEnemy(���f��,�ʒu,��],�g�k�j
	CAHamah(CModel* model, const CVector& position,
		const CVector& rotation, const CVector& scale);
	//�X�V����
	void Update();
};
#endif