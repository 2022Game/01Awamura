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
	spUi = new CUi(); //UIクラスの生成
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

	//タスクマネージャの更新
	CTaskManager::Instance()->Update();
	CTaskManager::Instance()->Collision();

	//シーンマネージャーの更新
	CSceneManager::Instance()->Update();
	//モデルビューの行列の取得
	glGetFloatv(GL_MODELVIEW_MATRIX, mModelViewInverse.M());
	//逆行列の取得
	mModelViewInverse = mModelViewInverse.Transpose();
	mModelViewInverse.M(0, 3, 0);
	mModelViewInverse.M(1, 3, 0);
	mModelViewInverse.M(2, 3, 0);
	//タスクリストの削除
	CTaskManager::Instance()->Delete();
	//タスクマネージャの描画
	CTaskManager::Instance()->Render();

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