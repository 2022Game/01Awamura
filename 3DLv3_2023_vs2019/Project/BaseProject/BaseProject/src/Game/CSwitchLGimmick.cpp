#include "CSwitchLGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CSwitchLGimmick::CSwitchLGimmick()
{
	// 初期処理
	Init();
}

CSwitchLGimmick::~CSwitchLGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mLSwitch.size(); i++)
	{
		mLSwitch[i]->Kill();
	}
	// 一応リストもクリアしておく
	mLSwitch.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CSwitchLGimmick::Init()
{
	// クリア土台のモデル読み込み
	mpMoveSwitchLModel = new CModel();
	mpMoveSwitchLModel->Load("Field\\Object\\switchBlue.obj", "Field\\Object\\switchBlue.mtl");

	// ワープの土台を生成
	//ステージ0
	if (CField::mStageCount == 3)
	{
		CreateSwitch(mpMoveSwitchLModel,
			CVector(-15.0f, -5.0f, 240.0f), CVector(10.0f, 10.0f, 10.0f));
	}
}

void CSwitchLGimmick::CreateSwitch(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpMoveSwitchLModel == nullptr) return;

	//// 土台を生成してリストに追加
	CSwitchLObject* switchlfield = new CSwitchLObject(mpMoveSwitchLModel, pos, scale);
	mLSwitch.push_back(switchlfield);
}

void CSwitchLGimmick::Update()
{

}