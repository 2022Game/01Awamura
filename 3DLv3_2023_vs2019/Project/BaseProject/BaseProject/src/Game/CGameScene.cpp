#include "CGameScene.h"
#include "CSceneManager.h"
#include "CField.h"
#include "CPlayer.h"
#include "CCamera.h"
#include "CField.h"
#include "Cinput.h"
//#include "CLineEffect.h"

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

	//背景
	CResourceManager::Load<CModel>("Field", "Field\\Dublesky4.obj");

	//プレイヤー
	CResourceManager::Load<CModelX>("Player", "Character\\Player\\Beardman.x");
	
	//土台、障害物
	CResourceManager::Load<CModel>("Stone", "Field\\Stone.obj");
	CResourceManager::Load<CModel>("Ifield", "Field\\Object\\Ifield.obj");
	CResourceManager::Load<CModel>("Jfield", "Field\\Object\\Jfield.obj");
	CResourceManager::Load<CModel>("Lfield", "Field\\Object\\Lfield.obj");
	CResourceManager::Load<CModel>("Tenfield", "Field\\Object\\10field.obj");
	CResourceManager::Load<CModel>("Tfield", "Field\\Object\\Tfield.obj");
	CResourceManager::Load<CModel>("Axe", "Field\\ono7.obj");
	CResourceManager::Load<CModel>("Bollfield", "Field\\bollfield.obj");
	CResourceManager::Load<CModel>("Clearcube", "Field\\Object\\Clearcube.obj");
	CResourceManager::Load<CModel>("Clearstage", "Field\\Object\\cylinder.obj");
	CResourceManager::Load<CModel>("Cube", "Field\\Object\\cube.obj");
	CResourceManager::Load<CModel>("Killwood", "Field\\Killwood.obj");
	CResourceManager::Load<CModel>("Sidewood", "Field\\Killbranc.obj");
	CResourceManager::Load<CModel>("Slope", "Field\\Object\\slopecube.obj");
	CResourceManager::Load<CModel>("Lswitch", "Field\\Object\\switchBlue.obj");
	CResourceManager::Load<CModel>("Rswitch", "Field\\Object\\switchRed.obj");
	CResourceManager::Load<CModel>("Warp", "Field\\WarpDoor2.obj");

	CResourceManager::Load<CModel>("FieldCube", "Field\\Object\\cube.obj");
	CResourceManager::Load<CModel>("FieldCylinder", "Field\\Object\\cylinder.obj");
	CResourceManager::Load<CModelX>("Player", "Character\\Player\\player.x");

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

	//CLineEffect* le = new CLineEffect(ETag::eNone);
	//le->AddPoint(CVector(0.0f, 10.0f, 10.0f), 1.0f);
	//le->AddPoint(CVector(10.0f, 10.0f, 10.0f), 1.0f);
	//le->AddPoint(CVector(10.0f, 20.0f, 50.0f), 1.0f);
	//le->AddPoint(CVector(50.0f, 10.0f, 50.0f), 1.0f);
}

//シーンの更新処理
void CGameScene::Update()
{
}
