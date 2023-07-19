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

int CApplication::StageReset = 0;

int CApplication::StageCountGuard = 0;

int CApplication::StageCheck = 0;

int CApplication::hcount = 0;

int CApplication::Rcount = 0;

void CApplication::Start()
{
	CSceneManager::Instance()->LoadScene(EScene::eTitle);
	spUi = new CUi(); //UIクラスの生成
}

void CApplication::Update()
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

	if (StageCount == 4)
	{
		if (mInput.Key(VK_RETURN))
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
			/*if (mpClearStage != nullptr)
			{
				delete mpClearStage;
			}*/
			mpCoinGimmick = nullptr;
			mpSoccerGimmick = nullptr;
			mpWallGimmick = nullptr;
			mpHamahGimmick = nullptr;
			mpWoodGimmick = nullptr;
			//mpClearStage = nullptr;
			SelectStage = 0;

			StageSwitch = 0;

			StageGuard = 0;

			StageCount = 0;

			StageReset = 0;

			StageCountGuard = 0;

			StageCheck = 0;

			hcount = 0;

			Ui()->Time(mTime = 0);
			Ui()->Restart(mRestart = 0);
			Rcount = 1;
		}
	}
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