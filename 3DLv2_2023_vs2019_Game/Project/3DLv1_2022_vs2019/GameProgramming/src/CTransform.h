#ifndef CTRANSFORM_H
#define CTRANSFORM_H
#include "CVector.h"
#include "CMatrix.h"
/*�g�����X�t�H�[���N���X
�ʒu�A��]�A�g�k�A�ϊ��s��̊�{�N���X
*/
class CTransform {
public:
	//�ʒu�̎擾
	const CVector& Position() const;
	//�ʒu�̐ݒ�
	//position(�ʒu�j
	void Position(const CVector& v);
	//��]�l�̐ݒ�
	//Rotation�i��]�l�j
	void Rotation(const CVector& v);
	//�g��k���̐ݒ�
	//Scale(�g��k���j
	void Scale(const CVector& v);
	//�����s��̎擾
	const CMatrix& Matrix() const;
	//��]�s��̎擾
	const CMatrix& MatrixRotate() const;
	//�s��X�V����
	void Update();
	//Update(�ʒu�A��]�A�X�P�[���j
	void Update(const CVector& pos, const CVector& rot, const CVector& scale);
protected: //�q�N���X�̓A�N�Z�X�\
	CVector mPosition; //�ʒu
	CVector mRotation; //��]
	CVector mScale; //�g��k��
	CMatrix mMatrixTranslate; //���s�ړ��s��
	CMatrix mMatrixRotate; //��]�s��
	CMatrix mMatrixScale; //�g��k���s��
	CMatrix mMatrix; //�����s��
};

#endif