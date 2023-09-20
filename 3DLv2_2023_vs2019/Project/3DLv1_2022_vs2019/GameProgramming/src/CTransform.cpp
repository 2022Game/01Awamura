#include "CTransform.h"
#include <corecrt_math.h>
#include <stdio.h>

CTransform::CTransform()
	: mpParent(nullptr)
{
}

CTransform::~CTransform()
{
	//�e�����݂���ꍇ�́A�e�̎q�����X�g���玩�g����菜��
	if (mpParent != nullptr)
	{
		mpParent->RemoveChild(this);
	}

	//�q�������݂���ꍇ�́A�q���Ƃ̐e�q�֌W����������
	auto it = mChildren.begin();
	while (it != mChildren.end())
	{
		CTransform* tf = *it;
		it++;
		tf->SetParent(nullptr);
	}
}

CVector CTransform::Position() const
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

CVector CTransform::Scale() const
{
	CVector scale = mScale;
	//�e�����݂���Ȃ��
	if (mpParent != nullptr)
	{
		//�e�̃X�P�[���s��̋t�s����|���āA
		//���[���h��Ԃł̃X�P�[���l��Ԃ�
		scale = scale * mpParent->MatrixScale();
	}
	return mScale;
}

void CTransform::Scale(const CVector& v)
{
	mScale = v;
	if (mpParent != nullptr)
	{
		//�e�̃X�P�[���s��̋t�s����|����
		//�e���猩�����ΓI�i���[�J���j�ȃX�P�[���l�ɕϊ�
		mScale = mScale * mpParent->MatrixScale().Inverse();
	}
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
		//���W�A�X�P�[���l�A���ꂼ���
		//���[���h��Ԃł̒l�ɖ߂�
		mPosition = mPosition * mpParent->Matrix();
		mScale = mScale * mpParent->MatrixScale();

		//�O�̐e�̎q�����X�g���玩�g����菜��
		mpParent->RemoveChild(this);
	}
	//�V�����ݒ肷��e�����݂���Ȃ��
	if (parent != nullptr)
	{
		//���W�A�X�P�[���l��
		//�ݒ肷��e���猩�����ΓI�Ȓl�ɕϊ�����
		mPosition = mPosition * parent->Matrix().Inverse();
		mScale = mScale * parent->MatrixScale().Inverse();

		//�V�����e�̎q�����X�g�Ɏ��g��ǉ�
		parent->AddChild(this);
	}
	mpParent = parent;
}

//�q����Transform�����X�g�ɒǉ�
void CTransform::AddChild(CTransform* child)
{
	mChildren.push_back(child);
}

//�q����Transform�����X�g�����菜��
void CTransform::RemoveChild(CTransform* child)
{
	mChildren.remove(child);
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