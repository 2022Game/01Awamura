#include "CTransform.h"

CTransform::CTransform()
	: mpParent(nullptr)
{
}

const CVector& CTransform::Position() const
{
	CVector pos = mPosition;
	if (mpParent != nullptr)
	{
		pos = pos * mpParent->Matrix();
	}
	return pos;
}

void CTransform::Position(const CVector& v)
{
	mPosition = v;
	if (mpParent != nullptr)
	{
		mPosition = mPosition * mpParent->Matrix().Inverse();
	}
}

const CVector& CTransform::Rotation() const
{
	return mRotation;
}

void CTransform::Rotation(const CVector& v)
{
	mRotation = v;
}

const CVector& CTransform::Scale() const
{
	return mScale;
}

void CTransform::Scale(const CVector& v)
{
	mScale = v;
}

const CMatrix& CTransform::Matrix() const
{
	return mMatrix;
}

const CMatrix& CTransform::MatrixTranslate() const
{
	return mMatrixTranslate;
}

const CMatrix& CTransform::MatrixRotate() const
{
	return mMatrixRotate;
}

const CMatrix& CTransform::MatrixScale() const
{
	return mMatrixScale;
}

//�e��Transform��ݒ�
void CTransform::SetParent(CTransform* parent)
{
	if (mpParent == parent) return;

	if (mpParent != nullptr)
	{
		mPosition = mPosition * mpParent->Matrix();
	}
	if (parent != nullptr)
	{
		mPosition = mPosition * parent->Matrix().Inverse();
	}
	mpParent = parent;
}

//�s��X�V����
void CTransform::Update() {
	//�g��k���s��̐ݒ�
	mLocalMatrixScale.Scale(mScale.X(), mScale.Y(), mScale.Z());
	//��]�s��̐ݒ�
	mLocalMatrixRotate =
		CMatrix().RotateZ(mRotation.Z()) *
		CMatrix().RotateX(mRotation.X()) *
		CMatrix().RotateY(mRotation.Y());
	//���s�ړ��s��̐ݒ�
	mLocalMatrixTranslate.Translate(mPosition.X(), mPosition.Y(), mPosition.Z());
	//�����s��̐ݒ�
	mLocalMatrix = mLocalMatrixScale * mLocalMatrixRotate * mLocalMatrixTranslate;

	//�e������ꍇ
	if (mpParent != nullptr)
	{
		//���[���h�s�� = �e�̃��[���h�s�� �~ ���[�J���s��
		const CMatrix& parentMtx = mpParent->Matrix();
		mMatrixTranslate = mLocalMatrixTranslate * parentMtx;
		mMatrixRotate = mLocalMatrixRotate * mpParent->MatrixRotate();
		mMatrixScale = mLocalMatrixScale * mpParent->MatrixScale();
		mMatrix = mLocalMatrix * parentMtx;
	}
	//�e�����Ȃ��ꍇ
	else
	{
		//���[�J���s������̂܂܃O���[�o���s��ɐݒ�
		mMatrixTranslate = mLocalMatrixTranslate;
		mMatrixRotate = mLocalMatrixRotate;
		mMatrixScale = mLocalMatrixScale;
		mMatrix = mLocalMatrix;
	}
}

void CTransform::Update(const CVector& pos, const CVector& rot, const CVector& scale)
{
	Position(pos);
	Rotation(rot);
	Scale(scale);
	Update();
}
