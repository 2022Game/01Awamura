#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CStorn.h"

class CStornGimmick : public CTask
{
private:
	std::vector<CStorn*> mStorn;	// クリア土台のリスト
	CModel* mpStornModel;			// クリア土台のモデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateStorn(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpStorn;


public:
	CStornGimmick();
	~CStornGimmick();

	// 更新処理
	void Update();
};