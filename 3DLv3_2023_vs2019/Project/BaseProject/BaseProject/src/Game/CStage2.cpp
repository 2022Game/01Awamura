#include "CStage2.h"
#include "CClearCube.h"
#include "CSlope.h"
#include "CFloor.h"
#include "CStone.h"
#include "Maths.h"

//コンストラクタ
CStage2::CStage2()
{
	mStageNo = 2;
}

//デストラクタ
CStage2::~CStage2()
{

}

//ステージ読み込み
void CStage2::Load()
{
	//普通の足場読み込み
	CModel* floorModel = CResourceManager::Get<CModel>("FieldCube");

	// クリア土台のモデル読み込み
	CModel* clearCubeStageModel = CResourceManager::Get<CModel>("Clearcube");

	// 坂道土台のモデル読み込み
	CModel* slopeModel = CResourceManager::Get<CModel>("Slope");

	// 岩石のモデル読み込み
	CModel* stoneModel = CResourceManager::Get<CModel>("Stone");


	//普通の足場
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, -10.0f, 0.0f), CVector(5.0f, 4.0f, 1.0f));
	AddTask(floor);

	//クリア土台を作成
	CClearCube* coin = new CClearCube(clearCubeStageModel,
		CVector(0.0f, 70.0f, -300.0f), CVector(5.0f, 1.0f, 1.0f));
	AddTask(coin);

	//坂道を作成
	CSlope* slope = new CSlope(slopeModel,
		CVector(0.0f, -10.0f, -150.0f), CVector(5.0f, 4.0f, 5.0f));
	AddTask(slope);

	//岩石を作成
	for (int i = 0; i < 15 ; i++)
	{
		CStone* stone = new CStone(stoneModel,
			CVector(Math::Rand(-100, 100), 240.0f, -260.0f), CVector(10.0f, 10.0f, 10.0f), 0.0f);
		AddTask(stone);
	}
}

//ステージ破棄
void CStage2::Unload()
{
	//ベースのステージ破棄処理
	CStageBase::Unload();
}