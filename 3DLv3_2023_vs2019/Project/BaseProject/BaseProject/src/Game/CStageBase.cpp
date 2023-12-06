#include "CStageBase.h"

//コンストラクタ
CStageBase::CStageBase()
{

}

//デストラクタ
CStageBase::~CStageBase()
{

}

//ステージ破棄
void CStageBase::Unload()
{
	//子のステージで作成したタスクを全て削除
	for (CTask* task : mCreateTasks)
	{
		task->Kill();
	}
}

//作成したタスクをリストに追加
void CStageBase::AddTask(CTask* task)
{
	mCreateTasks.push_back(task);
}

//作成したタスクをリストから取り除く
void CStageBase::RemoveTask(CTask* task)
{
	mCreateTasks.remove(task);
}

//ステージ番号取得
int CStageBase::GetStageNo() const
{
	return mStageNo;
}