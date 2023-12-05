#pragma once
#include "CStageBase.h"

//ステージ「入口」
class CStageEntrance : public CStageBase
{
public:
	//コンストラクタ
	CStageEntrance();
	//デストラクタ
	~CStageEntrance();

	//ステージ読み込み
	void Load() override;
	//ステージ破棄
	void Unload() override;

private:
};