#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CWarp.h"

class CWarpGimmick : public CTask
{
private:
	std::vector<CWarp*> mWarp;	// クリア土台のリスト
	CModel* mpWarpModel;			// クリア土台のモデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateWarp(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpWarp;


public:
	CWarpGimmick();
	~CWarpGimmick();

	// 更新処理
	void Update();
};