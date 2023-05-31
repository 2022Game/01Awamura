#ifndef CCOLLIDERMESH2_H
#define CCOLLIDERMESH2_H
#include "CModel.h"
#include "CColliderTriangle2.h"
#include "CCollider.h"

/*
モデルデータから三角コライダの生成
*/
class CColliderMesh2
{
public:
	void ChangePriority();
	CColliderMesh2();
	~CColliderMesh2();
	//Set（親、親行列、モデル）
	//モデルから三角コライダの生成
	void Set(CCharacter3* parent, CMatrix* matrix, CModel* model);
private:
	//三角コライダの配列生成
	CColliderTriangle2* mpColliderTriangles2;
	//三角コライダの配列の要素数
	int mTrianglesCount2;
};
#endif