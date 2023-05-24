#ifndef CCOLLIDERMESH1_H
#define CCOLLIDERMESH1_H
#include "CModel.h"
#include "CColliderTriangle1.h"
#include "CCollider.h"

/*
モデルデータから三角コライダの生成
*/
class CColliderMesh1
{
public:
	void ChangePriority();
	CColliderMesh1();
	~CColliderMesh1();
	//Set（親、親行列、モデル）
	//モデルから三角コライダの生成
	void Set(CCharacter3* parent, CMatrix* matrix, CModel* model);
private:
	//三角コライダの配列生成
	CColliderTriangle1* mpColliderTriangles1;
	//三角コライダの配列の要素数
	int mTrianglesCount1;
};
#endif