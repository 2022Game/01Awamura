#include "CWarpGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//床
#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"

//int rand(void);
//void srand(unsigned int seed);

CWarpGimmick::CWarpGimmick()
{
	//srand((unsigned int)time(NULL));
	// 初期処理
	Init();
}

CWarpGimmick::~CWarpGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mWarp.size(); i++)
	{
		mWarp[i]->Kill();
	}
	// 一応リストもクリアしておく
	mWarp.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CWarpGimmick::Init()
{
	// クリア土台のモデル読み込み
	mpWarpModel = new CModel();
	mpWarpModel->Load("Field\\Object\\cube.obj", "Field\\Object\\cube.mtl");

	// ワープの土台を生成
	//ステージ0
	if (CField::mStageCount == 0)
	{
		CreateWarp(mpWarpModel,
			CVector(0.0f, 20.0f, -100.0f), CVector(0.5f, 8.0f, -0.5f));
	}
}

void CWarpGimmick::CreateWarp(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpWarpModel == nullptr) return;

	// クリア土台を生成してリストに追加
	CWarp* warp = new CWarp(mpWarpModel, pos, scale);
	mWarp.push_back(warp);
}

void CWarpGimmick::Update()
{

}