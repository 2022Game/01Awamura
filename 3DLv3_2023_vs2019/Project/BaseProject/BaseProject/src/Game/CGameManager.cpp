#include "CGameManager.h"
#include "CStageManager.h"
#include "Maths.h"

CGameManager* CGameManager::spInstance = nullptr;

//コンストラクタ
CGameManager::CGameManager()
	:mStageNo(0)
	,mStageNoswitch(0)
	,mStageClearCount(0)
	,mState(EGameState::eReady)
	,mStateStep(0)
	,mElapsedTime(0.0f)
	,RandCount(7)
{
	n[0] = 1;
	n[1] = 2;
	n[2] = 3;
	n[3] = 4;
	n[4] = 5;
	n[5] = 6;
	n[6] = 7;
	n[7] = 8;
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

//現在のステージ進行を取得
int CGameManager::StageClearCount()
{
	return Instance()->mStageClearCount;
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
	//ステージをCLEARした時にカウントを+する
	mStageClearCount++;

	//ステージをクリアしたら次のステージを読み込む
	//重複しないランダムの生成用の配列
	//ステージは４つまで
	if (mStageClearCount < 5)
	{
		int x;
		x = 0;
		mStageNoswitch = Math::Rand(0, RandCount);
		x = mStageNoswitch;
		mStageNo = n[mStageNoswitch];
		n[x] = n[RandCount];
		RandCount = RandCount - 1;
		CStageManager::LoadStage(mStageNo);
	}

	//ステージを４つCLEARしたら終了
	if (mStageClearCount >= 5)
	{
		mStageNo = 0;
		CStageManager::LoadStage(mStageNo);
	}

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