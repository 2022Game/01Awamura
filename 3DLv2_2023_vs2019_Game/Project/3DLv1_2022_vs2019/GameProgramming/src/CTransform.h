#ifndef CTRANSFORM_H
#define CTRANSFORM_H
#include "CVector.h"
#include "CMatrix.h"
#include <list>
/*
トランスフォームクラス
位置、回転、拡縮、変換行列の基本クラス
*/
class CTransform {
public:
	//コンストラクタ
	CTransform();
	//デストラクタ
	virtual ~CTransform();
	//位置の取得
	CVector Position() const;
	//位置の設定
	//Position(位置)
	void Position(const CVector& v);
	//回転値の取得
	const CVector& Rotation() const;
	//回転値の設定
	//Rotation(回転値)
	void Rotation(const CVector& v);
	//スケール値の取得
	CVector Scale() const;
	//拡大縮小の設定
	//Scale(拡大縮小)
	void Scale(const CVector& v);
	//合成行列の取得
	const CMatrix& Matrix() const;
	//平行移動行列の取得
	const CMatrix& MatrixTranslate() const;
	//回転行列の取得
	const CMatrix& MatrixRotate() const;
	//拡大縮小行列の取得
	const CMatrix& MatrixScale() const;
	//親のTransformを設定
	void SetParent(CTransform* parent);
	//子供のTransformをリストに追加
	void AddChild(CTransform* child);
	//子供のTransformをリストから取り除く
	void RemoveChild(CTransform* child);
	//行列更新処理
	void Update();
	//Update(位置, 回転, スケール)
	void Update(const CVector& pos, const CVector& rot, const CVector& scale);
private:
	CVector mPosition;	//位置
	CVector mRotation;	//回転
	CVector mScale;	//拡大縮小

	CMatrix mMatrixTranslate; //平行移動行列(グローバル)
	CMatrix mMatrixRotate; //回転行列(グローバル)
	CMatrix mMatrixScale; //拡大縮小行列(グローバル)
	CMatrix mMatrix; //合成行列(グローバル)

	CMatrix mLocalMatrixTranslate; //平行移動行列(ローカル)
	CMatrix mLocalMatrixRotate; //回転行列(ローカル)
	CMatrix mLocalMatrixScale; //拡大縮小行列(ローカル)
	CMatrix mLocalMatrix; //合成行列(ローカル)

	CTransform* mpParent;	//親のTransform
	std::list<CTransform*> mChildren;	//子供のTransformリスト
};

#endif