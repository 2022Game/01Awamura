#include "CStage1.h"
#include "CClearStage.h"
#include "CAxe.h"
#include "CFloor.h"
#include "CWarp.h"

//コンストラクタ
CStage1::CStage1()
{
	mStageNo = 1;
}

//デストラクタ
CStage1::~CStage1()
{

}

//ステージ読み込み
void CStage1::Load()
{
	//普通の足場読み込み
	CModel* floorModel = CResourceManager::Get<CModel>("FieldCube");

	//ワープ扉読み込み
	CModel* warpModel = CResourceManager::Get<CModel>("Warp");

	// クリア土台のモデル読み込み
	CModel* clearStageModel = CResourceManager::Get<CModel>("Clearstage");

	// 斧のモデル読み込み
	CModel* axeModel = CResourceManager::Get<CModel>("Axe");

	//普通の足場
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, 2.0f, -20.0f), CVector(0.5f, 4.0f, 5.0f));
	AddTask(floor);

	//ワープ扉を作成
	CWarp* warp = new CWarp(warpModel,
		CVector(0.0f, 10.0f, -100.0f), CVector(6.0f, 3.0f, 10.0f));
	AddTask(warp);

	//クリア土台を作成
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, -5.0f, -20.0f), CVector(1.0f, 1.0f, 1.0f));
	AddTask(coin);

	//斧を作成
	CAxe* axe = new CAxe(axeModel,
		CVector(0.0f, 200.0f, -140.0f), CVector(5.5f, 5.0f, 5.25f)
		,5.0f, 45.0f);
	AddTask(axe);
	axe = new CAxe(axeModel,
		CVector(0.0f, 200.0f, -80.0f), CVector(5.5f, 5.0f, 5.25f)
		, 5.0f, -45.0f);
	AddTask(axe);
}

//ステージ破棄
void CStage1::Unload()
{
	//ベースのステージ破棄処理
	CStageBase::Unload();
}