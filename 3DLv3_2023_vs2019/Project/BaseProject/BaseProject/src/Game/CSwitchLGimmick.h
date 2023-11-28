#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CSwitchLObject.h"

class CSwitchLGimmick : public CTask
{
private:
	std::vector<CSwitchLObject*> mLSwitch;	// クリア土台のリスト
	CModel* mpMoveSwitchLModel;			// スイッチのモデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateSwitch(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpSwitch;


public:
	CSwitchLGimmick();
	~CSwitchLGimmick();

	// 更新処理
	void Update();
};