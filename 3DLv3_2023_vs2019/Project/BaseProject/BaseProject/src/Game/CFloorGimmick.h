#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CFloor.h"

class CFloorGimmick : public CTask
{
private:
	std::vector<CFloor*> mFloor;	// クリア土台のリスト
	CModel* mpFloorModel;			// クリア土台のモデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateFloor(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpFloor;


public:
	CFloorGimmick();
	~CFloorGimmick();

	// 更新処理
	void Update();
};