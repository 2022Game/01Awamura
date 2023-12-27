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
	int RandPos2;
	int RandPos3;
	int RandPosDate;
	int RandPosDate2;
	float RandPosX;
	float RandPosX2;
	float RandPosZ;
	float RandPosZ2;
	float PosY;
	float PosY2;
};