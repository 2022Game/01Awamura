#include "CStage4.h"
#include "CClearStage.h"
#include "CKillwood.h"
#include "CSidewood.h"
#include "CSideDownwood.h"
#include "CBollField.h"
#include "CCleardelta.h"
#include "CPlayer.h"
#include "CCamera.h"

//コンストラクタ
CStage4::CStage4()
{
	mStageNo = 4;
}

//デストラクタ
CStage4::~CStage4()
{

}

//ステージ読み込み
void CStage4::Load()
{
	// クリア土台のモデル読み込み
	CModel* clearStageModel = CResourceManager::Get<CModel>("Clearstage");

	//大木のモデル読み込み
	CModel* killwoodModel = CResourceManager::Get<CModel>("Killwood");

	//倒木のモデル読み込み
	CModel* sidewoodModel = CResourceManager::Get<CModel>("Sidewood");

	////倒木のモデル読み込み
	CModel* sidedownwoodModel = CResourceManager::Get<CModel>("SideDownwood");

	//円形土台のモデル読み込み
	CModel* bollFieldModel = CResourceManager::Get<CModel>("Rainbow12345");
	//テスト中！！！！！！！！！！！！！！！！！！！！！！！！！！！！

	//とんがりコーン土台のモデル読み込み
	CModel* deltaModel = CResourceManager::Get<CModel>("Cleardelta");

	//クリア土台を作成
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, -5.0f, -30.0f), CVector(0.5f, 0.5f, 0.5f));
	AddTask(coin);

	//大木を作成
	CKillwood* killwood = new CKillwood(killwoodModel,
		CVector(0.0f, 0.0f, -30.0f), CVector(4.5f, 5.0f, 4.5f)
		,0.0f);
	AddTask(killwood);

	//倒木を作成
	CSidewood* sidewood = new CSidewood(sidewoodModel,
		CVector(0.0f, 5.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f)
		,0.0f);
	AddTask(sidewood);
	/*sidewood = new CSidewood(sidewoodModel,
		CVector(0.0f, 5.0f, -30.0f), CVector(5.5f, 5.0f, 5.0f)
		, 0.0f);
	AddTask(sidewood);*/

	//落下する倒木を作成
	CSideDownwood* sidedownwood = new CSideDownwood(sidewoodModel,
		CVector(0.0f, 120.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f)
		, 0.0f);
	AddTask(sidedownwood);
	sidedownwood = new CSideDownwood(sidewoodModel,
		CVector(0.0f, 150.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f)
		, 0.0f);
	AddTask(sidedownwood);


	//円形土台を作成
	CBollField* bollField = new CBollField(bollFieldModel,
		CVector(0.0f, -20.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f));
	AddTask(bollField);

	//とんがり土台を作成
	CCleardelta* cleardelta = new CCleardelta (deltaModel,
		CVector(0.0f,500.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f));
	AddTask(cleardelta);

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
void CStage4::Unload()
{
	//ベースのステージ破棄処理
	CStageBase::Unload();
}