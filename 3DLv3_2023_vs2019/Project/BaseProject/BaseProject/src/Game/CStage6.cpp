#include "CStage6.h"
#include "CClearStage.h"
#include "CPlayer.h"
#include "CFloor.h"
#include "CMoveField.h"
#include "CCamera.h"
#include "CClearCube.h"
#include "CGameManager.h"

//コンストラクタ
CStage6::CStage6()
{
	mStageNo = 6;

	CVector2 pos = CVector2(0.0f, 0.0f);
	CVector2 size = CVector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	ETextAlignH textAlignH = ETextAlignH::eCenter;
	std::string text = "回転土台ステージ\n土台を渡り抜けろ";

	//テキストの影
	mpTextShadow = new CText
	(
		nullptr, 24,
		pos + CVector2(2.0f, 2.0f),
		size,
		CColor(0.0f, 0.0f, 0.0f),
		ETaskPriority::eTextShadow
	);

	mpTextShadow->SetTextAlignH(textAlignH);
	mpTextShadow->SetText(text.c_str());
	AddTask(mpTextShadow);

	//テキスト本体
	mpText = new CText
	(
		nullptr, 24,
		pos, size,
		CColor(1.0f, 1.0f, 1.0f),
		ETaskPriority::eText
	);
	mpText->SetTextAlignH(textAlignH);
	mpText->SetText(text.c_str());
	AddTask(mpText);
}

//デストラクタ
CStage6::~CStage6()
{

}

//ステージ読み込み
void CStage6::Load()
{
	//普通の足場読み込み
	CModel* floorModel = CResourceManager::Get<CModel>("FieldCube");

	//十字土台読み込み
	CModel* moveTenModel = CResourceManager::Get<CModel>("Tenfield");

	//十字土台読み込み
	CModel* moveTenPurpleModel = CResourceManager::Get<CModel>("TenfieldPurple");

	//十字土台読み込み
	CModel* moveTenSkyblueModel = CResourceManager::Get<CModel>("TenfieldSkyblue");

	//十字土台読み込み
	CModel* moveTenYellowModel = CResourceManager::Get<CModel>("TenfieldYellow");

	// クリア土台のモデル読み込み
	CModel* clearCubeStageModel = CResourceManager::Get<CModel>("Clearcube");

	//普通の足場
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f,-10.0f, 240.0f), CVector(5.0f, 4.0f, 0.5f));
	AddTask(floor);

	//十字土台を作成
	CMoveField* tenfield = new CMoveField(moveTenModel,
		CVector(0.0f, -5.0f, 182.5f), CVector(12.5f, 12.5f, 12.5f)
		, 0.0f);
	AddTask(tenfield);

	tenfield = new CMoveField(moveTenPurpleModel,
		CVector(0.0f, -6.0f, 122.5f), CVector(12.5f, 12.5f, 12.5f)
		, 0.0f);
	AddTask(tenfield);

	tenfield = new CMoveField(moveTenSkyblueModel,
		CVector(0.0f, -7.0f, 62.5f), CVector(12.5f, 12.5f, 12.5f)
		, 0.0f);
	AddTask(tenfield);

	tenfield = new CMoveField(moveTenYellowModel,
		CVector(0.0f, -8.0f, 2.5f), CVector(12.5f, 12.5f, 12.5f)
		, 0.0f);
	AddTask(tenfield);

	//クリア土台を作成
	CClearCube* coin = new CClearCube(clearCubeStageModel,
		CVector(0.0f, -7.0f, -62.0f), CVector(5.0f, 1.0f, 1.0f));
	AddTask(coin);

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
		CVector eye = playerPos + CVector(0.0f, 50.0f, 100.0f);
		CVector at = playerPos;
		CVector forward = (at - eye).Normalized();
		CVector side = CVector::Cross(forward, CVector::up);
		CVector up = CVector::Cross(side, forward);
		mainCamera->LookAt(eye, at, up);
		mainCamera->SetFollowTargetTf(player);
	}
}

//ステージ破棄
void CStage6::Unload()
{
	//ベースのステージ破棄処理
	CStageBase::Unload();
}