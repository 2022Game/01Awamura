#include "CFloorGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CFloorGimmick::CFloorGimmick()
{
	//srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CFloorGimmick::~CFloorGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mFloor.size(); i++)
	{
		mFloor[i]->Kill();
	}
	// 一応リストもクリアしておく
	mFloor.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CFloorGimmick::Init()
{
	// クリア土台のモデル読み込み
	mpFloorModel = new CModel();
	mpFloorModel->Load("Field\\Object\\cube.obj", "Field\\Object\\cube.mtl");

	// ワープの土台を生成
	//ステージ0
	if (CField::mStageCount == 0)
	{
		CreateFloor(mpFloorModel,
			CVector(0.0f, 2.0f, -20.0f), CVector(0.5f, 4.0f, 5.0f));
	}
	if (CField::mStageCount == 1)
	{
		CreateFloor(mpFloorModel,
			CVector(0.0f, 2.0f, -20.0f), CVector(0.5f, 4.0f, 5.0f));
	}
	if (CField::mStageCount == 2)
	{
		CreateFloor(mpFloorModel,
			CVector(0.0f, -10.0f, 0.0f), CVector(5.0f, 4.0f, 1.0f));
	}
	if (CField::mStageCount == 3)
	{
		CreateFloor(mpFloorModel,
			CVector(0.0f, -10.0f, 240.0f), CVector(5.0f, 4.0f, 0.5f));
	}
	if (CField::mStageCount == 4)
	{
		CreateFloor(mpFloorModel,
			CVector(0.0f, 2.0f, -20.0f), CVector(0.5f, 4.0f, 5.0f));
	}
}

void CFloorGimmick::CreateFloor(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpFloorModel == nullptr) return;

	// クリア土台を生成してリストに追加
	CFloor* warp = new CFloor(mpFloorModel, pos, scale);
	mFloor.push_back(warp);
}

void CFloorGimmick::Update()
{

}