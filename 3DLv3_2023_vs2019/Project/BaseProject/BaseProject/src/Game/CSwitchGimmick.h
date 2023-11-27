#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CSwitchObject.h"

class CSwitchGimmick : public CTask
{
private:
	std::vector<CSwitchObject*> mSwitch;	// クリア土台のリスト
	CModel* mpMoveSwitchModel;			// スイッチのモデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateSwitch(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpSwitch;


public:
	CSwitchGimmick();
	~CSwitchGimmick();

	// 更新処理
	void Update();
};