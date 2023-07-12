#include "CApplication.h"
#include "CRectangle.h"
//OpenGL
#include "glut.h"
#include "CVector.h"
#include "CTriangle.h"
#include "CTransform.h"
#include "CCollisionManager.h"
#include "CCharacter.h"
#include "GamePause.h"
#include "CSceneManager.h"

//クラスのstatic変数
CTexture CApplication::mTexture;
CCharacterManager CApplication::mCharacterManager;

//#define SOUND_BGM "res\\mario.wav" //BGM音声ファイル
//#define SOUND_OVER "res\\mdai.wav" //ゲームオーバー音声ファイル
////背景モデルデータの指定
//#define MODEL_BACKGROUND "res\\sky.obj","res\\sky.mtl"
////敵輸送機モデル
//#define MODEL_C5 "res\\f14.obj","res\\f14.mtl"
////土台Coin
//#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"
////ハンマーリンゴ
//#define MODEL_FHAMAH "res\\apple2.obj","res\\apple2.mtl"

//CTaskManager CApplication::mTaskManager;
//CTaskManager* CApplication::TaskManager()
//{
//	return &mTaskManager;
//}

CCharacterManager* CApplication::CharacterManager()
{
	return &mCharacterManager;
}

CTexture* CApplication::Texture()
{
	return &mTexture;
}

CMatrix CApplication::mModelViewInverse;

const CMatrix& CApplication::ModelViewInverse()
{
	return mModelViewInverse;
}

int CApplication::SelectStage = 0;

int CApplication::StageSwitch = 0;

int CApplication::StageGuard = 0;

int CApplication::StageCount = 0;

int CApplication::hcount = 0;

void CApplication::Start()
{
	CSceneManager::Instance()->LoadScene(EScene::eTitle);
	//SelectStage = 0;
	/*new CEnemy3(CVector(-5.0f, 1.0f, -10.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));
	new CEnemy3(CVector(5.0f, 1.0f, -10.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));*/
	spUi = new CUi(); //UIクラスの生成
	//C5モデルの読み込み
	//mModelC5.Load(MODEL_C5);
	//敵機のインスタンス作成
	/*new CEnemy(&mModelC5, CVector(0.0f, 10.0f, -100.0f),
		CVector(), CVector(0.1f, 0.1f, 0.1f));
	new CEnemy(&mModelC5, CVector(30.0f, 10.0f, -130.0f),
		CVector(), CVector(0.1f, 0.1f, 0.1f));*/
	//mEye = CVector(1.0f, 2.0f, 3.0f);
	//モデルファイルの入力
	//mModel.Load(MODEL_OBJ);
	//mBackGround.Load(MODEL_BACKGROUND);
	////mModelCoin.Load(MODEL_FCOIN);
	//mModelHamah.Load(MODEL_FHAMAH);
	///*CMatrix matrix;
	//matrix.Print();*/

	////// コインギミックはCACoinGimmick内にまとめる
	////mpCoinGimmick = new CACoinGimmick();

	//////ランダムでAならハマーを出す（予定）
	////mpHamahGimmick = new CAHamahGimmick();

	////ランダムでBなら移動床を出す。
	//
	////	mCharacter.Model(&mModel);
	//	//mCharacter.Scale(CVector(0.1f, 0.1f, 0.1f));
	////ビルボードの生成
	///*new CBillBoard(CVector(-6.0f, 3.0f, -10.0f), 1.0f, 1.0f);*/
	//////三角コライダの確認
	//mColliderLine.Set(nullptr, nullptr
	//	, CVector(24.0f, 24.0f, -50.0f)
	//	, CVector(24.0f, 24.0f, 300.0f));
	//mColliderLine.Layer(CCollider::ELayer::ELINEWALL);

	//mColliderLine2.Set(nullptr, nullptr
	//	, CVector(0.0f, 24.0f, -50.0f)
	//	, CVector(0.0f, 24.0f, 300.0f));
	//mColliderLine2.Layer(CCollider::ELayer::ELINEWALL);

	//mColliderLine3.Set(nullptr, nullptr
	//	, CVector(24.0f, 22.5f, -50.0f)
	//	, CVector(24.0f, 22.5f, 300.0f));
	//mColliderLine3.Layer(CCollider::ELayer::ELINEWALL);

	//mColliderLine4.Set(nullptr, nullptr
	//	, CVector(0.0f, 22.5f, -50.0f)
	//	, CVector(0.0f, 22.5f, 300.0f));
	//mColliderLine4.Layer(CCollider::ELayer::ELINEWALL);

	//mColliderLine5.Set(nullptr, nullptr
	//	, CVector(24.0f, 25.5f, -50.0f)
	//	, CVector(24.0f, 25.5f, 300.0f));
	//mColliderLine5.Layer(CCollider::ELayer::ELINEWALL);

	//mColliderLine6.Set(nullptr, nullptr
	//	, CVector(0.0f, 25.5f, -50.0f)
	//	, CVector(0.0f, 25.5f, 300.0f));
	//mColliderLine6.Layer(CCollider::ELayer::ELINEWALL);

	//mColliderLine7.Set(nullptr, nullptr
	//	, CVector(0.0f, 24.0f, -10.0f)
	//	, CVector(24.0f, 24.0f,-10.0f));
	//mColliderLine7.Layer(CCollider::ELayer::ELINEWALL);

	///*mColliderLine8.Set(nullptr, nullptr
	//	, CVector(0.0f, 28.5f, -10.0f)
	//	, CVector(0.0f, 28.5f, 10.0f));
	//mColliderLine8.Layer(CCollider::ELayer::ELINEWALL);*/
	////mColliderLine9.Set(nullptr, nullptr
	////	, CVector(24.0f, 23.5f, -50.0f)
	////	, CVector(24.0f, 23.5f, 300.0f));
	////mColliderLine9.Layer(CCollider::ELayer::ELINEWALL);

	////mColliderLine10.Set(nullptr, nullptr
	////	, CVector(0.0f, 23.5f, -50.0f)
	////	, CVector(0.0f, 23.5f, 300.0f));
	////mColliderLine10.Layer(CCollider::ELayer::ELINEWALL);*/

	//mColliderTriangle2.Set(nullptr, nullptr
	//	, CVector(-300.0f, 0.0f, -300.0f)
	//	, CVector(-300.0f, 0.0f, 300.0f)
	//	, CVector(300.0f, 0.0f, -300.0f));
	//mColliderTriangle2.Layer(CCollider::ELayer::EDEATH); 

	//mColliderTriangle3.Set(nullptr, nullptr
	//	, CVector(300.0f, 0.0f, 300.0f)
	//	, CVector(300.0f, 0.0f, -300.0f)
	//	, CVector(-300.0f, 0.0f, 300.0f));
	//mColliderTriangle3.Layer(CCollider::ELayer::EDEATH);
	////背景モデルから三角コライダを生成
	////親インスタンスと親行列はなし
	//mColliderMesh.Set(nullptr, nullptr, &mBackGround);
	////mColliderMesh.Set(nullptr, nullptr, &mModelCoin);
	////mpCoinGimmick = new CACoinGimmick();
	//mpClearStage = new CAClearStage();
	////mpHamahGimmick = new CAHamahGimmick();
	////mpClearStage = new CAClearStage();
	//mpPlayer = new CPlayer();
	//mpPlayer->Model(&mModel);
	//mpPlayer->Position(CVector(10.0f, 1.0f, 0.0f));
	//mpPlayer->Scale(CVector(0.5f, 0.5f, 0.5f));
	//mpPlayer->Rotation(CVector(0.0f, 0.0f, 0.0f));
}

