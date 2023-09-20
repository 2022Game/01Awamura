#ifndef CCOLLIDERMESH_H
#define CCOLLIDERMESH_H
#include "CModel.h"
#include "CColliderTriangle.h"
#include "CCollider.h"

/*
モデルデータから三角コライダの生成
*/
class CColliderMesh
{
public:
	void ChangePriority();
	CColliderMesh();
	~CColliderMesh();
	//Set（親、親行列、モデル）
	//モデルから三角コライダの生成
	void Set(CCharacter3* parent, const CMatrix* matrix, CModel* model);

	//コライダのレイヤーを取得
	CCollider::ELayer Layer() const;
	void Layer(CCollider::ELayer layer);
private:
	//コライダのレイヤー
	CCollider::ELayer mLayer;
	//三角コライダの配列生成
	CColliderTriangle* mpColliderTriangles;
	//三角コライダの配列の要素数
	int mTrianglesCount;
};
#endif