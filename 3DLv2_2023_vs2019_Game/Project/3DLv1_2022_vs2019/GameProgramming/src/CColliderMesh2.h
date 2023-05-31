#ifndef CCOLLIDERMESH2_H
#define CCOLLIDERMESH2_H
#include "CModel.h"
#include "CColliderTriangle2.h"
#include "CCollider.h"

/*
���f���f�[�^����O�p�R���C�_�̐���
*/
class CColliderMesh2
{
public:
	void ChangePriority();
	CColliderMesh2();
	~CColliderMesh2();
	//Set�i�e�A�e�s��A���f���j
	//���f������O�p�R���C�_�̐���
	void Set(CCharacter3* parent, CMatrix* matrix, CModel* model);
private:
	//�O�p�R���C�_�̔z�񐶐�
	CColliderTriangle2* mpColliderTriangles2;
	//�O�p�R���C�_�̔z��̗v�f��
	int mTrianglesCount2;
};
#endif