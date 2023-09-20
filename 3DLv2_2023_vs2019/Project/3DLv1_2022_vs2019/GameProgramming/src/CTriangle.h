//#pragma once
#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include"CVector.h"
/*
�O�p�`�N���X
*/
class CTriangle {
public:
	//���_���W�ݒ�
	//Vertex(���_1,���_2,���_3,)
	void Vertex(const CVector &v0, const CVector &v1, const CVector &v2);
	//�@���ݒ�
	//Normal(�@���x�N�g���j
	void Normal(const CVector &n);
	//�`��
	void Render();
	//Normal(�@���x�N�g��1,�@���x�N�g���Q,�@���x�N�g��3�j
	void Normal(const CVector &v0, const CVector &v1, const CVector &v2);
	//�}�e���A���ԍ��̎擾
	int MaterialIdx();
	//�}�e���A���ԍ��̐ݒ�
	//Material(�}�e���A���ԍ��j
	void MaterialIdx(int idx);
	//UV�ݒ�
	void UV(const CVector& v0, const CVector& v1, const CVector& v2);
	//�`��
	//Render(�s��j
	void Render(const CMatrix& m);
	//���_���W�𓾂�
	const CVector& V0() const;
	const CVector& V1() const;
	const CVector& V2() const;
	//�@���𓾂�
	const CVector& N0() const;
	const CVector& N1() const;
	const CVector& N2() const;
	//UV�𓾂�
	const CVector& U0() const;
	const CVector& U1() const;
	const CVector& U2() const;
private:
	CVector mV[3];//���_���W
	CVector mN[3]; //�@��
	CVector mUv[3]; //�e�N�X�`���}�b�s���O
	int mMaterialIdx; //�}�e���A���ԍ�
};
#endif