#include "CGameScene.h"
#include "CField.h"
#include "CPlayer.h"
#include "CSceneManager.h"
#include "CApplication.h"

//背景モデルデータの指定
#define MODEL_BACKGROUND "res\\sky.obj","res\\sky.mtl"

//土台Coin
#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"

//ハンマーリンゴ
#define MODEL_FHAMAH "res\\apple2.obj","res\\apple2.mtl"

//伝説のボール
#define MODEL_FSOCCER "res\\soccer1.obj","res\\soccer1.mtl"

//神聖なる木
#define MODEL_FWALL "res\\Wall2.obj","res\\Wall2.mtl"

//コンストラクタ
CGameScene::CGameScene()
	:CSceneBase(EScene::eTitle)
	,mpWallGimmick(0)
	,mpSoccerGimmick(0)
	,mpCoinGimmick(0)
	,mpClearStage(0)
	,mpWoodGimmick(0)
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

	//プレイヤー生成
	CPlayer* player = new CPlayer();
	player->Position(CVector(10.0f, 1.0f, 0.0f));
	player->Scale(CVector(0.5f, 0.5f, 0.5f));
	player->Rotation(CVector(0.0f, 0.0f, 0.0f));

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

	mColliderLine7.Set(nullptr, nullptr
		, CVector(0.0f, 24.0f, -10.0f)
		, CVector(24.0f, 24.0f, -10.0f));
	mColliderLine7.Layer(CCollider::ELayer::ELINEWALL);

	/*mColliderLine8.Set(nullptr, nullptr
		, CVector(0.0f, 28.5f, -10.0f)
		, CVector(0.0f, 28.5f, 10.0f));
	mColliderLine8.Layer(CCollider::ELayer::ELINEWALL);*/
	//mColliderLine9.Set(nullptr, nullptr
	//	, CVector(24.0f, 23.5f, -50.0f)
	//	, CVector(24.0f, 23.5f, 300.0f));
	//mColliderLine9.Layer(CCollider::ELayer::ELINEWALL);

	//mColliderLine10.Set(nullptr, nullptr
	//	, CVector(0.0f, 23.5f, -50.0f)
	//	, CVector(0.0f, 23.5f, 300.0f));
	//mColliderLine10.Layer(CCollider::ELayer::ELINEWALL);*/

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
	//背景モデルから三角コライダを生成
	//親インスタンスと親行列はなし
	//mColliderMesh.Set(nullptr, nullptr, &mBackGround);
	//mColliderMesh.Set(nullptr, nullptr, &mModelCoin);
	//mpCoinGimmick = new CACoinGimmick();
	mpClearStage = new CAClearStage();
	//mpHamahGimmick = new CAHamahGimmick();
	//mpClearStage = new CAClearStage();
}

//シーンの更新処理
void CGameScene::Update()
{
	//プレイヤーが存在しなければ、処理しない
	CPlayer* player = CPlayer::Instance();
	if (player == nullptr)return;

	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//視点を求める
	e = player->Position() + (CVector(-0.2f, 1.0f, -3.0f)) * player->MatrixRotate();
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

	if (player->IsClear())
	{
		CSceneManager::Instance()->LoadScene(EScene::eClear);
	}
}