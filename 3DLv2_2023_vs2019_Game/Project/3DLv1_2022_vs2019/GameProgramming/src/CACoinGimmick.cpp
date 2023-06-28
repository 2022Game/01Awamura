#include "CACoinGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"

#include <stdlib.h>

#include "time.h"

//土台Coin
#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"

int rand(void);
void srand(unsigned int seed);

CACoinGimmick::CACoinGimmick()
	:randnow(0)
	,randnow2(0)
	, randnow3(0)
	, randnow4(0)
	, randnow5(0)
{
	srand((unsigned int)time(NULL));
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

	if (CApplication::StageCount == 0)
	{
		randnow = 4 + rand() % 17;
		randnow2 = 4 + rand() % 17;
		randnow3 = 4 + rand() % 17;
		randnow4 = 4 + rand() % 17;
		randnow5 = 4 + rand() % 17;
	}
	if (CApplication::StageCount == 1)
	{
		randnow = 4 + rand() % 17;
		randnow2 = 4 + rand() % 17;
		randnow3 = 4 + rand() % 17;
		randnow4 = 4 + rand() % 17;
		randnow5 = 4 + rand() % 17;
	}
	if (CApplication::StageCount == 2)
	{
		randnow = 4 + rand() % 17;
		randnow2 = 4 + rand() % 17;
		randnow3 = 4 + rand() % 17;
		randnow4 = 4 + rand() % 17;
		randnow5 = 4 + rand() % 17;
	}

	// コインを生成
	//ステージ１
	if (CApplication::StageCount == 0)
	{
		CreateCoin(CVector(randnow, 0.1f, 5.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow2, 0.1f, 12.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow3, 0.1f, 19.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow4, 0.1f, 26.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow5, 0.1f, 33.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow5, 0.1f, 40.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}
	////ステージ２
	if (CApplication::StageCount == 1)
	{
		CreateCoin(CVector(randnow, 0.1f, 54.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow2, 0.1f, 61.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow3, 0.1f, 68.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow4, 0.1f, 75.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow5, 0.1f, 82.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}
	////ステージ３
	if (CApplication::StageCount == 2)
	{
		CreateCoin(CVector(randnow, 0.1f, 96.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow2, 0.1f, 103.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow3, 0.1f, 110.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow4, 0.1f, 117.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow5, 0.1f, 124.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
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