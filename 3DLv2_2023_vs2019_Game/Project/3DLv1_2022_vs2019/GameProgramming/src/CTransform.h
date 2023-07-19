#ifndef CTRANSFORM_H
#define CTRANSFORM_H
#include "CVector.h"
#include "CMatrix.h"
#include <list>
/*
�g�����X�t�H�[���N���X
�ʒu�A��]�A�g�k�A�ϊ��s��̊�{�N���X
*/
class CTransform {
public:
	//�R���X�g���N�^
	CTransform();
	//�f�X�g���N�^
	virtual ~CTransform();
	//�ʒu�̎擾
	CVector Position() const;
	//�ʒu�̐ݒ�
	//Position(�ʒu)
	void Position(const CVector& v);
	//��]�l�̎擾
	const CVector& Rotation() const;
	//��]�l�̐ݒ�
	//Rotation(��]�l)
	void Rotation(const CVector& v);
	//�X�P�[���l�̎擾
	CVector Scale() const;
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
	//�q����Transform�����X�g�ɒǉ�
	void AddChild(CTransform* child);
	//�q����Transform�����X�g�����菜��
	void RemoveChild(CTransform* child);
	//�s��X�V����
	void Update();
	//Update(�ʒu, ��], �X�P�[��)
	void Update(const CVector& pos, const CVector& rot, const CVector& scale);
private:
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
	std::list<CTransform*> mChildren;	//�q����Transform���X�g
};

#endif