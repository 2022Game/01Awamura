#ifndef CCOLLIDERMESH_H
#define CCOLLIDERMESH_H
#include "CModel.h"
#include "CColliderTriangle.h"

/*
���f���f�[�^����O�p�R���C�_�̐���
*/
class CColliderMesh
{
public:
	void ChangePriority();
	CColliderMesh();
	~CColliderMesh();
	//Set�i�e�A�e�s��A���f���j
	//���f������O�p�R���C�_�̐���
	void Set(CCharacter3* parent, CMatrix* matrix, CModel* model,CModel* position);
private:
	//�O�p�R���C�_�̔z�񐶐�
	CColliderTriangle* mpColliderTriangles;
};
#endif