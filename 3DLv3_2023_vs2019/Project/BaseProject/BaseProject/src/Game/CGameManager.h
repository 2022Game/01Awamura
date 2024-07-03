#pragma once
#include "CTask.h"

//ゲームの状態
enum class EGameState
{
	eReady,       //準備中
	eGame,       //ゲーム実行中
	eStageClear, //ステージクリア
	eGameClear,  //ゲームクリア
	eGameOver,   //ゲームオーバー
};

//ゲームを管理するクラス
class CGameManager:public CTask
{
public:
	//ゲーム開始
	static void GameStart();
	//ステージクリア
	static void StageClear();
	//ゲームオーバー
	static void GameOver();
	//現在のゲームの状態を取得
	static EGameState GameState();
	//現在のステージ番号を取得
	static int StageNo();
	//更新
	void Update() override;
	//現在のステージ進行を取得
	static int StageClearCount();
private:
	//コンストラクタ
	CGameManager();
	//デストラクタ
	~CGameManager();

	static CGameManager* Instance();

	//現在のゲームの状態を切り替える
	void ChangeState(EGameState state);

	//準備状態の更新処理
	void UpdateReady();
	//ゲーム中の更新処理
	void UpdateGame();
	//ステージクリア時の更新処理
	void UpdateStageClear();
	//ゲームクリア時の更新処理
	void UpdateGameClear();
	//ゲームオーバー時の更新処理
	void UpdateGameOver();

	static CGameManager* spInstance;
	int RandCount; //ランダム調整用
	int n[8]; //ランダム用の配列
	int mStageNo; //現在のステージ番号
	int mStageNoswitch; //ステージ管理用
	int mStageClearCount; //CLEARしたカウント
	EGameState mState; //現在のゲームの状態
	int mStateStep; //状態内でのステップ
	float mElapsedTime; //経過時間計測用

};