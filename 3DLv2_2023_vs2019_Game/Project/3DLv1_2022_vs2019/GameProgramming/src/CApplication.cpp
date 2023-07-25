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

CModel CApplication::mCoin;
CModel CApplication::mCleaCoin;
CModel CApplication::mWood;
CModel CApplication::mWall;
CModel CApplication::mHamah;
CModel CApplication::mSoccer;

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
CModel* CApplication::Coin()
{
	return &mCoin;
}

CModel* CApplication::Hamah()
{
	return &mHamah;
}

CModel* CApplication::CleaCoin()
{
	return &mCleaCoin;
}

CModel* CApplication::Wood()
{
	return &mWood;
}

CModel* CApplication::Wall()
{
	return &mWall;
}

CModel* CApplication::Soccer()
{
	return &mSoccer;
}

CMatrix CApplication::mModelViewInverse;

const CMatrix& CApplication::ModelViewInverse()
{
	return mModelViewInverse;
}

int CApplication::SelectStage = 0;

int CApplication::StageSwitch = 0;

int CApplication::StartCount = 0;

int CApplication::StageGuard = 0;

int CApplication::StageCount = 0;

int CApplication::StageReset = 0;

int CApplication::StageCountGuard = 0;

int CApplication::StageCheck = 0;

int CApplication::StageTime = 0;

int CApplication::StageClearDelete = 0;

int CApplication::hcount = 0;

int CApplication::Rcount = 0;

int CApplication::reset = 0;

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

//伝説の木
#define MODEL_FWOOD "res\\WWWW.obj","res\\WWWW.mtl"

CApplication::CApplication()
	:mpClearStage(nullptr)
	,mpCoinGimmick(nullptr)
	,mpWallGimmick(nullptr)
	,mpWoodGimmick(nullptr)
	,mpHamahGimmick(nullptr)
	,mpSoccerGimmick(nullptr)
	,mpGameScene(nullptr)
{

}

void CApplication::Start()
{
	/*if (mpClearStage == nullptr)
	{
		mpClearStage = new CAClearStage();
	}*/
	CApplication::Coin()->Load(MODEL_FCOIN);
	CApplication::CleaCoin()->Load(MODEL_FCOIN);
	CApplication::Wood()->Load(MODEL_FWOOD);
	CApplication::Wall()->Load(MODEL_FWALL);
	CApplication::Hamah()->Load(MODEL_FHAMAH);
	CApplication::Soccer()->Load(MODEL_FSOCCER);
	CSceneManager::Instance()->LoadScene(EScene::eTitle);
	mpGameScene = new CGameScene();
	spUi = new CUi(); //UIクラスの生成
}

