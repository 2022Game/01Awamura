#include "CGameScene.h"
#include "CField.h"
#include "CPlayer.h"
#include "CSceneManager.h"
#include "CApplication.h"

////背景モデルデータの指定
//#define MODEL_BACKGROUND "res\\sky.obj","res\\sky.mtl"
//
////土台Coin
//#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"
//
////ハンマーリンゴ
//#define MODEL_FHAMAH "res\\apple2.obj","res\\apple2.mtl"
//
////伝説のボール
//#define MODEL_FSOCCER "res\\soccer1.obj","res\\soccer1.mtl"
//
////神聖なる木
//#define MODEL_FWALL "res\\Wall2.obj","res\\Wall2.mtl"
//
////伝説の木
//#define MODEL_FWOOD "res\\WWWW.obj","res\\WWWW.mtl"

//コンストラクタ
CGameScene::CGameScene()
	:CSceneBase(EScene::eTitle)
	,mpWallGimmick(nullptr)
	,mpSoccerGimmick(nullptr)
	,mpCoinGimmick(nullptr)
	,mpClearStage(nullptr)
	,mpWoodGimmick(nullptr)
	,player(nullptr)
{

}

//デストラクタ
CGameScene::~CGameScene()
{
}

//シーン読み込み
void CGameScene::Load()
{
	//ここでタイトル画面に必要な
	//リソースの読み込みやクラスの生成を行う

	//背景生成
	AddTask(new CField());
	/*if (CApplication::reset == 1)
	{
		if (player == nullptr)
		{
			delete player;
		}
	}*/
	////プレイヤー生成
	//CApplication::Coin()->Load(MODEL_FCOIN);
	//CApplication::CleaCoin()->Load(MODEL_FCOIN);
	//CApplication::Wood()->Load(MODEL_FWOOD);
	//CApplication::Wall()->Load(MODEL_FWALL);
	//CApplication::Hamah()->Load(MODEL_FHAMAH);
	//CApplication::Soccer()->Load(MODEL_FSOCCER);
	player = new CPlayer();
	player->Position(CVector(10.0f, 1.0f, 0.0f));
	player->Scale(CVector(0.5f, 0.5f, 0.5f));
	player->Rotation(CVector(0.0f, 0.0f, 0.0f));
	AddTask(player);
	//// コインギミックはCACoinGimmick内にまとめる
	//mpCoinGimmick = new CACoinGimmick();

	////ランダムでAならハマーを出す（予定）
	//mpHamahGimmick = new CAHamahGimmick();

	////三角コライダの確認
	mColliderLine.Set(nullptr, nullptr
		, CVector(24.0f, 24.0f, -50.0f)
		, CVector(24.0f, 24.0f, 300.0f));
	mColliderLine.Layer(CCollider::ELayer::ELINEWALL);

	mColliderLine2.Set(nullptr, nullptr
		, CVector(0.0f, 24.0f, -50.0f)
		, CVector(0.0f, 24.0f, 300.0f));
	mColliderLine2.Layer(CCollider::ELayer::ELINEWALL);

	mColliderLine3.Set(nullptr, nullptr
		, CVector(24.0f, 22.5f, -50.0f)
		, CVector(24.0f, 22.5f, 300.0f));
	mColliderLine3.Layer(CCollider::ELayer::ELINEWALL);

	mColliderLine4.Set(nullptr, nullptr
		, CVector(0.0f, 22.5f, -50.0f)
		, CVector(0.0f, 22.5f, 300.0f));
	mColliderLine4.Layer(CCollider::ELayer::ELINEWALL);

	mColliderLine5.Set(nullptr, nullptr
		, CVector(24.0f, 25.5f, -50.0f)
		, CVector(24.0f, 25.5f, 300.0f));
	mColliderLine5.Layer(CCollider::ELayer::ELINEWALL);

	mColliderLine6.Set(nullptr, nullptr
		, CVector(0.0f, 25.5f, -50.0f)
		, CVector(0.0f, 25.5f, 300.0f));
	mColliderLine6.Layer(CCollider::ELayer::ELINEWALL);

	mColliderTriangle2.Set(nullptr, nullptr
		, CVector(-300.0f, 0.0f, -300.0f)
		, CVector(-300.0f, 0.0f, 300.0f)
		, CVector(300.0f, 0.0f, -300.0f));
	mColliderTriangle2.Layer(CCollider::ELayer::EDEATH);

	mColliderTriangle3.Set(nullptr, nullptr
		, CVector(300.0f, 0.0f, 300.0f)
		, CVector(300.0f, 0.0f, -300.0f)
		, CVector(-300.0f, 0.0f, 300.0f));
	mColliderTriangle3.Layer(CCollider::ELayer::EDEATH);
	mpClearStage = new CAClearStage();
	AddTask(mpClearStage);
}

//シーンの更新処理
void CGameScene::Update()
{
	if (CApplication::StageReset == 1)
	{
		if (CApplication::StageCount == 0)
		{
			if (mpClearStage == nullptr)
			{
				mpClearStage = new CAClearStage();
				CApplication::StageDelete = 1;
			}
		}
	}
	if (CApplication::StageGuard == 1)
	{
		if (CApplication::StageDelete == 2)
		{
			if (mpClearStage != nullptr)
			{
				delete mpClearStage;
				mpClearStage = nullptr;
			}
		}
		CApplication::StageGuard = 0;
	}
	if (CApplication::StageClearDelete == 2)
	{
		if (mpClearStage != nullptr)
		{
			delete mpClearStage;
		}
		mpClearStage = nullptr;
	}
	//プレイヤーが存在しなければ、処理しない
	CPlayer* player = CPlayer::Instance();
	if (player == nullptr)return;

	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//視点を求める
	e = player->Position() + (CVector(0.0f, 3.0f, -5.0f)) * player->MatrixRotate();
	//注視点を求める
	c = player->Position();
	//上方向を求める
	u = (CVector(0.0f, 1.0f, 0.0f)) * player->MatrixRotate();
	//カメラの設定
	gluLookAt(e.X(), e.Y(), e.Z(), c.X(), c.Y(), c.Z(), u.X(), u.Y(), u.Z());

	////ゲームオーバーシーン
	//if (player->IsDeath())
	//{
	//	CSceneManager::Instance()->LoadScene(EScene::eTitle);
	//}

	//mColliderLine9 = nullptr;

	if (player->IsClear())
	{
		CSceneManager::Instance()->LoadScene(EScene::eClear);
	}
}