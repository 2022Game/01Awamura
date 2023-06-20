#include "CACoinGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"

//土台Coin
#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"

CACoinGimmick::CACoinGimmick()
{
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	CTaskManager::Instance()->Add(this);
	
}

CACoinGimmick::~CACoinGimmick()
{
	// コインのモデルデータを破棄
	if (mpCoinModel != nullptr)
	{
		delete mpCoinModel;
	}

	// コインを破棄
	for (int i = 0; i < mCoins.size(); i++)
	{
		delete mCoins[i];
	}
	// 一応リストもクリアしておく
	mCoins.clear();

	// タスクマネージャーから自身を取り除く
	CTaskManager::Instance()->Remove(this);
}

void CACoinGimmick::Init()
{
	// コインのモデル読み込み
	mpCoinModel = new CModel();
	mpCoinModel->Load(MODEL_FCOIN);

	// コインを生成
	//ステージ１
	if (CApplication::StageCount == 0)
	{
		CreateCoin(CVector(10.0f, 0.1f, 6.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(11.5f, 0.1f, 14.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(13.0f, 0.1f, 22.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(11.5f, 0.1f, 30.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(10.0f, 0.1f, 38.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}
	////ステージ２
	if (CApplication::StageCount == 1)
	{
		CreateCoin(CVector(10.0f, 0.1f, 54.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateCoin(CVector(11.5f, 0.1f, 62.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateCoin(CVector(13.0f, 0.1f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateCoin(CVector(11.5f, 0.1f, 78.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateCoin(CVector(10.0f, 0.1f, 86.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}
	////ステージ３
	if (CApplication::StageCount == 2)
	{
		CreateCoin(CVector(10.0f, 0.1f, 102.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(11.5f, 0.1f, 110.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(13.0f, 0.1f, 118.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(11.5f, 0.1f, 126.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(10.0f, 0.1f, 134.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}
}

void CACoinGimmick::CreateCoin(CVector& pos, CVector& rot, CVector& scale)
{
	if (mpCoinModel == nullptr) return;

	// コインを生成してリストに追加
	CACoin* coin = new CACoin(mpCoinModel, pos, rot, scale);
	mCoins.push_back(coin);
}

void CACoinGimmick::Update()
{
	//if (プレイヤーがコインに接地したら)
	{
		for (int i = 0; i < mCoins.size(); i++)
		{
			CACoin* coin = mCoins[i];
			if (coin->SCount == 0)
			{
				coin->SCount = 1;
			}
		}
	}
}