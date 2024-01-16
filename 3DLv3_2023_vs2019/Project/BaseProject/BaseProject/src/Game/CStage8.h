#pragma once
#include "CStageBase.h"

//ステージ2「岩石坂道ステージ」
class CStage8 : public CStageBase
{
public:
	//コンストラクタ
	CStage8();
	//デストラクタ
	~CStage8();

	//ステージ読み込み
	void Load() override;
	//ステージ破棄
	void Unload() override;

private:
};