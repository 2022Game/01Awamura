#ifndef CCOLLIDERMESH_H
#define CCOLLIDERMESH_H
#include "CModel.h"
#include "CColliderTriangle.h"
#include "CCollider.h"

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
	void Set(CCharacter3* parent, const CMatrix* matrix, CModel* model);

	//�R���C�_�̃��C���[���擾
	CCollider::ELayer Layer() const;
	void Layer(CCollider::ELayer layer);
private:
	//�R���C�_�̃��C���[
	CCollider::ELayer mLayer;
	//�O�p�R���C�_�̔z�񐶐�
	CColliderTriangle* mpColliderTriangles;
	//�O�p�R���C�_�̔z��̗v�f��
	int mTrianglesCount;
};
#endif