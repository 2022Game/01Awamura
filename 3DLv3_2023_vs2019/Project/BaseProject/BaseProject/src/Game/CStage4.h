#pragma once
#include "CStageBase.h"
#include "CText.h"

//ステージ4「ぐるぐる縄跳びステージ」
class CStage4 : public CStageBase
{
public:
	//コンストラクタ
	CStage4();
	//デストラクタ
	~CStage4();

	//ステージ読み込み
	void Load() override;
	//ステージ破棄
	void Unload() override;

private:
	CText* mpText;
	CText* mpTextShadow;
};