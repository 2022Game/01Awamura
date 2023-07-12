#pragma once
#include "CTask.h"
#include "CModel.h"
#include "CColliderMesh.h"

//フィールド
class CField : public CTask
{
public:
	//コンストラクタ
	CField();
	//デストラクタ
	~CField();

	//更新処理
	void Update();
	//描画処理
	void Render();

private:
	CModel* mModel; //フィールドのモデルデータ
	CColliderMesh mColliderMesh; //フィールドの当たり判定用コライダ
};