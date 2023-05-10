#ifndef CTRANSFORM_H
#define CTRANSFORM_H
#include "CVector.h"
#include "CMatrix.h"
/*
�g�����X�t�H�[���N���X
�ʒu�A��]�A�g�k�A�ϊ��s��̊�{�N���X
*/
class CTransform {
public:
	//�R���X�g���N�^
	CTransform();
	//�ʒu�̎擾
	const CVector& Position() const;
	//�ʒu�̐ݒ�
	//Position(�ʒu)
	void Position(const CVector& v);
	//��]�l�̐ݒ�
	//Rotation(��]�l)
	void Rotation(const CVector& v);
	//�g��k���̐ݒ�
	//Scale(�g��k��)
	void Scale(const CVector& v);
	//�����s��̎擾
	const CMatrix& Matrix() const;
	//���s�ړ��s��̎擾
	const CMatrix& MatrixTranslate() const;
	//��]�s��̎擾
	const CMatrix& MatrixRotate() const;
	//�g��k���s��̎擾
	const CMatrix& MatrixScale() const;
	//�e��Transform��ݒ�
	void SetParent(CTransform* parent);
	//�s��X�V����
	void Update();
	//Update(�ʒu, ��], �X�P�[��)
	void Update(const CVector& pos, const CVector& rot, const CVector& scale);
protected: //�q�N���X�̓A�N�Z�X�\
	CVector mPosition;	//�ʒu
	CVector mRotation;	//��]
	CVector mScale;	//�g��k��

	CMatrix mMatrixTranslate; //���s�ړ��s��(�O���[�o��)
	CMatrix mMatrixRotate; //��]�s��(�O���[�o��)
	CMatrix mMatrixScale; //�g��k���s��(�O���[�o��)
	CMatrix mMatrix; //�����s��(�O���[�o��)

	CMatrix mLocalMatrixTranslate; //���s�ړ��s��(���[�J��)
	CMatrix mLocalMatrixRotate; //��]�s��(���[�J��)
	CMatrix mLocalMatrixScale; //�g��k���s��(���[�J��)
	CMatrix mLocalMatrix; //�����s��(���[�J��)

	CTransform* mpParent;	//�e��Transform
};

#endif
