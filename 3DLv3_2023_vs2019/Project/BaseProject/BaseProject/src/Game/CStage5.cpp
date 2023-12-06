#include "CStage5.h"
#include "CClearStage.h"
#include "CFloor.h"

//コンストラクタ
CStage5::CStage5()
{
	mStageNo = 5;
}

//デストラクタ
CStage5::~CStage5()
{

}

//ステージ読み込み
void CStage5::Load()
{
	// クリア土台のモデル読み込み
	CModel* clearStageModel = CResourceManager::Get<CModel>("Clearstage");

	//普通の足場読み込み
	CModel* floorModel = CResourceManager::Get<CModel>("Floor");

	//クリア土台を作成
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, -5.0f, -20.0f), CVector(1.0f, 1.0f, 1.0f));
	AddTask(coin);

	//普通の足場
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, 2.0f, -20.0f), CVector(0.5f, 4.0f, 5.0f));
	AddTask(floor);
}

//ステージ破棄
void CStage5::Unload()
{
	//ベースのステージ破棄処理
	CStageBase::Unload();
}