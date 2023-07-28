#include "CACoinGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CResourceManager.h"

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
	,randnow6(0)
	,mmmmm(0)
{
	srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	CTaskManager::Instance()->Add(this);
	
}

CACoinGimmick::~CACoinGimmick()
{
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
	mpCoinModel = GET_MODEL("Coin");

	if (CApplication::StageCount == 0)
	{
		randnow = 4 + rand() % 17;
		randnow2 = 4 + rand() % 17;
		randnow3 = 4 + rand() % 17;
		randnow4 = 4 + rand() % 17;
		randnow5 = 4 + rand() % 17;
		randnow6 = 4 + rand() % 17;
	}
	if (CApplication::StageCount == 1)
	{
		randnow = 4 + rand() % 17;
		randnow2 = 4 + rand() % 17;
		randnow3 = 4 + rand() % 17;
		randnow4 = 4 + rand() % 17;
		randnow5 = 4 + rand() % 17;
		randnow6 = 4 + rand() % 17;
	}
	if (CApplication::StageCount == 2)
	{
		randnow = 4 + rand() % 17;
		randnow2 = 4 + rand() % 17;
		randnow3 = 4 + rand() % 17;
		randnow4 = 4 + rand() % 17;
		randnow5 = 4 + rand() % 17;
		randnow6 = 4 + rand() % 17;
	}

	// コインを生成
	//ステージ１
	if (CApplication::StageCount == 0)
	{
		CreateCoin(CVector(randnow, 22.9f, 6.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow2, 22.9f, 13.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow3, 22.9f, 20.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow4, 22.9f, 27.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow5, 22.9f, 34.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow6, 22.9f, 41.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}
	////ステージ２
	if (CApplication::StageCount == 1)
	{
		CreateCoin(CVector(randnow, 22.9f, 56.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow2, 22.9f, 63.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow3, 22.9f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow4, 22.9f, 77.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow5, 22.9f, 84.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow6, 22.9f, 91.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}
	////ステージ３
	if (CApplication::StageCount == 2)
	{
		CreateCoin(CVector(randnow, 22.9f,106.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow2, 22.9f, 113.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow3, 22.9f, 120.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow4, 22.9f, 127.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow5, 22.9f, 134.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow6, 22.9f, 141.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
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