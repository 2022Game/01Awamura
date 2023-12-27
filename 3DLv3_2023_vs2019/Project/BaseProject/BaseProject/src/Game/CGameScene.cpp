#include "CGameScene.h"
#include "CSceneManager.h"
#include "CField.h"
#include "CPlayer.h"
#include "CCamera.h"
#include "CField.h"
#include "Cinput.h"
#include "CStageManager.h"
#include "CGameManager.h"

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
	//CResourceManager::Load<CModel>("Field", "Field\\Dublesky3.obj");
	CResourceManager::Load<CModel>("Field", "Field\\Rainbowsky.obj");
	//CResourceManager::Load<CModel>("Field", "Field\\Object\\Clearrainbow.obj");

	//プレイヤー
	CResourceManager::Load<CModelX>("Player", "Character\\Player\\Beardman.x");
	
	//土台、障害物
	CResourceManager::Load<CModel>("Stone", "Field\\Stone.obj");  //岩
	CResourceManager::Load<CModel>("Ifield", "Field\\Object\\Ifield.obj"); //I字土台
	CResourceManager::Load<CModel>("Jfield", "Field\\Object\\Jfield.obj"); //J字土台
	CResourceManager::Load<CModel>("Lfield", "Field\\Object\\Lfield.obj"); //L字土台
	CResourceManager::Load<CModel>("Tenfield", "Field\\Object\\10field.obj"); //十字土台
	CResourceManager::Load<CModel>("Tfield", "Field\\Object\\Tfield.obj"); //T字土台
	CResourceManager::Load<CModel>("Axe", "Field\\ono7.obj"); //斧
	CResourceManager::Load<CModel>("Bollfield", "Field\\bollfield2.obj"); //円形土台
	CResourceManager::Load<CModel>("Clearcube", "Field\\Object\\Clearcube.obj"); //クリア四角土台
	CResourceManager::Load<CModel>("Clearstage", "Field\\Object\\cylinder.obj"); //クリア円形土台
	CResourceManager::Load<CModel>("Cube", "Field\\Object\\cube.obj"); //四角土台
	CResourceManager::Load<CModel>("Killwood", "Field\\Killwood.obj"); //大木
	CResourceManager::Load<CModel>("Sidewood", "Field\\Killbranc.obj"); //倒木
	CResourceManager::Load<CModel>("SideDownwood", "Field\\Killbranc2.obj"); //上下に動く倒木
	CResourceManager::Load<CModel>("Slope", "Field\\Object\\slopecube.obj"); //坂道
	CResourceManager::Load<CModel>("Lswitch", "Field\\Object\\switchBlue.obj"); //左スイッチ
	CResourceManager::Load<CModel>("Rswitch", "Field\\Object\\switchRed.obj"); //右スイッチ
	CResourceManager::Load<CModel>("Warp", "Field\\WarpDoor2.obj"); //ワープドア
	CResourceManager::Load<CModel>("Cleardelta", "Field\\Cleardelta.obj"); //三角クリア障害物
	CResourceManager::Load<CModel>("Needle", "Field\\Object\\needle.obj"); //針
	CResourceManager::Load<CModel>("Transparent", "Field\\Object\\transparent.obj"); //透明用土台
	CResourceManager::Load<CModel>("Cubecol", "Field\\Object\\cubecol.obj");

	CResourceManager::Load<CModel>("Rainbow12345", "Field\\Rainbow12345.obj");//テスト用

	CResourceManager::Load<CModel>("FieldCube", "Field\\Object\\cube.obj");
	CResourceManager::Load<CModel>("FieldCylinder", "Field\\Object\\cylinder.obj");

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

	//ゲーム開始処理
	CGameManager::GameStart();
}

//シーンの更新処理
void CGameScene::Update()
{
}
