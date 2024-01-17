#include "CGameManager.h"
#include "CStageManager.h"

CGameManager* CGameManager::spInstance = nullptr;

//コンストラクタ
CGameManager::CGameManager()
	:mStageNo(6)
	,mState(EGameState::eReady)
	,mStateStep(0)
	,mElapsedTime(0.0f)
{

}

//デストラクタ
CGameManager::~CGameManager()
{

}

//インスタンス取得
CGameManager* CGameManager::Instance()
{
	if (spInstance == nullptr)
	{
		spInstance = new CGameManager();
	}
	return spInstance;
}

//ゲーム開始
void CGameManager::GameStart()
{
	//準備状態でなければゲーム開始はしない
	if (GameState() != EGameState::eReady)return;

	//最初のステージを読み込み
	CStageManager::LoadStage(Instance()->mStageNo);

	//ゲーム開始
	Instance()->ChangeState(EGameState::eGame);
}

//ステージクリア
void CGameManager::StageClear()
{
	Instance()->ChangeState(EGameState::eStageClear);
}

//ゲームオーバー
void CGameManager::GameOver()
{
	Instance()->ChangeState(EGameState::eGameOver);
}

//現在のゲームの状態を取得
EGameState CGameManager::GameState()
{
	return Instance()->mState;
}

//現在のステージ番号を取得
int CGameManager::StageNo()
{
	return Instance()->mStageNo;
}

//現在のゲームの状態を切り替える
void CGameManager::ChangeState(EGameState state)
{
	if (mState == state)return;
	mState = state;
	mStateStep = 0;
	mElapsedTime = 0.0f;
}

//準備状態の更新処理
void CGameManager::UpdateReady()
{

}

//ゲーム中の更新処理
void CGameManager::UpdateGame()
{

}

//ステージクリア時の更新処理
void CGameManager::UpdateStageClear()
{
	//ステージをクリアしたら次のステージを読み込む
	mStageNo++;
	CStageManager::LoadStage(mStageNo);

	//ステージの読み込みが終わればゲーム開始
	ChangeState(EGameState::eGame);
}

//ゲームクリア時の更新処理
void CGameManager::UpdateGameClear()
{

}

//ゲームオーバー時の更新処理
void CGameManager::UpdateGameOver()
{

}

//更新
void CGameManager::Update()
{
	//現在の状態に合わせた更新処理を行う
	switch (mState)
	{
		//準備中
	case EGameState::eReady:
		UpdateReady();
		break;
		//ゲーム中
	case EGameState::eGame:
		UpdateGame();
		break;
		//ステージクリア
	case EGameState::eStageClear:
		UpdateStageClear();
		break;
		//ゲームクリア
	case EGameState::eGameClear:
		UpdateGameClear();
		break;
		//ゲームオーバー
	case EGameState::eGameOver:
		UpdateGameOver();
		break;
	}
}