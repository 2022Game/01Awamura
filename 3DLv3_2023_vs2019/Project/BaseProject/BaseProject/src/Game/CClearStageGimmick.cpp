#include "CClearStageGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

////クリア土台
//#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"

//int rand(void);
//void srand(unsigned int seed);

CClearStageGimmick::CClearStageGimmick()
{
	//srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CClearStageGimmick::~CClearStageGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mClearStage.size(); i++)
	{
		mClearStage[i]->Kill();
		//delete mClearStage[i];
	}
	// 一応リストもクリアしておく
	mClearStage.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CClearStageGimmick::Init()
{
	// クリア土台のモデル読み込み
	mpClearStageModel = new CModel();
	mpClearStageModel->Load("Field\\Object\\Coin2.obj", "Field\\Object\\Coin2.mtl");

	// クリア判定用の土台を生成
	//ステージ１
	if (CField::mStageCount == 1 && CField::mStageCreateSwitch == 1)
	{
		CreateClearStage(mpClearStageModel,
		CVector(0.0f, 5.0f, -20.0f),  CVector(5.5f, 5.0f, 5.25f));
	}
	//ステージ２
	if (CField::mStageCount == 2 && CField::mStageCreateSwitch == 1)
	{
		CreateClearStage(mpClearStageModel,
		CVector(0.0f, 0.0f, -20.0f), CVector(5.5f, 5.0f, 5.25f));
	}
	//ステージ3
	if (CField::mStageCount == 3 && CField::mStageCreateSwitch == 1)
	{
		CreateClearStage(mpClearStageModel,
			CVector(0.0f, 0.0f, -20.0f), CVector(5.5f, 5.0f, 5.25f));
	}
	//ステージ4
	if (CField::mStageCount == 4 && CField::mStageCreateSwitch == 1)
	{
		CreateClearStage(mpClearStageModel,
			CVector(20.0f, 0.0f, -390.0f), CVector(5.5f, 5.0f, 5.25f));
	}
	//ステージ5
	if (CField::mStageCount == 5 && CField::mStageCreateSwitch == 1)
	{
		CreateClearStage(mpClearStageModel,
			CVector(20.0f, 0.0f, -440.0f), CVector(5.5f, 5.0f, 5.25f));
	}
}

void CClearStageGimmick::CreateClearStage(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpClearStageModel == nullptr) return;

	// クリア土台を生成してリストに追加
	CClearStage* coin = new CClearStage(mpClearStageModel, pos, scale);
	mClearStage.push_back(coin);
}

void CClearStageGimmick::Update()
{

}