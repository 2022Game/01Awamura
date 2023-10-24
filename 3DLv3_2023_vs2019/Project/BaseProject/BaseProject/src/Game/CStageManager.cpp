//#include "CStageManager.h"
//#include "CCollisionManager.h"
//#include "CMoveFloor.h"
//#include "CRotateFloor.h"
//#include "CClearStage.h"
//#include "CClearStageGimmick.h"
//
//int CStageManager::mClearCount1 = 0;
//int CStageManager::mStageCount1 = 0;
//int CStageManager::mClearCountSwitch1 = 0;
//int CStageManager::mStageReset1 = 0;
//
//CStageManager::CStageManager()
//{
//	////クリア床
//	//new CClearStage
//	//(
//	//	mpClearModel,
//	//	CVector(20.0f, 0.0f, -140.0f), CVector(5.5f, 5.0f, 5.25f)
//	//);
//	//new CClearStage
//	//(
//	//	mpClearModel,
//	//	CVector(60.0f, 0.0f, -140.0f), CVector(5.5f, 5.0f, 5.25f)
//	//);
//}
//
//CStageManager::~CStageManager()
//{
//
//}
//
//void CStageManager::Update()
//{
//	if (mClearCount1 == 1 && mClearCountSwitch1 == 1)
//	{
//		mStageCount1++;
//		if (mStageCount1 == 1)
//		{
//			mpClearStageGimmick = new CClearStageGimmick();
//			mClearCount1 = 0;
//			mClearCountSwitch1 = 0;
//			/*delete mpClearStageGimmick;
//			mpClearStageGimmick = nullptr;*/
//			//mpClearStageGimmick->Kill();
//		}
//		if (mStageCount1 == 2)
//		{
//			//mpClearStageGimmick->Kill();
//			//delete mpClearStageGimmick;
//			//mpClearStageGimmick = nullptr;
//			mpClearStageGimmick2 = new CClearStageGimmick();
//			mClearCount1 = 0;
//			mClearCountSwitch1 = 0;
//		}
//	}
//}




//以前まで作っていたやつ↓↓





