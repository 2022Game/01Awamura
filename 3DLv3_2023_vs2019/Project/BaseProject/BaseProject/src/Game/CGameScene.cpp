#include "CGameScene.h"
#include "CSceneManager.h"
#include "CField.h"
#include "CPlayer.h"
#include "CCamera.h"

//コンストラクタ
CGameScene::CGameScene()
	: CSceneBase(EScene::eGame)
{
}

//デストラクタ
CGameScene::~CGameScene()
{
}

//シーン読み込み
void CGameScene::Load()
{
	// 背景色設定
	System::SetClearColor(0.1921569f, 0.3019608f, 0.4745098f, 1.0f);

	//ここでゲーム中に必要な
	//リソースの読み込みやクラスの生成を行う

	new CField();

	CPlayer* player = new CPlayer();
	//player->Scale(1.0f, 1.0f, 1.0f);

	CCamera* mainCamera = new CCamera
	(
		//CVector(5.0f, -15.0f, 180.0f),
		CVector(0.0f, 50.0f, 75.0f),
		player->Position()
	);
	mainCamera->SetFollowTargetTf(player);
}

//シーンの更新処理
void CGameScene::Update()
{
}
