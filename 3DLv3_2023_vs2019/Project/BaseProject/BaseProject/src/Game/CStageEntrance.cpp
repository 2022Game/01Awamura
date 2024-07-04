#include "CStageEntrance.h"
#include "CFloor.h"
#include "CWarp.h"
#include "CPlayer.h"
#include "CCamera.h"

//コンストラクタ
CStageEntrance::CStageEntrance()
{
	mStageNo = 0;
	if (CGameManager::StageClearCount() >= 8)
	{
		CVector2 pos = CVector2(0.0f, 0.0f);
		CVector2 size = CVector2(WINDOW_WIDTH, WINDOW_HEIGHT);
		ETextAlignH textAlignH = ETextAlignH::eCenter;
		std::string text = "GameClear\nおはよ";

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
	else
	{
		CVector2 pos = CVector2(0.0f, 0.0f);
		CVector2 size = CVector2(WINDOW_WIDTH, WINDOW_HEIGHT);
		ETextAlignH textAlignH = ETextAlignH::eCenter;
		std::string text = "エントランスステージ\nおはよ";

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
}

//デストラクタ
CStageEntrance::~CStageEntrance()
{

}

//ステージ読み込み
void CStageEntrance::Load()
{
	// 普通の土台のモデル読み込み
	CModel* floorModel = CResourceManager::Get<CModel>("FieldCube");

	//ワープ扉の読み込み
	CModel* warpModel = CResourceManager::Get<CModel>("Warp");

	//普通の足場
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, 2.0f, -20.0f), CVector(0.5f, 4.0f, 5.0f));
	AddTask(floor);

	//ワープ扉を作成
	CWarp* warp = new CWarp(warpModel,
		CVector(0.0f, 10.0f, -20.0f), CVector(6.0f, 3.0f, 10.0f));
	AddTask(warp);

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
void CStageEntrance::Unload()
{
	//ベースのステージ破棄処理
	CStageBase::Unload();
}