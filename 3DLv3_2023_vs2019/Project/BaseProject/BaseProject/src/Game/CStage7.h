#pragma once
#include "CStageBase.h"
#include "CText.h"

//ステージ7「透明化ステージ」
class CStage7 : public CStageBase
{
public:
	//コンストラクタ
	CStage7();
	//デストラクタ
	~CStage7();

	//ステージ読み込み
	void Load() override;
	//ステージ破棄
	void Unload() override;

private:
	CText* mpText;
	CText* mpTextShadow;
	int n;
	int z;
	int RandPos;
	int RandPos2;
	int RandPos3;
	int RandPosDate;
	int RandPosDate2;
	int RandPosDate3;
	int RandPosDate4;
	int RandPosDate5;
	int RandPosDate6;
	float RandPosX;
	float RandPosX2;
	float RandPosZ;
	float RandPosZ2;
	float PosY;
	float PosY2;
	float PosZ;
};