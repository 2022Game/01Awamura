#include "CColliderMesh.h"
#include "CCollisionManager.h"

CColliderMesh::CColliderMesh()
	: mpColliderTriangles(nullptr)
	, mTrianglesCount(0)
	, mLayer(CCollider::ELayer::EDEFAULT)
{

}

CColliderMesh::~CColliderMesh()
{
	if (mpColliderTriangles != nullptr)
	{
		//三角コライダ配列の削除
		delete[]mpColliderTriangles;
	}
}

//優先度の変更
void CColliderMesh::ChangePriority()
{
	for (int i = 0; i < mTrianglesCount; i++)
	{
		//三角コライダの設定
		mpColliderTriangles[i].ChangePriority();
	}
}

//Set（親、親行列、モデル）
//モデルから三角コライダの生成
void CColliderMesh::Set(CCharacter3* parent, const CMatrix* matrix, CModel* model)
{
	//三角形コライダを生成済みであれば、瓦解する
	if (mpColliderTriangles != nullptr)
	{
		//三角コライダ配列の削除
		delete[] mpColliderTriangles; //[]を付けると配列全て削除、無ければ先頭のみ削除
	}
	//モデルの三角ポリゴンで三角コライダの配列作成
	mTrianglesCount = model->Triangles().size();
	mpColliderTriangles = new CColliderTriangle[mTrianglesCount];
	for (int i = 0; i < mTrianglesCount; i++)
	{
		//三角コライダの設定
		mpColliderTriangles[i].Set(parent, matrix
			, model->Triangles()[i].V0()
			, model->Triangles()[i].V1()
			, model->Triangles()[i].V2());
		mpColliderTriangles[i].ChangePriority();
		mpColliderTriangles[i].Layer(mLayer);
	}
}

//コライダのレイヤーを取得
CCollider::ELayer CColliderMesh::Layer() const
{
	return mLayer;
}

void CColliderMesh::Layer(CCollider::ELayer layer)
{
	mLayer = layer;
	//生成済の三角形コライダ全てにレイヤーを設定
	for (int i= 0; i < mTrianglesCount; i++)
	{
		mpColliderTriangles[i].Layer(mLayer);
	}
}