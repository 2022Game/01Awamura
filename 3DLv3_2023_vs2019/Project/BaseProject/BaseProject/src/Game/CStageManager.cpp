#include "CStageManager.h"
#include "CStageBase.h"
#include "CStageEntrance.h"
#include "CStage1.h"
#include "CStage2.h"
#include "CStage3.h"
#include "CStage4.h"
#include "CStage5.h"
#include "CStage6.h"

CStageManager* CStageManager::spInstance = nullptr;
CStageBase* CStageManager::spCurrentStage = nullptr;

//コンストラクタ
CStageManager::CStageManager()
{
	spInstance = this;
}

//デストラクタ
CStageManager::~CStageManager()
{
	spInstance = nullptr;

	//ステージが読み込まれていたら破棄
	UnloadStage();
}

//ステージ読み込み
void CStageManager::LoadStage(int no)
{
	//既にステージが読み込まれていたら破棄
	UnloadStage();

	//ステージ番号に合わせてステージを読み込み
	switch (no)
	{
	case 0:spCurrentStage = new CStageEntrance(); break;
	case 1:spCurrentStage = new CStage1(); break;
	case 2:spCurrentStage = new CStage2(); break;
	case 3:spCurrentStage = new CStage3(); break;
	case 4:spCurrentStage = new CStage4(); break;
	case 5:spCurrentStage = new CStage5(); break;
	case 6:spCurrentStage = new CStage6(); break;

	//指定されていないステージになった時
	default:spCurrentStage = new CStage6(); break;
	}

	//ステージが作成できたらステージを読み込み
	if (spCurrentStage != nullptr)
	{
		spCurrentStage->Load();
	}
}

//現在のステージを破棄
void CStageManager::UnloadStage()
{
	if (spCurrentStage == nullptr)return;
	spCurrentStage->Unload();
	SAFE_DELETE(spCurrentStage);
}

//作成したタスクをリストに追加
void CStageManager::AddTask(CTask* task)
{
	if (spCurrentStage == nullptr)return;
	spCurrentStage->AddTask(task);
}

//作成したタスクをリストから取り除く
void CStageManager::RemoveTask(CTask* task)
{
	if (spCurrentStage == nullptr)return;
	spCurrentStage->RemoveTask(task);
}