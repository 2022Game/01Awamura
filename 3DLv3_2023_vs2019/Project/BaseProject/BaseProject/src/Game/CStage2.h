#pragma once
#include "CStageBase.h"

//ステージ2「岩石坂道ステージ」
class CStage2 : public CStageBase
{
public:
	//コンストラクタ
	CStage2();
	//デストラクタ
	~CStage2();

	//ステージ読み込み
	void Load() override;
	//ステージ破棄
	void Unload() override;

private:
};