void CApplication::Update()
{
	if (CPlayer::CountLine == 1)
	{
		mColliderLine8.Set(nullptr, nullptr
			, CVector(0.0f, 24.0f, 30.0f)
			, CVector(24.0f, 24.0f, 30.0f));
		mColliderLine8.Layer(CCollider::ELayer::ELINEWALL);
		CPlayer::CountLine = 0;
	}

	if (CASoccer::hdhd == 2)
	{
		mpSoccerGimmick = new CASoccerGimmick();
	}
	/*switch (mState)
	{
	case EState::ECLEAR:
	{
		mpUi->Clear();
	}
	break;
	case EState::EOVER:
	{
		mpUi->Over();
	}
	break;
	}*/
	
	if (SelectStage != 0)
	{
		delete mpCoinGimmick;
		mpCoinGimmick = nullptr;
		delete mpHamahGimmick;
		delete mpWoodGimmick;
		delete mpWallGimmick;
		delete mpSoccerGimmick;
		mpSoccerGimmick = nullptr;
		mpWallGimmick = nullptr;
		mpHamahGimmick = nullptr;
		mpWoodGimmick = nullptr;
	}
	if (StageGuard == 1)
	{
		mpWallGimmick = new CAWallGimmick();
		StageGuard = 0;
	}
	if (SelectStage == 1)
	{
		//ランダムで１ならハマーステージ予定
		mpClearStage = new CAClearStage();
		mpCoinGimmick = new CACoinGimmick();
		mpHamahGimmick = new CAHamahGimmick();
		SelectStage = 0; //テスト用
	}
	if (SelectStage == 2)
	{
		//ランダムで2ならウッドステージ予定
		mpClearStage = new CAClearStage();
		mpCoinGimmick = new CACoinGimmick();
		mpWoodGimmick = new CAWoodGimmick();
		hcount = 1;
		SelectStage = 0; //テスト用
	}
	if (SelectStage == 3)
	{
		//ランダムで１ならハマーステージ予定
		mpClearStage = new CAClearStage();
		mpCoinGimmick = new CACoinGimmick();
		mpWoodGimmick = new CAWoodGimmick();
		hcount = 2;
		SelectStage = 0; //テスト用
	}
	if (SelectStage == 4)
	{
		//ランダムで１ならハマーステージ予定
		mpClearStage = new CAClearStage();
		mpCoinGimmick = new CACoinGimmick();
		mpHamahGimmick = new CAHamahGimmick();
		SelectStage = 0; //テスト用
	}
	if (SelectStage == 5)
	{
		//ランダムで5ならステージ予定
		mpClearStage = new CAClearStage();
		mpCoinGimmick = new CACoinGimmick();
		mpSoccerGimmick = new CASoccerGimmick();
		SelectStage = 0; //テスト用
	}
	//if (SelectStage != 3 && SelectStage != 0)
	//{
	//	delete mpCoinGimmick;
	//	mpCoinGimmick = nullptr;
	//	/*delete mpHamahGimmick;
	//	mpHamahGimmick = nullptr;*/
	//}
	//タスクマネージャの更新
	CTaskManager::Instance()->Update();
	CTaskManager::Instance()->Collision();
	////頂点１,頂点2,頂点3,法線のデータの作成
	//CVector v0, v1, v2, n;
	////法線を上向きで設定する
	//n.Set(0.0f, 1.0f, 0.0f);
	////頂点1の座標を設定する
	//v0.Set(0.0f, 0.0f, 0.5f);
	////頂点２の座標を設定する
	//v1.Set(1.0f, 0.0f, 0.0f);
	////頂点３の座標を設定する
	//v2.Set(0.0f, 0.0f, -0.5f);

	/*if (mInput.Key('J'))
	{
		mEye = mEye - CVector(0.1f, 0.0f, 0.0f);
	}
	if (mInput.Key('L'))
	{
		mEye = mEye + CVector(0.1f, 0.0f, 0.0f);
	}
	if (mInput.Key('I'))
	{
		mEye = mEye - CVector(0.0f, 0.0f, 0.1f);
	}
	if (mInput.Key('K'))
	{
		mEye = mEye + CVector(0.0f, 0.0f, 0.1f);
	}
	if (mInput.Key('O'))
	{
		mEye = mEye + CVector(0.0f, 1.0f, 0.0f);
	}
	if (mInput.Key('M'))
	{
		mEye = mEye - CVector(0.0f, 1.0f, 0.0f);
	}*/

	//視点の設定
	//gluLookAt(視点Ｘ,視点Ｙ,視点Ｚ,中心X,中心Y,中心Z,上向X,上向Y,上向Z）
	//gluLookAt(mEye.X(),mEye.Y(),mEye.Z(), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	//mCharacter.Update();
	//mCharacter.Render();
	//mPlayer.Update();
	////カメラのパラメータを作成する
	//CVector e, c, u;//視点、注視点、上方向
	////視点を求める
	//e = mpPlayer->Position() + (CVector(-0.2f, 1.0f, -3.0f)) * mpPlayer->MatrixRotate();
	////注視点を求める
	//c = mpPlayer->Position();
	////上方向を求める
	//u = (CVector(0.0f, 1.0f, 0.0f)) * mpPlayer->MatrixRotate();
	////カメラの設定
	//gluLookAt(e.X(), e.Y(), e.Z(), c.X(), c.Y(), c.Z(), u.X(), u.Y(), u.Z());
	//シーンマネージャーの更新
	CSceneManager::Instance()->Update();
	//モデルビューの行列の取得
	glGetFloatv(GL_MODELVIEW_MATRIX, mModelViewInverse.M());
	//逆行列の取得
	mModelViewInverse = mModelViewInverse.Transpose();
	mModelViewInverse.M(0, 3, 0);
	mModelViewInverse.M(1, 3, 0);
	mModelViewInverse.M(2, 3, 0);
	//mPlayer.Render(); 
	//CTransform trans; //変換行列インスタンスの作成
	//trans.Position(CVector(0.5f, 1.8f, 0.5f)); //位置の作成
	//trans.Rotation(CVector(-10.0f, -20.0f, -30.0f)); //回転の設定
	//trans.Scale(CVector(0.1f, 0.1f, 0.1f)); //拡大縮小の設定
	//trans.Update(); //行列の更新
	//mModel.Render(trans.Matrix());//モデルの描画
	//mBackGround.Render();
	//タスクリストの削除
	CTaskManager::Instance()->Delete();
	//タスクマネージャの描画
	CTaskManager::Instance()->Render();
	//子リジョンマネージャの衝突処理
	// 削除　CCollisionManager::Instance()->Collision();

	//コリジョンマネジャー描画
	CCollisionManager::Instance()->Render();
	spUi->Render(); //UIの描画
}

CUi* CApplication::spUi = nullptr;

CUi* CApplication::Ui()
{
	return spUi; //インスタンスのポインタを返す
}

CApplication::~CApplication()
{
	delete spUi; //インスタンスUiの削除
}