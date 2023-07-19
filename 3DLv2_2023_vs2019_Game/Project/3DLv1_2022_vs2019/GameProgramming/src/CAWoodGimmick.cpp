#include "CAWoodGimmick.h"
#include "CTaskManager.h"
#include "CApplication.h"
#include <stdlib.h>
#include "time.h"

//伝説の木
#define MODEL_FWOOD "res\\WWWW.obj","res\\WWWW.mtl"

int rand(void);
void srand(unsigned int seed);

CAWoodGimmick::CAWoodGimmick()
	:randnow(0)
	, randnow2(0)
	, randnow3(0)
	, randnow4(0)
	, randnow5(0)
	, randnow6(0)
	, randnow7(0)
	, randnow8(0)
	, randnow9(0)
	, randnow10(0)
	, randnow11(0)
	, randnow12(0)
	, randnow13(0)
	, randnow14(0)
	, randnow15(0)
{
	srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	CTaskManager::Instance()->Add(this);
}

CAWoodGimmick::~CAWoodGimmick()
{
	// 木のモデルデータを破棄
	if (mpWoodModel != nullptr)
	{
		delete mpWoodModel;
	}

	// 木を破棄
	for (int i = 0; i < mWoods.size(); i++)
	{
		delete mWoods[i];
	}
	// 一応リストもクリアしておく
	mWoods.clear();

	// タスクマネージャーから自身を取り除く
	CTaskManager::Instance()->Remove(this);
}

void CAWoodGimmick::Init()
{
	// 木のモデル読み込み
	mpWoodModel = new CModel();
	mpWoodModel->Load(MODEL_FWOOD);

	if (CApplication::StageCount == 0)
	{
		randnow = 4 + rand() % 17;
		randnow2 = 4 + rand() % 17;
		randnow3 = 4 + rand() % 17;
		randnow4 = 4 + rand() % 17;
		randnow5 = 4 + rand() % 17;
		randnow6 = 4 + rand() % 17;
		randnow7 = 4 + rand() % 17;
		randnow8 = 4 + rand() % 17;
		randnow9 = 4 + rand() % 17;
		randnow10 = 4 + rand() % 17;
		randnow11 = 4 + rand() % 17;
		randnow12 = 4 + rand() % 17;
		randnow13 = 4 + rand() % 17;
		randnow14 = 4 + rand() % 17;
		randnow15 = 4 + rand() % 17;
	}
	if (CApplication::StageCount == 1)
	{
		randnow = 4 + rand() % 17;
		randnow2 = 4 + rand() % 17;
		randnow3 = 4 + rand() % 17;
		randnow4 = 4 + rand() % 17;
		randnow5 = 4 + rand() % 17;
		randnow6 = 4 + rand() % 17;
		randnow7 = 4 + rand() % 17;
		randnow8 = 4 + rand() % 17;
		randnow9 = 4 + rand() % 17;
		randnow10 = 4 + rand() % 17;
		randnow11 = 4 + rand() % 17;
		randnow12 = 4 + rand() % 17;
		randnow13 = 4 + rand() % 17;
		randnow14 = 4 + rand() % 17;
		randnow15 = 4 + rand() % 17;
	}
	if (CApplication::StageCount == 2)
	{
		randnow = 4 + rand() % 17;
		randnow2 = 4 + rand() % 17;
		randnow3 = 4 + rand() % 17;
		randnow4 = 4 + rand() % 17;
		randnow5 = 4 + rand() % 17;
		randnow6 = 4 + rand() % 17;
		randnow7 = 4 + rand() % 17;
		randnow8 = 4 + rand() % 17;
		randnow9 = 4 + rand() % 17;
		randnow10 = 4 + rand() % 17;
		randnow11 = 4 + rand() % 17;
		randnow12 = 4 + rand() % 17;
		randnow13 = 4 + rand() % 17;
		randnow14 = 4 + rand() % 17;
		randnow15 = 4 + rand() % 17;
	}

	// 木を生成
	if (CApplication::SelectStage == 2)
	{
		if (CApplication::StageCount == 0)
		{
			CreateWood(CVector(randnow, 22.9f, 7.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow2, 22.9f, 9.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow3, 22.9f, 12.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow4, 22.9f, 14.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow5, 22.9f, 17.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow6, 22.9f, 19.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow7, 22.9f, 22.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow8, 22.9f, 24.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow9, 22.9f, 27.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow10, 22.9f, 29.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow11, 22.9f, 32.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow12, 22.9f, 34.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow13, 22.9f, 37.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow14, 22.9f, 39.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow15, 22.9f, 42.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CApplication::StageCount == 1)
		{
			CreateWood(CVector(randnow, 22.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow2, 22.9f, 59.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow3, 22.9f, 62.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow4, 22.9f, 64.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow5, 22.9f, 67.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow6, 22.9f, 69.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow7, 22.9f, 72.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow8, 22.9f, 74.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow9, 22.9f, 77.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow10, 22.9f, 79.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow11, 22.9f, 82.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow12, 22.9f, 84.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow13, 22.9f, 87.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow14, 22.9f, 89.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow15, 22.9f, 92.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CApplication::StageCount == 2)
		{
			CreateWood(CVector(randnow, 22.9f, 107.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow2, 22.9f, 109.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow3, 22.9f, 112.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow4, 22.9f, 114.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow5, 22.9f, 117.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow6, 22.9f, 119.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow7, 22.9f, 122.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow8, 22.9f, 124.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow9, 22.9f, 127.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow10, 22.9f, 129.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow11, 22.9f, 132.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow12, 22.9f, 134.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow13, 22.9f, 137.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow14, 22.9f, 139.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow15, 22.9f, 142.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
	}
	if (CApplication::SelectStage == 3)
	{
		if (CApplication::StageCount == 0)
		{
			CreateWood(CVector(randnow, 22.9f, 7.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow2, 22.9f, 15.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow3, 22.9f, 23.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow4, 22.9f, 31.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow5, 22.9f, 39.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow6, 22.9f, 7.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow7, 22.9f, 15.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow8, 22.9f, 23.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow9, 22.9f, 31.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow10, 22.9f, 39.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow11, 22.9f, 7.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow12, 22.9f, 15.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow13, 22.9f, 23.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow14, 22.9f, 31.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow15, 22.9f, 39.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CApplication::StageCount == 1)
		{
			CreateWood(CVector(randnow, 22.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow2, 22.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow3, 22.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow4, 22.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow5, 22.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow6, 22.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow7, 22.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow8, 22.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow9, 22.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow10, 22.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow11, 22.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow12, 22.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow13, 22.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow14, 22.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow15, 22.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CApplication::StageCount == 2)
		{
			CreateWood(CVector(randnow, 22.9f, 107.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow2, 22.9f, 115.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow3, 22.9f, 123.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow4, 22.9f, 131.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow5, 22.9f, 139.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow6, 22.9f, 107.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow7, 22.9f, 115.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow8, 22.9f, 123.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow9, 22.9f, 131.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow10, 22.9f, 139.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow11, 22.9f, 107.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow12, 22.9f, 115.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow13, 22.9f, 123.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow14, 22.9f, 131.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(randnow15, 22.9f, 139.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
	}
}

void CAWoodGimmick::CreateWood(CVector& pos, CVector& rot, CVector& scale)
{
	if (mpWoodModel == nullptr) return;

	// 木を生成してリストに追加
	CAWood* wood = new CAWood(mpWoodModel, pos, rot, scale);
	mWoods.push_back(wood);
}

void CAWoodGimmick::Update()
{
}