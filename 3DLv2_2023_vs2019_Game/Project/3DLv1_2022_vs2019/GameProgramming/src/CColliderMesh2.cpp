#include "CColliderMesh2.h"
#include "CCollisionManager.h"

CColliderMesh2::CColliderMesh2()
	: mpColliderTriangles2(nullptr)
	, mTrianglesCount2(0)
{

}

CColliderMesh2::~CColliderMesh2()
{
	if (mpColliderTriangles2 != nullptr)
	{
		//三角コライダ配列の削除
		delete[]mpColliderTriangles2;
	}
}

//優先度の変更
void CColliderMesh2::ChangePriority()
{
	for (int i = 0; i < mTrianglesCount2; i++)
	{
		//三角コライダの設定
		mpColliderTriangles2[i].ChangePriority();
	}
}

//Set（親、親行列、モデル）
//モデルから三角コライダの生成
void CColliderMesh2::Set(CCharacter3* parent, CMatrix* matrix, CModel* model)
{
	//モデルの三角ポリゴンで三角コライダの配列作成
	mTrianglesCount2 = model->Triangles().size();
	mpColliderTriangles2 = new CColliderTriangle2[mTrianglesCount2];
	for (int i = 0; i < mTrianglesCount2; i++)
	{
		//三角コライダの設定
		mpColliderTriangles2[i].Set(parent, matrix
			, model->Triangles()[i].V0()
			, model->Triangles()[i].V1()
			, model->Triangles()[i].V2());
		mpColliderTriangles2[i].ChangePriority();
	}
}