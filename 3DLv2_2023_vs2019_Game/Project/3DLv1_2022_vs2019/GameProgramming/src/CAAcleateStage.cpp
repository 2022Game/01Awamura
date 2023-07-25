//#include "CAAcleateStage.h"
//#include "CTaskManager.h"
//#include "CCollisionManager.h"
//#include "CColliderMesh.h"
//#include "CApplication.h"
//
//#include <stdlib.h>
//
//#include "time.h"
//
//int rand(void);
//void srand(unsigned int seed);
//
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
//
//CAAcleateStage::CAAcleateStage()
//	:randnow(0)
//	, randnow2(0)
//	, randnow3(0)
//	, randnow4(0)
//	, randnow5(0)
//	, randnow6(0)
//	, randnow7(0)
//	, randnow8(0)
//	, randnow9(0)
//	, randnow10(0)
//{
//	// 初期処理
//	Init();
//
//	// タスクマネージャーに自身を追加
//	CTaskManager::Instance()->Add(this);
//
//}
//
//CAAcleateStage::~CAAcleateStage()
//{
//	// コインのモデルデータを破棄
//	if (mpClearStageModel != nullptr)
//	{
//		delete mpClearStageModel;
//	}
//
//	// コインを破棄
//	for (int i = 0; i < mClearStages.size(); i++)
//	{
//		mClearStages[i]->Kill();
//	}
//	// 一応リストもクリアしておく
//	mClearStages.clear();
//
//	// ハマーのモデルデータを破棄
//	if (mpHamahModel != nullptr)
//	{
//		delete mpHamahModel;
//	}
//
//	// ハマーを破棄
//	for (int i = 0; i < mHamahs.size(); i++)
//	{
//		delete mHamahs[i];
//	}
//	// 一応リストもクリアしておく
//	mHamahs.clear();
//
//	// Soccerのモデルデータを破棄
//	if (mpSoccerModel != nullptr)
//	{
//		delete mpSoccerModel;
//	}
//
//	// Soccerを破棄
//	for (int i = 0; i < mSoccers.size(); i++)
//	{
//		delete mSoccers[i];
//	}
//	// 一応リストもクリアしておく
//	mSoccers.clear();
//
//	// ハマーのモデルデータを破棄
//	if (mpWallModel != nullptr)
//	{
//		delete mpWallModel;
//	}
//
//	// ハマーを破棄
//	for (int i = 0; i < mWalls.size(); i++)
//	{
//		delete mWalls[i];
//	}
//	// 一応リストもクリアしておく
//	mWalls.clear();
//
//	// 木のモデルデータを破棄
//	if (mpWoodModel != nullptr)
//	{
//		delete mpWoodModel;
//	}
//
//	// 木を破棄
//	for (int i = 0; i < mWoods.size(); i++)
//	{
//		delete mWoods[i];
//	}
//	// 一応リストもクリアしておく
//	mWoods.clear();
//
//	// コインのモデルデータを破棄
//	if (mpCoinModel != nullptr)
//	{
//		delete mpCoinModel;
//	}
//
//	// コインを破棄
//	for (int i = 0; i < mCoins.size(); i++)
//	{
//		delete mCoins[i];
//	}
//	// 一応リストもクリアしておく
//	mCoins.clear();
//
//	// タスクマネージャーから自身を取り除く
//	CTaskManager::Instance()->Remove(this);
//}
//
//void CAAcleateStage::Init()
//{
//	mpCoinModel = new CModel();
//	mpCoinModel->Load(MODEL_FCOIN);
//	CApplication::CleaCoin()->Load(MODEL_FCOIN);
//	CApplication::Wood()->Load(MODEL_FWOOD);
//	mpWallModel = new CModel();
//	mpWallModel->Load(MODEL_FWALL);
//	CApplication::Hamah()->Load(MODEL_FHAMAH);
//	CApplication::Soccer()->Load(MODEL_FSOCCER);
//}
//
//void CAAcleateStage::CreateSoccer(CVector& pos, CVector& rot, CVector& scale)
//{
//	if (mpSoccerModel == nullptr) return;
//
//	// 木を生成してリストに追加
//	CASoccer* soccer = new CASoccer(mpSoccerModel, pos, rot, scale);
//	mSoccers.push_back(soccer);
//}
//
//void CAAcleateStage::CreateWall(CVector& pos, CVector& rot, CVector& scale)
//{
//	if (mpWallModel == nullptr) return;
//
//	// ハマーを生成してリストに追加
//	CAWall* wall = new CAWall(mpWallModel, pos, rot, scale);
//	mWalls.push_back(wall);
//}
//
//void CAAcleateStage::CreateWood(CVector& pos, CVector& rot, CVector& scale)
//{
//	if (mpWoodModel == nullptr) return;
//
//	// 木を生成してリストに追加
//	CAWood* wood = new CAWood(mpWoodModel, pos, rot, scale);
//	mWoods.push_back(wood);
//}
//
//void CAAcleateStage::CreateHamah(CVector& pos, CVector& rot, CVector& scale)
//{
//	if (mpHamahModel == nullptr) return;
//
//	// ハマーを生成してリストに追加
//	CAHamah* hamah = new CAHamah(mpHamahModel, pos, rot, scale);
//	mHamahs.push_back(hamah);
//}
//
//void CAAcleateStage::CreateCoin(CVector& pos, CVector& rot, CVector& scale)
//{
//	if (mpCoinModel == nullptr) return;
//
//	// コインを生成してリストに追加
//	CACoin* coin = new CACoin(mpCoinModel, pos, rot, scale);
//	mCoins.push_back(coin);
//}
//
//void CAAcleateStage::ClearStage(CVector& pos, CVector& rot, CVector& scale)
//{
//	if (mpClearStageModel == nullptr) return;
//
//	// コインを生成してリストに追加
//	CACoinClearStage* coin = new CACoinClearStage(mpClearStageModel, pos, rot, scale);
//	mClearStages.push_back(coin);
//}
//
//void CAAcleateStage::Update()
//{
//	if (CApplication::StageCount == 0)
//	{
//		randnow = 3 + rand() % 17;
//		randnow2 = 3 + rand() % 17;
//		randnow3 = 3 + rand() % 17;
//		randnow4 = 3 + rand() % 17;
//		randnow5 = 3 + rand() % 17;
//		randnow6 = 3 + rand() % 17;
//	}
//	if (CApplication::StageCount == 1)
//	{
//		randnow = 3 + rand() % 17;
//		randnow2 = 3 + rand() % 17;
//		randnow3 = 3 + rand() % 17;
//		randnow4 = 3 + rand() % 17;
//		randnow5 = 3 + rand() % 17;
//		randnow6 = 3 + rand() % 17;
//	}
//	if (CApplication::StageCount == 2)
//	{
//		randnow = 3 + rand() % 17;
//		randnow2 = 3 + rand() % 17;
//		randnow3 = 3 + rand() % 17;
//		randnow4 = 3 + rand() % 17;
//		randnow5 = 3 + rand() % 17;
//		randnow6 = 3 + rand() % 17;
//	}
//
//	// コインを生成
//	//ステージ１
//	if (CApplication::StageCount == 0 && CApplication::Stage == 1)
//	{
//		CreateCoin(CVector(randnow, 0.1f, 6.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CreateCoin(CVector(randnow2, 0.1f, 13.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CreateCoin(CVector(randnow3, 0.1f, 20.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CreateCoin(CVector(randnow4, 0.1f, 27.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CreateCoin(CVector(randnow5, 0.1f, 34.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CreateCoin(CVector(randnow6, 0.1f, 41.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CApplication::Stage = 0;
//	}
//	////ステージ２
//	if (CApplication::StageCount == 1 && CApplication::Stage == 1)
//	{
//		CreateCoin(CVector(randnow, 0.1f, 56.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CreateCoin(CVector(randnow2, 0.1f, 63.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CreateCoin(CVector(randnow3, 0.1f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CreateCoin(CVector(randnow4, 0.1f, 77.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CreateCoin(CVector(randnow5, 0.1f, 84.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CreateCoin(CVector(randnow6, 0.1f, 91.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CApplication::Stage = 0;
//	}
//	////ステージ３
//	if (CApplication::StageCount == 2 && CApplication::Stage == 1)
//	{
//		CreateCoin(CVector(randnow, 0.1f, 106.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CreateCoin(CVector(randnow2, 0.1f, 113.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CreateCoin(CVector(randnow3, 0.1f, 120.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CreateCoin(CVector(randnow4, 0.1f, 127.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CreateCoin(CVector(randnow5, 0.1f, 134.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CreateCoin(CVector(randnow6, 0.1f, 141.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
//		CApplication::Stage = 0;
//	}
//	if (CApplication::StartCount == 1)
//	{
//		if (CApplication::StageGuard == 1)
//		{
//			CreateWall(CVector(10.0f, 22.9f, 2.5f), CVector(), CVector(1.8f, 5.8f, 2.8f));
//			CApplication::StageGuard = 0;
//		}
//	}
//	if (CApplication::SelectStage != 0)
//	{
//		if (CApplication::StageReset != 1)
//		{
//			if (mpCoinModel != nullptr)
//			{
//				delete mpCoinModel;
//				mpCoinModel = nullptr;
//				CApplication::StageCheck++;
//			}
//			/*if (mpHamahGimmick != nullptr)
//			{
//				delete mpHamahGimmick;
//			}
//			if (mpWoodGimmick != nullptr)
//			{
//				delete mpWoodGimmick;
//			}
//			if (mpWallGimmick != nullptr)
//			{
//				delete mpWallGimmick;
//			}
//			if (mpSoccerGimmick != nullptr)
//			{
//				delete mpSoccerGimmick;
//			}
//			if (mpClearStage != nullptr)
//			{
//				delete mpClearStage;
//			}*/
//			/*mpClearStage = nullptr;
//			mpCoinGimmick = nullptr;
//			mpSoccerGimmick = nullptr;
//			mpWallGimmick = nullptr;
//			mpHamahGimmick = nullptr;
//			mpWoodGimmick = nullptr;*/
//		}
//	}
//	//if (プレイヤーがコインに接地したら)
//	{
//		for (int i = 0; i < mCoins.size(); i++)
//		{
//			CACoin* coin = mCoins[i];
//			if (coin->SCount == 0)
//			{
//				coin->SCount = 1;
//			}
//		}
//	}
//}