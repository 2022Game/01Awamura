#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CStone.h"

class CStoneGimmick : public CTask
{
private:
	std::vector<CStone*> mStone;	// クリア土台のリスト
	CModel* mpStoneModel;			// クリア土台のモデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateStone(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpStone;

	int randpos;


public:
	CStoneGimmick();
	~CStoneGimmick();

	// 更新処理
	void Update();
};