//#include "CStageManager.h"
//
//void CStageManager::Update()
//{
//	if (mpClearStage != nullptr)
//	{
//		delete mpClearStage;
//		mpClearStage = nullptr;
//	}
//	if (StartCount == 1)
//	{
//		if (SelectStage != 0)
//		{
//			if (StageReset != 1)
//			{
//				if (mpCoinGimmick != nullptr)
//				{
//					delete mpCoinGimmick;
//					StageCheck++;
//				}
//				if (mpHamahGimmick != nullptr)
//				{
//					delete mpHamahGimmick;
//				}
//				if (mpWoodGimmick != nullptr)
//				{
//					delete mpWoodGimmick;
//				}
//				/*if (mpWallGimmick != nullptr)
//				{
//					delete mpWallGimmick;
//				}*/
//				if (mpSoccerGimmick != nullptr)
//				{
//					delete mpSoccerGimmick;
//				}
//				if (mpClearStage != nullptr)
//				{
//					delete mpClearStage;
//				}
//				mpClearStage = nullptr;
//				mpCoinGimmick = nullptr;
//				mpSoccerGimmick = nullptr;
//				//mpWallGimmick = nullptr;
//				mpHamahGimmick = nullptr;
//				mpWoodGimmick = nullptr;
//			}
//		}
//		if (StageReset == 1)
//		{
//			if (StageCount == 0)
//			{
//				if (mpClearStage2 != nullptr)
//				{
//					delete mpClearStage2;
//					mpClearStage2 = nullptr;
//				}
//			}
//			if (StageCount == 1)
//			{
//				if (mpClearStage2 == nullptr)
//				{
//					if (mpClearStage3 != nullptr)
//					{
//						delete mpClearStage3;
//						mpClearStage3 = nullptr;
//					}
//					mpClearStage2 = new CAClearStage();
//					StageDelete = 1;
//				}
//			}
//			if (StageCount == 2)
//			{
//				if (mpClearStage3 == nullptr)
//				{
//					if (mpClearStage4 != nullptr)
//					{
//						delete mpClearStage4;
//						mpClearStage4 = nullptr;
//					}
//					mpClearStage3 = new CAClearStage();
//					StageDelete = 1;
//				}
//			}
//			if (StageCount == 3)
//			{
//				if (mpClearStage4 == nullptr)
//				{
//					mpClearStage4 = new CAClearStage();
//					StageDelete = 1;
//				}
//			}
//			StageSwitch = 1;
//			StageReset = 0;
//		}
//		if (StageGuard == 1)
//		{
//			if (StageDelete == 2)
//			{
//				if (mpClearStage2 != nullptr)
//				{
//					delete mpClearStage2;
//					mpClearStage2 = nullptr;
//				}
//				if (mpClearStage3 != nullptr)
//				{
//					delete mpClearStage3;
//					mpClearStage3 = nullptr;
//				}
//				if (mpClearStage4 != nullptr)
//				{
//					delete mpClearStage4;
//					mpClearStage4 = nullptr;
//				}
//			}
//			StageGuard = 0;
//		}
//		if (StageCount == 0)
//		{
//			if (mpWallGimmick == nullptr)
//			{
//				mpWallGimmick = new CAWallGimmick();
//			}
//		}
//		if (StageCount == 1)
//		{
//			if (mpClearStage2 == nullptr)
//			{
//				mpClearStage2 = new CAClearStage();
//				StageDelete = 1;
//			}
//		}
//		if (StageCount == 2)
//		{
//			if (mpClearStage3 == nullptr)
//			{
//				mpClearStage3 = new CAClearStage();
//				StageDelete = 1;
//			}
//		}
//		if (StageCount == 3)
//		{
//			if (mpClearStage4 == nullptr)
//			{
//				mpClearStage4 = new CAClearStage();
//				StageDelete = 1;
//			}
//		}
//		if (StageClearDelete == 3)
//		{
//			if (mpClearStage2 != nullptr)
//			{
//				delete mpClearStage2;
//			}
//			mpClearStage2 = nullptr;
//		}
//		if (StageClearDelete == 4)
//		{
//			if (mpClearStage3 != nullptr)
//			{
//				delete mpClearStage3;
//			}
//			mpClearStage3 = nullptr;
//		}
//		if (SelectStage == 1)
//		{
//			//ランダムで１ならハマーステージ予定
//			mpCoinGimmick = new CACoinGimmick();
//			mpHamahGimmick = new CAHamahGimmick();
//			SelectStage = 0; //テスト用
//		}
//		if (SelectStage == 2)
//		{
//			//ランダムで2ならウッドステージ予定
//			mpCoinGimmick = new CACoinGimmick();
//			mpWoodGimmick = new CAWoodGimmick();
//			hcount = 1;
//			SelectStage = 0; //テスト用
//		}
//		if (SelectStage == 3)
//		{
//			//ランダムで3ならSoccerステージ予定
//			mpCoinGimmick = new CACoinGimmick();
//			mpSoccerGimmick = new CASoccerGimmick();
//			hcount = 8;
//			SelectStage = 0; //テスト用
//		}
//		if (SelectStage == 4)
//		{
//			//ランダムで４ならハマーステージ予定
//			mpCoinGimmick = new CACoinGimmick();
//			mpHamahGimmick = new CAHamahGimmick();
//			SelectStage = 0; //テスト用
//		}
//		if (SelectStage == 5)
//		{
//			//ランダムで5ならSoccerステージ予定
//			mpCoinGimmick = new CACoinGimmick();
//			mpSoccerGimmick = new CASoccerGimmick();
//			hcount = 7;
//			SelectStage = 0; //テスト用
//		}
//		if (SelectStage == 6)
//		{
//			//ランダムで６ならウッドステージ予定
//			mpCoinGimmick = new CACoinGimmick();
//			mpWoodGimmick = new CAWoodGimmick();
//			hcount = 3;
//			SelectStage = 0; //テスト用
//		}
//		if (StageCount == 4)
//		{
//			if (mInput.Key(VK_SPACE))
//			{
//				CSceneManager::Instance()->LoadScene(EScene::eTitle);
//				if (mpCoinGimmick != nullptr)
//				{
//					delete mpCoinGimmick;
//					StageCheck++;
//				}
//				if (mpHamahGimmick != nullptr)
//				{
//					delete mpHamahGimmick;
//				}
//				if (mpWoodGimmick != nullptr)
//				{
//					delete mpWoodGimmick;
//				}
//				if (mpWallGimmick != nullptr)
//				{
//					delete mpWallGimmick;
//				}
//				if (mpSoccerGimmick != nullptr)
//				{
//					delete mpSoccerGimmick;
//				}
//				if (mpClearStage4 != nullptr)
//				{
//					delete mpClearStage4;
//				}
//				if (mpClearStage3 != nullptr)
//				{
//					delete mpClearStage3;
//				}
//				if (mpClearStage2 != nullptr)
//				{
//					delete mpClearStage2;
//				}
//				if (mpGameScene != nullptr)
//				{
//					delete mpGameScene;
//				}
//				mpCoinGimmick = nullptr;
//				mpSoccerGimmick = nullptr;
//				mpWallGimmick = nullptr;
//				mpHamahGimmick = nullptr;
//				mpWoodGimmick = nullptr;
//				mpClearStage2 = nullptr;
//				mpClearStage3 = nullptr;
//				mpClearStage4 = nullptr;
//				mpGameScene = nullptr;
//				SelectStage = 0;
//
//				StageSwitch = 0;
//
//				StageGuard = 0;
//
//				StageCount = 0;
//
//				StageReset = 0;
//
//				StageCountGuard = 0;
//
//				StageCheck = 0;
//
//				StageClearDelete = 0;
//
//				//StageTime = 0;
//
//				StartCount = 0;
//
//				hcount = 0;
//
//				Ui()->Time(mTime = 0);
//				Ui()->Restart(mRestart = 0);
//				Rcount = 1;
//				reset = 1;
//			}
//		}
//	}
//}