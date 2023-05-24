#ifndef CCOLLIDERTRIANGLE1_H
#define CCOLLIDERTRIANGLE1_H
#include "CCollider.h"
/*
三角形コライダの定義
*/
class CColliderTriangle1 : public CCollider
{
public:
	void ChangePriority();
	CColliderTriangle1() {}
	//コンストラクタ(三角コライダ）
	//CColliderTriangle(親、親行列、頂点1、頂点２、頂点３）
	CColliderTriangle1(CCharacter3* parent, CMatrix* matrix
		, const CVector& v0, const CVector& v1, const CVector& v2);
	//三角コライダの設定
	//Set(親、親行列、頂点１、頂点２、頂点３）
	void Set(CCharacter3* parent, CMatrix* matrix
		, const CVector& v0, const CVector& v1, const CVector& v2);
	//描画
	void Render();
};
#endif