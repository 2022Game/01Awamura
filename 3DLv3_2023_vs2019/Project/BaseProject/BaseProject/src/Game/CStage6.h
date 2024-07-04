#pragma once
#include "CStageBase.h"
#include "CText.h"

//ステージ6「ぐるぐる土台」
class CStage6 : public CStageBase
{
public:
	//コンストラクタ
	CStage6();
	//デストラクタ
	~CStage6();

	//ステージ読み込み
	void Load() override;
	//ステージ破棄
	void Unload() override;

private:
	CText* mpText;
	CText* mpTextShadow;
};