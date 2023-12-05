#pragma once
#include "CTask.h"
#include <list>
#include "CModel.h"

//ステージのベースクラス
class CStageBase
{
public:
	//コンストラクタ
	CStageBase();
	//デストラクタ
	virtual ~CStageBase();

	//ステージ読み込み(継承先で実装）
	virtual void Load() = 0;
	//ステージ破棄
	virtual void Unload();

	//ステージ番号取得
	int GetStageNo() const;

	//作成したタスクを追加
	void AddTask(CTask* task);
	//作成したタスクをリストから取り除く
	void RemoveTask(CTask* task);

protected:
	int mStageNo; //ステージ番号

	//子のステージで作成したタスクのリスト
	std::list<CTask*>mCreateTasks;
	//子のステージで作成したモデルのリスト
	std::list<CModel*> mCreateModels;
};