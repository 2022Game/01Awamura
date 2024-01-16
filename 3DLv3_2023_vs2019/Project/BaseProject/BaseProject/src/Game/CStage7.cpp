#include "CStage7.h"
#include "CClearStage.h"
#include "CFloor.h"
#include "CPlayer.h"
#include "CCamera.h"
#include "CDisappearFloor.h"
#include "Maths.h"

//コンストラクタ
CStage7::CStage7()
	:RandPos(0)
	, RandPos2(0)
	, RandPos3(0)
	, RandPosX(0)
	, RandPosX2(0)
	, RandPosZ(0)
	, RandPosZ2(0)
	, PosY(0)
	, PosY2(0)
	, RandPosDate(0)
	, RandPosDate2(0)
	, RandPosDate3(0)
	, RandPosDate4(0)
	, RandPosDate5(0)
	, RandPosDate6(0)
	,z(8)
{
	mStageNo = 7;
	PosY = 380.0f;
	PosY2 = -200.0f;
	PosZ = 215.0f;
}

//デストラクタ
CStage7::~CStage7()
{

}

//ステージ読み込み
void CStage7::Load()
{
	// クリア土台のモデル読み込み
	CModel* clearStageModel = CResourceManager::Get<CModel>("Clearstage");

	//普通の足場読み込み
	CModel* floorModel = CResourceManager::Get<CModel>("FieldCube");

	//透明の足場読み込み
	CModel* cubecolModel = CResourceManager::Get<CModel>("Cubecol");

	//クリア土台を作成
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, -300.0f, 0.0f), CVector(0.8f, 5.0f, 0.8f));
	AddTask(coin);

	//普通の足場
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, -10.0f, 240.0f), CVector(4.4f, 4.0f, 0.5f));
	AddTask(floor);
	floor = new CFloor(floorModel,
		CVector(0.0f, -10.0f, 43.5f), CVector(4.4f, 4.0f, 0.5f));
	AddTask(floor);

	for (int a = 0; a < 7; a++)
	{
		//重複しないランダムの生成用の配列
		int n[9];
		n[0] = 0;
		n[1] = 1;
		n[2] = 2;
		n[3] = 3;
		n[4] = 4;
		n[5] = 5;
		n[6] = 6;
		n[7] = 7;
		n[8] = 8;
		z = 8;
		for (int i = 0; i < 7; i++)
		{
			//重複しないランダムの生成
			int x;
			x = Math::Rand(0, z);
			RandPos = n[x];
			n[x] = n[z];
			z = z - 1;
			//透明化土台を作成
			switch (RandPos)
			{
			case 0:
				RandPosX = 0.0f;
				break;
			case 1:
				RandPosX = 24.5f;
				break;
			case 2:
				RandPosX = -24.5f;
				break;
			case 3:
				RandPosX = -49.0f;
				break;
			case 4:
				RandPosX = 49.0f;
				break;
			case 5:
				RandPosX = -73.5f;
				break;
			case 6:
				RandPosX = 73.5f;
				break;
			case 7:
				RandPosX = 98.0f;
				break;
			case 8:
				RandPosX = -98.0f;
				break;
			};
			//透過土台
			CDisappearFloor* dfloor = new CDisappearFloor
			(
				CVector(RandPosX, -10.0f, PosZ), CVector(0.5f, 4.0f, 0.5f),
				ETag::ePlayer, ELayer::ePlayer
			);
		}
		PosZ = PosZ - 24.5f;
	}

	//プレイヤーの開始位置を設定
	CPlayer* player = CPlayer::Instance();
	CVector playerPos = CVector(0.0f, 30.0f, 240.0f);
	if (player != nullptr)
	{
		player->SetStartPosition(playerPos);
	}

	//カメラの位置と向きを設定
	CCamera* mainCamera = CCamera::MainCamera();
	if (mainCamera != nullptr)
	{
		CVector eye = playerPos + CVector(0.0f, 150.0f, 150.0f);
		CVector at = playerPos;
		CVector forward = (at - eye).Normalized();
		CVector side = CVector::Cross(forward, CVector::back);
		CVector up = CVector::Cross(side, forward);
		mainCamera->LookAt(eye, at, up);
		mainCamera->SetFollowTargetTf(player);
	}
}

//ステージ破棄
void CStage7::Unload()
{
	//ベースのステージ破棄処理
	CStageBase::Unload();
}