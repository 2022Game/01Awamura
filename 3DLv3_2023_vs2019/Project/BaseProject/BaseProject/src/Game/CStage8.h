#pragma once
#include "CStageBase.h"

//横方向の配置数
#define BLOCK_COUNT_X 9
//縦方向の配置数
#define BLOCK_COUNT_Y 10
//ブロックを配置する最大数
#define MAX_BLOCK_COUNT 30
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
	//壁にぶつかるまで移動して、通ったマスを移動ルートにする。
	int PaveTheRoute(int x, int y, int moveX, int moveY);

	//ブロックの配置データを作成
	void CreateBlockData();

	//ブロックの配置データ
	//(0:なにもなし、１：ブロック配置、２：移動ルート）
	int mBlockData[BLOCK_COUNT_X][BLOCK_COUNT_Y];
	//int mBlockData[9][10];
};