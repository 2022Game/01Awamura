#include "CAWoodGimmick.h"
#include "CTaskManager.h"
#include "CApplication.h"

//伝説の木
#define MODEL_FWOOD "res\\WWWW.obj","res\\WWWW.mtl"

CAWoodGimmick::CAWoodGimmick()
{
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

	// 木を生成
	if (CApplication::SelectStage == 2)
	{
		if (CApplication::StageCount == 0)
		{
			CreateWood(CVector(4.0f, 22.9f, 7.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 15.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 23.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 31.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 39.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 7.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 15.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 23.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 31.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 39.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 7.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 15.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 23.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 31.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 39.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CApplication::StageCount == 1)
		{
			CreateWood(CVector(4.0f, 22.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CApplication::StageCount == 2)
		{
			CreateWood(CVector(4.0f, 22.9f, 107.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 115.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 123.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 131.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 139.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 107.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 115.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 123.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 131.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 139.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 107.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 115.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 123.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 131.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 139.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
	}
	if (CApplication::SelectStage == 3)
	{
		if (CApplication::StageCount == 0)
		{
			CreateWood(CVector(4.0f, 22.9f, 7.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 15.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 23.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 31.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 39.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 7.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 15.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 23.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 31.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 39.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 7.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 15.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 23.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 31.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 39.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CApplication::StageCount == 1)
		{
			CreateWood(CVector(4.0f, 22.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CApplication::StageCount == 2)
		{
			CreateWood(CVector(4.0f, 22.9f, 107.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 115.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 123.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 131.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 139.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 107.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 115.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 123.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 131.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 139.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 107.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 115.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 123.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 131.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 139.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
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