#include "CSwitchGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CSwitchGimmick::CSwitchGimmick()
{
	//srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CSwitchGimmick::~CSwitchGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mSwitch.size(); i++)
	{
		mSwitch[i]->Kill();
	}
	// 一応リストもクリアしておく
	mSwitch.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CSwitchGimmick::Init()
{
	// クリア土台のモデル読み込み
	mpMoveSwitchModel = new CModel();
	mpMoveSwitchModel->Load("Field\\Object\\switchRed.obj", "Field\\Object\\switchRed.mtl");

	// ワープの土台を生成
	//ステージ0
	if (CField::mStageCount == 3)
	{
		CreateSwitch(mpMoveSwitchModel,
			CVector(0.0f, 0.0f, -1.5f), CVector(10.0f, 10.0f, 10.0f));
	}
}

void CSwitchGimmick::CreateSwitch(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpMoveSwitchModel == nullptr) return;

	//// 土台を生成してリストに追加
	//CSwitch* tenfield = new CSwitch(mpMoveTenModel, pos, scale);
	//mSwitch.push_back(tenfield);

	CSwitchObject* switchfield = new CSwitchObject(mpMoveSwitchModel, pos, scale, 1.0f);
	mSwitch.push_back(switchfield);
	//CVector offset = CVector(0.0f, 0.0f, 5.0f);
	//tenfield = new CSwitch(mpMoveTenModel, CVector(0.0f, 200.0f, -80.0f), CVector(5.5f, 5.0f, 5.25f), 5.0f, -45.0f);
	//mSwitch.push_back(tenfield);
}

void CSwitchGimmick::Update()
{

}