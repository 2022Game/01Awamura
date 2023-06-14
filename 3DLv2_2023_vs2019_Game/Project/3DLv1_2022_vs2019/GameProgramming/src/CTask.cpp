#include "CTask.h"

//コンストラクタ
CTask::CTask()
	: mpNext(nullptr)
	, mpPrev(nullptr)
	, mPriority((int)TaskPriority::eDefault)
	, mEnabled(true)
	, mPauseType(TaskPauseType::eDefault)
{
}

//デストラクタ
CTask::~CTask()
{
}

//更新
void CTask::Update()
{
}

//描画
void CTask::Render()
{
}

//ポーズの種類を設定
void CTask::SetPauseType(TaskPauseType type)
{
	mPauseType = type;
}

//ポーズの種類を取得
TaskPauseType CTask::GetPauseType() const
{
	return mPauseType;
}