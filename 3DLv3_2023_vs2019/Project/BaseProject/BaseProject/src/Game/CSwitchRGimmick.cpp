#include "CSwitchRGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CSwitchRGimmick::CSwitchRGimmick()
{
	// 初期処理
	Init();
}

CSwitchRGimmick::~CSwitchRGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mRSwitch.size(); i++)
	{
		mRSwitch[i]->Kill();
	}
	// 一応リストもクリアしておく
	mRSwitch.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CSwitchRGimmick::Init()
{
	// クリア土台のモデル読み込み
	mpMoveSwitchRModel = new CModel();
	mpMoveSwitchRModel->Load("Field\\Object\\switchRed.obj", "Field\\Object\\switchRed.mtl");

	// ワープの土台を生成
	//ステージ0
	if (CField::mStageCount == 3)
	{
		
	}
}

void CSwitchRGimmick::CreateSwitch(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpMoveSwitchRModel == nullptr) return;

	//// 土台を生成してリストに追加
	CSwitchRObject* switchrfield = new CSwitchRObject(mpMoveSwitchRModel, pos, scale);
	mRSwitch.push_back(switchrfield);
}

void CSwitchRGimmick::Update()
{

}