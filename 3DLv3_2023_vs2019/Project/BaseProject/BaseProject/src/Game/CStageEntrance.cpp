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
	// クリア土台のモデル読み込み
	CModel* floorModel = new CModel();
	floorModel->Load("Field\\Object\\cube.obj", "Field\\Object\\cube.mtl");
	mCreateModels.push_back(floorModel);

	CModel* warpModel = new CModel();
	warpModel->Load("Field\\WarpDoor2.obj", "Field\\WarpDoor2.mtl");
	mCreateModels.push_back(warpModel);

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