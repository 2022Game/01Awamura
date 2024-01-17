#include "CStage8.h"
#include "CClearCube.h"
#include "CFloor.h"
#include "Maths.h"
#include "CPlayer.h"
#include "CCamera.h"
#include "CIceField.h"
#include "CCube.h"

//コンストラクタ
CStage8::CStage8()
{
	mStageNo = 8;
}

//デストラクタ
CStage8::~CStage8()
{

}

//ステージ読み込み
void CStage8::Load()
{
	//普通の足場読み込み
	CModel* floorModel = CResourceManager::Get<CModel>("FieldCube");

	//壁読み込み
	CModel* cubeModel = CResourceManager::Get<CModel>("Cube");

	//滑る足場読み込み
	CModel* icefieldModel = CResourceManager::Get<CModel>("IceField");

	// クリア土台のモデル読み込み
	CModel* clearCubeStageModel = CResourceManager::Get<CModel>("Clearcube");


	//普通の足場
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, -10.0f, 0.0f), CVector(5.0f, 4.0f, 1.0f));
	AddTask(floor);

	//壁
	CCube* cube = new CCube(cubeModel,
		CVector(0.0f, 10.0f, -100.0f), CVector(0.5f, 5.0f, 0.5f));
	AddTask(cube);

	//滑る足場
	CIceField* icefield = new CIceField(icefieldModel,
		CVector(0.0f, -10.0f, -150.0f), CVector(5.0f, 4.0f, 5.0f));
	AddTask(icefield);

	//クリア土台を作成
	CClearCube* coin = new CClearCube(clearCubeStageModel,
		CVector(0.0f, -10.0f, -300.0f), CVector(5.0f, 4.0f, 1.0f));
	AddTask(coin);

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
void CStage8::Unload()
{
	//ベースのステージ破棄処理
	CStageBase::Unload();
}