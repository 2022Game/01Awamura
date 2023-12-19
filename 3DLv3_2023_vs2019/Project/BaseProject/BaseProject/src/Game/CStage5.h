#pragma once
#include "CStageBase.h"

//ステージ5「透明化ステージ」
class CStage5 : public CStageBase
{
public:
	//コンストラクタ
	CStage5();
	//デストラクタ
	~CStage5();

	//ステージ読み込み
	void Load() override;
	//ステージ破棄
	void Unload() override;

private:
	int RandPos;
	float RandPosX;
	float RandPosZ;
	float PosY;
	float PosY2;
};