#ifndef CCOLLIDERTRIANGLE1_H
#define CCOLLIDERTRIANGLE1_H
#include "CCollider.h"
/*
�O�p�`�R���C�_�̒�`
*/
class CColliderTriangle1 : public CCollider
{
public:
	void ChangePriority();
	CColliderTriangle1() {}
	//�R���X�g���N�^(�O�p�R���C�_�j
	//CColliderTriangle(�e�A�e�s��A���_1�A���_�Q�A���_�R�j
	CColliderTriangle1(CCharacter3* parent, CMatrix* matrix
		, const CVector& v0, const CVector& v1, const CVector& v2);
	//�O�p�R���C�_�̐ݒ�
	//Set(�e�A�e�s��A���_�P�A���_�Q�A���_�R�j
	void Set(CCharacter3* parent, CMatrix* matrix
		, const CVector& v0, const CVector& v1, const CVector& v2);
	//�`��
	void Render();
};
#endif