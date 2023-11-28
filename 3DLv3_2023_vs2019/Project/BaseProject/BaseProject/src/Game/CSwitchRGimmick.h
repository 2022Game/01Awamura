#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CSwitchRObject.h"

class CSwitchRGimmick : public CTask
{
private:
	std::vector<CSwitchRObject*> mRSwitch;	// クリア土台のリスト
	CModel* mpMoveSwitchRModel;			// スイッチのモデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateSwitch(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpSwitch;


public:
	CSwitchRGimmick();
	~CSwitchRGimmick();

	// 更新処理
	void Update();
};