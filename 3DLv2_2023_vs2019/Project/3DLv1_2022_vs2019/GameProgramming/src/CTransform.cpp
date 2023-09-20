#include "CTransform.h"
#include <corecrt_math.h>
#include <stdio.h>

CTransform::CTransform()
	: mpParent(nullptr)
{
}

CTransform::~CTransform()
{
	//親が存在する場合は、親の子供リストから自身を取り除く
	if (mpParent != nullptr)
	{
		mpParent->RemoveChild(this);
	}

	//子供が存在する場合は、子供との親子関係を解除する
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
	//親が存在するならば
	if (mpParent != nullptr)
	{
		//親のスケール行列の逆行列を掛けて、
		//ワールド空間でのスケール値を返す
		scale = scale * mpParent->MatrixScale();
	}
	return mScale;
}

void CTransform::Scale(const CVector& v)
{
	mScale = v;
	if (mpParent != nullptr)
	{
		//親のスケール行列の逆行列を掛けて
		//親から見た相対的（ローカル）なスケール値に変換
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

//親のTransformを設定
void CTransform::SetParent(CTransform* parent)
{
	if (mpParent == parent) return;

	if (mpParent != nullptr)
	{
		//座標、スケール値、それぞれを
		//ワールド空間での値に戻す
		mPosition = mPosition * mpParent->Matrix();
		mScale = mScale * mpParent->MatrixScale();

		//前の親の子供リストから自身を取り除く
		mpParent->RemoveChild(this);
	}
	//新しく設定する親が存在するならば
	if (parent != nullptr)
	{
		//座標、スケール値を
		//設定する親から見た相対的な値に変換する
		mPosition = mPosition * parent->Matrix().Inverse();
		mScale = mScale * parent->MatrixScale().Inverse();

		//新しい親の子供リストに自身を追加
		parent->AddChild(this);
	}
	mpParent = parent;
}

//子供のTransformをリストに追加
void CTransform::AddChild(CTransform* child)
{
	mChildren.push_back(child);
}

//子供のTransformをリストから取り除く
void CTransform::RemoveChild(CTransform* child)
{
	mChildren.remove(child);
}

//行列更新処理
void CTransform::Update() {
	//拡大縮小行列の設定
	mLocalMatrixScale.Scale(mScale.X(), mScale.Y(), mScale.Z());
	//回転行列の設定
	mLocalMatrixRotate =
		CMatrix().RotateZ(mRotation.Z()) *
		CMatrix().RotateX(mRotation.X()) *
		CMatrix().RotateY(mRotation.Y());
	//平行移動行列の設定
	mLocalMatrixTranslate.Translate(mPosition.X(), mPosition.Y(), mPosition.Z());
	//合成行列の設定
	mLocalMatrix = mLocalMatrixScale * mLocalMatrixRotate * mLocalMatrixTranslate;

	//親がいる場合
	if (mpParent != nullptr)
	{
		//ワールド行列 = 親のワールド行列 × ローカル行列
		const CMatrix& parentMtx = mpParent->Matrix();
		mMatrixTranslate = mLocalMatrixTranslate * parentMtx;
		mMatrixRotate = mLocalMatrixRotate * mpParent->MatrixRotate();
		mMatrixScale = mLocalMatrixScale * mpParent->MatrixScale();
		mMatrix = mLocalMatrix * parentMtx;
	}
	//親がいない場合
	else
	{
		//ローカル行列をそのままグローバル行列に設定
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