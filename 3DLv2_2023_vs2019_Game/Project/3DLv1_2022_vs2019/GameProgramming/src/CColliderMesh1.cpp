#include "CColliderMesh1.h"
#include "CCollisionManager.h"

CColliderMesh1::CColliderMesh1()
	: mpColliderTriangles1(nullptr)
	, mTrianglesCount1(0)
{

}

CColliderMesh1::~CColliderMesh1()
{
	if (mpColliderTriangles1 != nullptr)
	{
		//三角コライダ配列の削除
		delete[]mpColliderTriangles1;
	}
}

//優先度の変更
void CColliderMesh1::ChangePriority()
{
	for (int i = 0; i < mTrianglesCount1; i++)
	{
		//三角コライダの設定
		mpColliderTriangles1[i].ChangePriority();
	}
}

//Set（親、親行列、モデル）
//モデルから三角コライダの生成
void CColliderMesh1::Set(CCharacter3* parent, CMatrix* matrix, CModel* model)
{
	//モデルの三角ポリゴンで三角コライダの配列作成
	mTrianglesCount1 = model->Triangles().size();
	mpColliderTriangles1 = new CColliderTriangle1[mTrianglesCount1];
	for (int i = 0; i < mTrianglesCount1; i++)
	{
		//三角コライダの設定
		mpColliderTriangles1[i].Set(parent, matrix
			, model->Triangles()[i].V0()
			, model->Triangles()[i].V1()
			, model->Triangles()[i].V2());
		mpColliderTriangles1[i].ChangePriority();
	}
}