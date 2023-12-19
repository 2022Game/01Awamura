#include "CStage5.h"
#include "CClearStage.h"
#include "CFloor.h"
#include "CPlayer.h"
#include "CCamera.h"
#include "CDisappearFloor.h"
#include "CDisappearFloor2.h"
#include "CNeedle.h"
#include "CTransparentField.h"

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
	CModel* floorModel = CResourceManager::Get<CModel>("FieldCube");

	//棘の読み込み
	CModel* needleModel = CResourceManager::Get<CModel>("Needle");

	//クリア土台を作成
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, -225.0f, 0.0f), CVector(1.0f, 5.0f, 1.0f));
	AddTask(coin);

	//普通の足場
	/*CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, 590.0f, 0.0f), CVector(0.5f, 2.0f, 0.5f));
	AddTask(floor);*/

	//透過土台
	CDisappearFloor* dfloor = new CDisappearFloor
	(
		CVector(-12.5f, 400.0f, 12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	AddTask(dfloor);
	dfloor = new CDisappearFloor
	(
		CVector(12.5f, 400.0f, 12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	AddTask(dfloor);
	dfloor = new CDisappearFloor
	(
		CVector(-12.5f, 400.0f, -12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	AddTask(dfloor);
	dfloor = new CDisappearFloor
	(
		CVector(12.5f, 400.0f, -12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	AddTask(dfloor);

	dfloor = new CDisappearFloor
	(
		CVector(-12.5f, 200.0f, 12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	AddTask(dfloor);
	dfloor = new CDisappearFloor
	(
		CVector(12.5f, 200.0f, 12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	AddTask(dfloor);
	dfloor = new CDisappearFloor
	(
		CVector(-12.5f, 200.0f, -12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	AddTask(dfloor);
	dfloor = new CDisappearFloor
	(
		CVector(12.5f, 200.0f, -12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	AddTask(dfloor);

	//透過土台２
	CDisappearFloor2* dfloor2 = new CDisappearFloor2
	(
		CVector(0.0f, 500.0f, 0.0f), CVector(1.0f, 2.0f, 1.0f),
		ETag::ePlayer, ELayer::ePlayer
	);

	dfloor2 = new CDisappearFloor2
	(
		CVector(12.5f, 300.0f, 12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);

	dfloor2 = new CDisappearFloor2
	(
		CVector(12.5f, 300.0f, -12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);

	dfloor2 = new CDisappearFloor2
	(
		CVector(-12.5f, 300.0f, 12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	dfloor2 = new CDisappearFloor2
	(
		CVector(-12.5f, 300.0f, -12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);


	//棘を作成
	CNeedle* needle = new CNeedle(needleModel,
		CVector(12.5f, 380.0f, -12.5f), CVector(3.0f, 2.0f, 3.0f));
	AddTask(needle);

	//透明な土台
	CTransparentField* transfloor = new CTransparentField
	(
		floorModel,CVector(12.5f, 370.0f, -12.5f), CVector(0.5f, 1.0f, 0.5f)
	);
	AddTask(transfloor);

	//プレイヤーの開始位置を設定
	CPlayer* player = CPlayer::Instance();
	CVector playerPos = CVector(0.0f, 550.0f, 0.0f);
	if (player != nullptr)
	{
		player->SetStartPosition(playerPos);
	}

	//カメラの位置と向きを設定
	CCamera* mainCamera = CCamera::MainCamera();
	if (mainCamera != nullptr)
	{
		CVector eye = playerPos + CVector(0.0f, 75.0f, 1.0f);
		CVector at = playerPos;
		CVector forward = (at - eye).Normalized();
		CVector side = CVector::Cross(forward, CVector::up);
		CVector up = CVector::Cross(side, forward);
		mainCamera->LookAt(eye, at, up);
		mainCamera->SetFollowTargetTf(player);
	}
}

//ステージ破棄
void CStage5::Unload()
{
	//ベースのステージ破棄処理
	CStageBase::Unload();
}