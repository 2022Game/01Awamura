#include "CField.h"
#include "CTaskManager.h"
#include "CResourceManager.h"
//コンストラクタ
CField::CField()
{
	//ポーズの種類を設定
	SetPauseType(TaskPauseType::eGame);
	//タスクの優先度設定
	mPriority = (int)TaskPriority::eBackground;
	//タスクマネージャーに自信を追加
	CTaskManager::Instance()->Add(this);

	//背景のモデルデータ読みこみ
	mModel = GET_MODEL("Field");
	//読み込んだ背景のモデルデータでコライダを作成
	mColliderMesh.Set(nullptr, nullptr, mModel);
}

//デストラクタ
CField::~CField()
{
	//タスクマネージャーから自信を取り除く
	CTaskManager::Instance()->Remove(this);
}

//更新処理
void CField::Update()
{

}

//描画処理
void CField::Render()
{
	if (mModel == nullptr) return;
		//拝啓モデルを描画
		mModel->Render();
}