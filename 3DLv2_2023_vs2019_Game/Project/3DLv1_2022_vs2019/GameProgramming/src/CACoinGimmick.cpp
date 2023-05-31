#include "CACoinGimmick.h"
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
	CreateCoin(CVector(10.0f, 0.1f, 31.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateCoin(CVector(11.5f, 0.1f, 23.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateCoin(CVector(13.0f, 0.1f, 16.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateCoin(CVector(11.5f, 0.1f, 8.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateCoin(CVector(10.0f, 0.1f, 3.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	////ステージ２
	//CreateCoin(CVector(10.0f, 0.1f, 76.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	//CreateCoin(CVector(11.5f, 0.1f, 68.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	//CreateCoin(CVector(13.0f, 0.1f, 61.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	//CreateCoin(CVector(11.5f, 0.1f, 53.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	//CreateCoin(CVector(10.0f, 0.1f, 46.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	////ステージ３
	//CreateCoin(CVector(10.0f, 0.1f, 76.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	//CreateCoin(CVector(11.5f, 0.1f, 68.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	//CreateCoin(CVector(13.0f, 0.1f, 61.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	//CreateCoin(CVector(11.5f, 0.1f, 53.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	//CreateCoin(CVector(10.0f, 0.1f, 46.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
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