void CApplication::Update()
{
	if (mpClearStage != nullptr)
	{
		delete mpClearStage;
		mpClearStage = nullptr;
	}
	if (StartCount == 1)

	{
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
			if (StageReset != 1)
			{
				if (mpCoinGimmick != nullptr)
				{
					delete mpCoinGimmick;
					StageCheck++;
				}
				if (mpHamahGimmick != nullptr)
				{
					delete mpHamahGimmick;
				}
				if (mpWoodGimmick != nullptr)
				{
					delete mpWoodGimmick;
				}
				if (mpWallGimmick != nullptr)
				{
					delete mpWallGimmick;
				}
				if (mpSoccerGimmick != nullptr)
				{
					delete mpSoccerGimmick;
				}
				if (mpClearStage != nullptr)
				{
					delete mpClearStage;
				}
				mpClearStage = nullptr;
				mpCoinGimmick = nullptr;
				mpSoccerGimmick = nullptr;
				mpWallGimmick = nullptr;
				mpHamahGimmick = nullptr;
				mpWoodGimmick = nullptr;
			}
		}
		if (StageReset == 1)
		{
			if (mpWallGimmick != nullptr)
			{
				delete mpWallGimmick;
			}
			mpWallGimmick = nullptr;
			StageSwitch = 1;
			StageReset = 0;
		}
		if (StageGuard == 1)
		{
			mpWallGimmick = new CAWallGimmick();
			StageGuard = 0;
		}
		if (StageCount == 1)
		{
			if (mpClearStage2 == nullptr)
			{
				mpClearStage2 = new CAClearStage();
			}
		}
		if (StageCount == 2)
		{
			if (mpClearStage3 == nullptr)
			{
				mpClearStage3 = new CAClearStage();
			}
		}
		if (StageCount == 3)
		{
			if (mpClearStage4 == nullptr)
			{
				mpClearStage4 = new CAClearStage();
			}
		}
		if (StageClearDelete == 3)
		{
			if (mpClearStage2 != nullptr)
			{
				delete mpClearStage2;
			}
			mpClearStage2 = nullptr;
		}
		if (StageClearDelete == 4)
		{
			if (mpClearStage3 != nullptr)
			{
				delete mpClearStage3;
			}
			mpClearStage3 = nullptr;
		}
		if (SelectStage == 1)
		{
			//ランダムで１ならハマーステージ予定
			//mpClearStage = new CAClearStage();
			mpCoinGimmick = new CACoinGimmick();
			mpHamahGimmick = new CAHamahGimmick();
			SelectStage = 0; //テスト用
		}
		if (SelectStage == 2)
		{
			//ランダムで2ならウッドステージ予定
			//mpClearStage = new CAClearStage();
			mpCoinGimmick = new CACoinGimmick();
			mpWoodGimmick = new CAWoodGimmick();
			hcount = 1;
			SelectStage = 0; //テスト用
		}
		if (SelectStage == 3)
		{
			//ランダムで１ならハマーステージ予定
			//mpClearStage = new CAClearStage();
			mpCoinGimmick = new CACoinGimmick();
			mpWoodGimmick = new CAWoodGimmick();
			hcount = 2;
			SelectStage = 0; //テスト用
		}
		if (SelectStage == 4)
		{
			//ランダムで１ならハマーステージ予定
			//mpClearStage = new CAClearStage();
			mpCoinGimmick = new CACoinGimmick();
			mpHamahGimmick = new CAHamahGimmick();
			SelectStage = 0; //テスト用
		}
		if (SelectStage == 5)
		{
			//ランダムで5ならステージ予定
			//mpClearStage = new CAClearStage();
			mpCoinGimmick = new CACoinGimmick();
			mpSoccerGimmick = new CASoccerGimmick();
			hcount = 7;
			SelectStage = 0; //テスト用
		}
		if (SelectStage == 6)
		{
			//ランダムで5ならステージ予定
			//mpClearStage = new CAClearStage();
			mpCoinGimmick = new CACoinGimmick();
			mpWoodGimmick = new CAWoodGimmick();
			hcount = 3;
			SelectStage = 0; //テスト用
		}
		if (SelectStage == 7)
		{
			//ランダムで5ならステージ予定
			//mpClearStage = new CAClearStage();
			mpCoinGimmick = new CACoinGimmick();
			mpSoccerGimmick = new CASoccerGimmick();
			hcount = 8;
			SelectStage = 0; //テスト用
		}
		if (StageCount == 4)
		{
			if (mInput.Key(VK_SPACE))
			{
				CSceneManager::Instance()->LoadScene(EScene::eTitle);
				if (mpCoinGimmick != nullptr)
				{
					delete mpCoinGimmick;
					StageCheck++;
				}
				if (mpHamahGimmick != nullptr)
				{
					delete mpHamahGimmick;
				}
				if (mpWoodGimmick != nullptr)
				{
					delete mpWoodGimmick;
				}
				if (mpWallGimmick != nullptr)
				{
					delete mpWallGimmick;
				}
				if (mpSoccerGimmick != nullptr)
				{
					delete mpSoccerGimmick;
				}
				if (mpClearStage4 != nullptr)
				{
					delete mpClearStage4;
				}
				if (mpClearStage3 != nullptr)
				{
					delete mpClearStage3;
				}
				if (mpClearStage2 != nullptr)
				{
					delete mpClearStage2;
				}
				if (mpGameScene != nullptr)
				{
					delete mpGameScene;
				}
				mpCoinGimmick = nullptr;
				mpSoccerGimmick = nullptr;
				mpWallGimmick = nullptr;
				mpHamahGimmick = nullptr;
				mpWoodGimmick = nullptr;
				mpClearStage2 = nullptr;
				mpClearStage3 = nullptr;
				mpClearStage4 = nullptr;
				mpGameScene = nullptr;
				SelectStage = 0;

				StageSwitch = 0;

				StageGuard = 0;

				StageCount = 0;

				StageReset = 0;

				StageCountGuard = 0;

				StageCheck = 0;

				StageClearDelete = 0;

				//StageTime = 0;

				hcount = 0;

				Ui()->Time(mTime = 0);
				Ui()->Restart(mRestart = 0);
				Rcount = 1;
				reset = 1;
			}
		}
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

	/*if (mInput.PushKey('P'))
	{
		if (mpClearStage2 != nullptr)
		{
			delete mpClearStage2;
			mpClearStage = nullptr;
		}
	}*/

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