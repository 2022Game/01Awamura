#include "CStage1.h"
#include "CClearStage.h"
#include "CAxe.h"
#include "CFloor.h"
#include "CWarp.h"
#include "CPlayer.h"
#include "CCamera.h"
#include "CGameManager.h"

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
void CStage1::Unload()
{
	//ベースのステージ破棄処理
	CStageBase::Unload();
}