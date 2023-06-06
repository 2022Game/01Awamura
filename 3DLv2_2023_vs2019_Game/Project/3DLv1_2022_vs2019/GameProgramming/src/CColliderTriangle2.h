#ifndef CCOLLIDERTRIANGLE2_H
#define CCOLLIDERTRIANGLE2_H
#include "CCollider.h"

//クリア用

/*
三角形コライダの定義
*/
class CColliderTriangle2 : public CCollider
{
public:
	void ChangePriority();
	CColliderTriangle2() {}
	//コンストラクタ(三角コライダ）
	//CColliderTriangle(親、親行列、頂点1、頂点２、頂点３）
	CColliderTriangle2(CCharacter3* parent, CMatrix* matrix
		, const CVector& v0, const CVector& v1, const CVector& v2);
	//三角コライダの設定
	//Set(親、親行列、頂点１、頂点２、頂点３）
	void Set(CCharacter3* parent, CMatrix* matrix
		, const CVector& v0, const CVector& v1, const CVector& v2);
	//描画
	void Render();
};
#endif