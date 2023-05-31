#include "CColliderMesh2.h"
#include "CCollisionManager.h"

CColliderMesh2::CColliderMesh2()
	: mpColliderTriangles2(nullptr)
	, mTrianglesCount2(0)
{

}

CColliderMesh2::~CColliderMesh2()
{
	if (mpColliderTriangles2 != nullptr)
	{
		//�O�p�R���C�_�z��̍폜
		delete[]mpColliderTriangles2;
	}
}

//�D��x�̕ύX
void CColliderMesh2::ChangePriority()
{
	for (int i = 0; i < mTrianglesCount2; i++)
	{
		//�O�p�R���C�_�̐ݒ�
		mpColliderTriangles2[i].ChangePriority();
	}
}

//Set�i�e�A�e�s��A���f���j
//���f������O�p�R���C�_�̐���
void CColliderMesh2::Set(CCharacter3* parent, CMatrix* matrix, CModel* model)
{
	//���f���̎O�p�|���S���ŎO�p�R���C�_�̔z��쐬
	mTrianglesCount2 = model->Triangles().size();
	mpColliderTriangles2 = new CColliderTriangle2[mTrianglesCount2];
	for (int i = 0; i < mTrianglesCount2; i++)
	{
		//�O�p�R���C�_�̐ݒ�
		mpColliderTriangles2[i].Set(parent, matrix
			, model->Triangles()[i].V0()
			, model->Triangles()[i].V1()
			, model->Triangles()[i].V2());
		mpColliderTriangles2[i].ChangePriority();
	}
}