#pragma once
class CStageBase;

//ステージの管理クラス
class CStageManager
{
public:
	//ステージ読み込み
	static void LoadStage(int no);
	//現在のステージ破棄
	static void UnloadStage();
	//作成したタスクをリストに追加
	static void AddTask(CTask* task);
	//作成したタスクをリストから取り除く
	static void RemoveTask(CTask* task);
private:
	//コンストラクタ
	CStageManager();
	//デストラクタ
	~CStageManager();

	//ステージマネージャーのインスタンス
	static CStageManager* spInstance;
	static CStageBase* spCurrentStage; // 現在のステージ
};