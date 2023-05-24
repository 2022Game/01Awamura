#include "CColliderMesh1.h"
#include "CCollisionManager.h"

CColliderMesh1::CColliderMesh1()
	: mpColliderTriangles1(nullptr)
	, mTrianglesCount1(0)
{

}

CColliderMesh1::~CColliderMesh1()
{
	if (mpColliderTriangles1 != nullptr)
	{
		//�O�p�R���C�_�z��̍폜
		delete[]mpColliderTriangles1;
	}
}

//�D��x�̕ύX
void CColliderMesh1::ChangePriority()
{
	for (int i = 0; i < mTrianglesCount1; i++)
	{
		//�O�p�R���C�_�̐ݒ�
		mpColliderTriangles1[i].ChangePriority();
	}
}

//Set�i�e�A�e�s��A���f���j
//���f������O�p�R���C�_�̐���
void CColliderMesh1::Set(CCharacter3* parent, CMatrix* matrix, CModel* model)
{
	//���f���̎O�p�|���S���ŎO�p�R���C�_�̔z��쐬
	mTrianglesCount1 = model->Triangles().size();
	mpColliderTriangles1 = new CColliderTriangle1[mTrianglesCount1];
	for (int i = 0; i < mTrianglesCount1; i++)
	{
		//�O�p�R���C�_�̐ݒ�
		mpColliderTriangles1[i].Set(parent, matrix
			, model->Triangles()[i].V0()
			, model->Triangles()[i].V1()
			, model->Triangles()[i].V2());
		mpColliderTriangles1[i].ChangePriority();
	}
}