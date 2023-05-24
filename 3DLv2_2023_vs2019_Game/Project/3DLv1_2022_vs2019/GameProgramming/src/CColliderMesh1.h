#ifndef CCOLLIDERMESH1_H
#define CCOLLIDERMESH1_H
#include "CModel.h"
#include "CColliderTriangle1.h"
#include "CCollider.h"

/*
���f���f�[�^����O�p�R���C�_�̐���
*/
class CColliderMesh1
{
public:
	void ChangePriority();
	CColliderMesh1();
	~CColliderMesh1();
	//Set�i�e�A�e�s��A���f���j
	//���f������O�p�R���C�_�̐���
	void Set(CCharacter3* parent, CMatrix* matrix, CModel* model);
private:
	//�O�p�R���C�_�̔z�񐶐�
	CColliderTriangle1* mpColliderTriangles1;
	//�O�p�R���C�_�̔z��̗v�f��
	int mTrianglesCount1;
};
#endif