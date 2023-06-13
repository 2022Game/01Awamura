#ifndef CACOIN_H
#define CACOIN_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"
//�R���R���̃C���N���[�h
#include "CCollider.h"
#include "CColliderMesh.h"
#include "CColliderTriangle.h"
#include "CColliderLine.h"
/*
�G�l�~�[�N���X
�L�����N�^�N���X���p��
*/
class CACoin : public CCharacter3 {
private:
	//�R���C�_
	CColliderMesh mColliderMesh;
public:
	int SCount;
	int UpCount;
	int SideChengeCount;
	int SideCount;
	//static int mD;
	//�Փˏ���
	//Collision(�R���C�_�P�A�R���C�_�Q�j
	void Collision(CCollider* m, CCollider* o);
	void Collision();
	//�R���X�g���N�^
	//CEnemy(���f��,�ʒu,��],�g�k�j
	CACoin(CModel* model, const CVector& position,
		const CVector& rotation, const CVector& scale);
	//�X�V����
	void Update();
};
#endif