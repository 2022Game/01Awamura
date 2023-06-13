#ifndef CACOINCREARSTAGE_H
#define CACOINCREARSTAGE_H
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
class CACoinClearStage : public CCharacter3 {
private:
	//�R���C�_
	CColliderMesh mColliderMesh;
public:
	int BackCount;
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
	CACoinClearStage(CModel* model, const CVector& position,
		const CVector& rotation, const CVector& scale);
	//�X�V����
	void Update();
};
#endif