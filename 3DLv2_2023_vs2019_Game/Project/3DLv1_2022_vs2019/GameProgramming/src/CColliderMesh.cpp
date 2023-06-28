#include "CColliderMesh.h"
#include "CCollisionManager.h"

CColliderMesh::CColliderMesh()
	: mpColliderTriangles(nullptr)
	, mTrianglesCount(0)
	, mLayer(CCollider::ELayer::EDEFAULT)
{

}

CColliderMesh::~CColliderMesh()
{
	if (mpColliderTriangles != nullptr)
	{
		//�O�p�R���C�_�z��̍폜
		delete[]mpColliderTriangles;
	}
}

//�D��x�̕ύX
void CColliderMesh::ChangePriority()
{
	for (int i = 0; i < mTrianglesCount; i++)
	{
		//�O�p�R���C�_�̐ݒ�
		mpColliderTriangles[i].ChangePriority();
	}
}

//Set�i�e�A�e�s��A���f���j
//���f������O�p�R���C�_�̐���
void CColliderMesh::Set(CCharacter3* parent, const CMatrix* matrix, CModel* model)
{
	//�O�p�`�R���C�_�𐶐��ς݂ł���΁A��������
	if (mpColliderTriangles != nullptr)
	{
		//�O�p�R���C�_�z��̍폜
		delete[] mpColliderTriangles; //[]��t����Ɣz��S�č폜�A������ΐ擪�̂ݍ폜
	}
	//���f���̎O�p�|���S���ŎO�p�R���C�_�̔z��쐬
	mTrianglesCount = model->Triangles().size();
	mpColliderTriangles = new CColliderTriangle[mTrianglesCount];
	for (int i = 0; i < mTrianglesCount; i++)
	{
		//�O�p�R���C�_�̐ݒ�
		mpColliderTriangles[i].Set(parent, matrix
			, model->Triangles()[i].V0()
			, model->Triangles()[i].V1()
			, model->Triangles()[i].V2());
		mpColliderTriangles[i].ChangePriority();
		mpColliderTriangles[i].Layer(mLayer);
	}
}

//�R���C�_�̃��C���[���擾
CCollider::ELayer CColliderMesh::Layer() const
{
	return mLayer;
}

void CColliderMesh::Layer(CCollider::ELayer layer)
{
	mLayer = layer;
	//�����ς̎O�p�`�R���C�_�S�ĂɃ��C���[��ݒ�
	for (int i= 0; i < mTrianglesCount; i++)
	{
		mpColliderTriangles[i].Layer(mLayer);
	}
}