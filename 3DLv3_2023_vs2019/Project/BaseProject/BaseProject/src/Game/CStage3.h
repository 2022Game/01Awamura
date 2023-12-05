#pragma once
#include "CStageBase.h"

//ステージ3「ぐるぐるパズルゲーム」
class CStage3 : public CStageBase
{
public:
	//コンストラクタ
	CStage3();
	//デストラクタ
	~CStage3();

	//ステージ読み込み
	void Load() override;
	//ステージ破棄
	void Unload() override;

private:
};