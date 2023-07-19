#ifndef CAWall_H
#define CAWall_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"
#include "CCharacter.h"
//�R���R���̃C���N���[�h
#include "CCollider.h"
#include "CColliderMesh.h"
/*
�G�l�~�[�N���X
�L�����N�^�N���X���p��
*/
class CAWall : public CCharacter3 {
private:
	//�R���C�_
	CColliderMesh mColliderMesh;
	CCollider mCollider;
public:
	//static int hn;
	//�Փˏ���
	//Collision(�R���C�_�P�A�R���C�_�Q�j
	void Collision(CCollider* m, CCollider* o);
	void Collision();
	//�R���X�g���N�^
	//CEnemy(���f��,�ʒu,��],�g�k�j
	CAWall(CModel* model, const CVector& position,
		const CVector& rotation, const CVector& scale);
	//�X�V����
	void Update();
};
#endif