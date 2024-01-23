#include "CStage3.h"
#include "CClearStage.h"
#include "CFloor.h"
#include "CSwitchLObject.h"
#include "CSwitchRObject.h"
#include "CMoveField.h"
#include "CIMoveField.h"
#include "CTMoveField.h"
#include "CJMoveField.h"
#include "CLMoveField.h"
#include "CPlayer.h"
#include "CCamera.h"
#include "CGameManager.h"

//コンストラクタ
CStage3::CStage3()
{
	mStageNo = 3;
}

//デストラクタ
CStage3::~CStage3()
{

}

//ステージ読み込み
void CStage3::Load()
{
	//普通の足場読み込み
	CModel* floorModel = CResourceManager::Get<CModel>("FieldCube");

	// クリア土台のモデル読み込み
	CModel* clearStageModel = CResourceManager::Get<CModel>("Clearstage");

	// 左スイッチのモデル読み込み
	CModel* switchLModel = CResourceManager::Get<CModel>("Lswitch");

	// 右スイッチのモデル読み込み
	CModel* switchRModel = CResourceManager::Get<CModel>("Rswitch");

	//十字土台読み込み
	CModel* moveTenModel = CResourceManager::Get<CModel>("Tenfield");

	// I字土台読み込み
	CModel* moveIModel = CResourceManager::Get<CModel>("Ifield");

	// T字土台のモデル読み込み
	CModel* moveTModel = CResourceManager::Get<CModel>("Tfield");

	//J字土台のモデル読み込み
	CModel* moveJModel = CResourceManager::Get<CModel>("Jfield");

	//L字土台のモデル読み込み
	CModel* moveLModel = CResourceManager::Get<CModel>("Lfield");

	//普通の足場
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, -10.0f, 240.0f), CVector(5.0f, 4.0f, 0.5f));
	AddTask(floor);

	//クリア土台を作成
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, 0.0f, -70.0f), CVector(1.0f, 1.0f, 1.0f));
	AddTask(coin);

	//左スイッチを作成
	CSwitchLObject* switchl = new CSwitchLObject(switchLModel,
		CVector(-15.0f, -5.0f, 240.0f), CVector(10.0f, 10.0f, 10.0f));
	AddTask(switchl);

	//右スイッチを作成
	CSwitchRObject* switchr = new CSwitchRObject(switchRModel,
		CVector(15.0f, -5.0f, 240.0f), CVector(10.0f, 10.0f, 10.0f));
	AddTask(switchr);

	//十字土台を作成
	CMoveField* tenfield = new CMoveField(moveTenModel,
		CVector(0.0f, -5.0f, 10.0f), CVector(13.5f, 12.5f, 13.5f)
		,0.0f);
	AddTask(tenfield);

	//I字土台を作成
	CIMoveField* ifield = new CIMoveField(moveIModel,
		CVector(80.0f, -5.0f, 178.5f), CVector(13.5f, 12.5f, 13.5f)
		,0.0f);
	AddTask(ifield);

	//T字土台を作成
	CTMoveField* tfield = new CTMoveField(moveTModel,
		CVector(0.0f, -5.0f, 178.5f), CVector(13.5f, 12.5f, 13.5f)
		,0.0f);
	AddTask(tfield);
	tfield = new CTMoveField(moveTModel,
		CVector(80.0f, -5.0f, 100.0f), CVector(13.5f, 12.5f, 13.5f)
		, 0.0f);
	AddTask(tfield);
	tfield = new CTMoveField(moveTModel,
		CVector(-80.0f, -5.0f, 100.0f), CVector(13.5f, 12.5f, 13.5f)
		, 0.0f);
	AddTask(tfield);
	tfield = new CTMoveField(moveTModel,
		CVector(70.0f, -5.0f, -50.0f), CVector(13.5f, 12.5f, 13.5f)
		, 0.0f);
	AddTask(tfield);
	tfield = new CTMoveField(moveTModel,
		CVector(-70.0f, -5.0f, -50.0f), CVector(13.5f, 12.5f, 13.5f)
		, 0.0f);
	AddTask(tfield);

	//J字土台を作成
	CJMoveField* jfield = new CJMoveField(moveJModel,
		CVector(0.0f, -5.0f, 110.0f), CVector(13.5f, 12.5f, 13.5f)
		, 0.0f);
	AddTask(jfield);
	jfield = new CJMoveField(moveJModel,
		CVector(-80.0f, -5.0f, 20.0f), CVector(13.5f, 12.5f, 13.5f)
		, 0.0f);
	AddTask(jfield);

	//L字土台を作成
	CLMoveField* lfield = new CLMoveField(moveLModel,
		CVector(80.0f, -5.0f, 20.0f), CVector(13.5f, 12.5f, 13.5f)
		, 0.0f);
	AddTask(lfield);
	lfield = new CLMoveField(moveLModel,
		CVector(-80.0f, -5.0f, 178.5f), CVector(13.5f, 12.5f, 13.5f)
		, 0.0f);
	AddTask(lfield);

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
		CVector eye = playerPos + CVector(0.0f, 150.0f, 200.0f);
		CVector at = playerPos;
		CVector forward = (at - eye).Normalized();
		CVector side = CVector::Cross(forward, CVector::up);
		CVector up = CVector::Cross(side, forward);
		mainCamera->LookAt(eye, at, up);
		mainCamera->SetFollowTargetTf(player);
	}
}

//ステージ破棄
void CStage3::Unload()
{
	//ベースのステージ破棄処理
	CStageBase::Unload();
}