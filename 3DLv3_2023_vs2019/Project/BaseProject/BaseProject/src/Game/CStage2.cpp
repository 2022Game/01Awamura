#include "CStage2.h"
#include "CClearCube.h"
#include "CSlope.h"
#include "CFloor.h"
#include "CStone.h"
#include "Maths.h"
#include "CPlayer.h"
#include "CCamera.h"
#include "CAppearFloor.h"

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

	CAppearFloor* afloor = new CAppearFloor
	(
		CVector(0.0f, -10.0f, 37.5f), CVector(0.5f, 4.0f, 0.5f),
		ETag::eStone, ELayer::eStone
	);
	AddTask(afloor);

	afloor = new CAppearFloor
	(
		CVector(0.0f, -10.0f, 37.5f + 25.0f), CVector(0.5f, 4.0f, 0.5f),
		ETag::eStone, ELayer::eStone
	);
	AddTask(afloor);

	//プレイヤーの開始位置を設定
	CPlayer* player = CPlayer::Instance();
	CVector playerPos = CVector(0.0f, 30.0f, 0.0f);
	if (player != nullptr)
	{
		player->SetStartPosition(playerPos);
	}

	//カメラの位置と向きを設定
	CCamera* mainCamera = CCamera::MainCamera();
	if (mainCamera != nullptr)
	{
		CVector eye = CVector(0.0f, 50.0f, 75.0f);
		CVector at = playerPos;
		CVector forward = (at - eye).Normalized();
		CVector side = CVector::Cross(forward, CVector::up);
		CVector up = CVector::Cross(side, forward);
		mainCamera->LookAt(eye, at, up);
		mainCamera->SetFollowTargetTf(player);
	}
}

//ステージ破棄
void CStage2::Unload()
{
	//ベースのステージ破棄処理
	CStageBase::Unload();
}