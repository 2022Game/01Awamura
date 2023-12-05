#include "CClearCubeGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

////クリア土台
//#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"

//int rand(void);
//void srand(unsigned int seed);

CClearCubeGimmick::CClearCubeGimmick()
{
	//srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CClearCubeGimmick::~CClearCubeGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mClearCube.size(); i++)
	{
		mClearCube[i]->Kill();
		//delete mClearCube[i];
	}
	// 一応リストもクリアしておく
	mClearCube.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CClearCubeGimmick::Init()
{
	// クリア土台のモデル読み込み
	mpClearCubeStageModel = new CModel();
	mpClearCubeStageModel->Load("Field\\Object\\Clearcube.obj", "Field\\Object\\Clearcube.mtl");

	// クリア判定用の土台を生成
	//ステージ１
	if (CField::mStageCount == 2 && CField::mStageCreateSwitch == 1)
	{
	
	}
}

void CClearCubeGimmick::CreateClearCubeStage(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpClearCubeStageModel == nullptr) return;

	// クリア土台を生成してリストに追加
	CClearCube* coin = new CClearCube(mpClearCubeStageModel, pos, scale);
	mClearCube.push_back(coin);
}

void CClearCubeGimmick::Update()
{

}