#include "CStageEntrance.h"
#include "CFloor.h"
#include "CWarp.h"

//コンストラクタ
CStageEntrance::CStageEntrance()
{
	mStageNo = 0;
}

//デストラクタ
CStageEntrance::~CStageEntrance()
{

}

//ステージ読み込み
void CStageEntrance::Load()
{
	// 普通の土台のモデル読み込み
	CModel* floorModel = CResourceManager::Get<CModel>("Floor");

	//ワープ扉の読み込み
	CModel* warpModel = CResourceManager::Get<CModel>("Warp");

	//普通の足場
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, 2.0f, -20.0f), CVector(0.5f, 4.0f, 5.0f));
	AddTask(floor);

	//ワープ扉を作成
	CWarp* warp = new CWarp(warpModel,
		CVector(0.0f, 10.0f, -20.0f), CVector(6.0f, 3.0f, 10.0f));
	AddTask(warp);
}

//ステージ破棄
void CStageEntrance::Unload()
{
	//ベースのステージ破棄処理
	CStageBase::Unload();
}