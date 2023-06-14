#ifndef CTASK_H
#define CTASK_H
#include "TaskPriority.h"
#include "TaskPauseType.h"
class CTaskManager;
class CCollisionManager;

/*
タスククラス
タスクリストの要素
*/
class CTask {
	friend CTaskManager;
	friend CCollisionManager;
public:
	//衝突処理
	virtual void Collision() {}

	//デフォルトコンストラクタ
	CTask();
	//デストラクタ virtualにしないと子クラスのデストラクタが呼ばれない
	virtual ~CTask();
	//更新
	virtual void Update();
	//描画
	virtual void Render();

	//ポーズの種類を設定
	void SetPauseType(TaskPauseType type);
	//ポーズの種類を取得
	TaskPauseType GetPauseType() const;
protected:
	int mPriority;	//優先度
	bool mEnabled;	//有効フラグ
private:
	CTask* mpNext;//次のポインタ
	CTask* mpPrev;//前のポインタ
	TaskPauseType mPauseType;//ポーズの種類
};

#endif
