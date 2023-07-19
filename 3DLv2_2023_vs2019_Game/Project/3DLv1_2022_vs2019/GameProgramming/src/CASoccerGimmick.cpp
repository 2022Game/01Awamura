#include "CASoccerGimmick.h"
#include "CTaskManager.h"
#include "CApplication.h"
#include <stdlib.h>

#include "time.h"

//伝説のボール
#define MODEL_FSOCCER "res\\soccer1.obj","res\\soccer1.mtl"

int rand(void);
void srand(unsigned int seed);

CASoccerGimmick::CASoccerGimmick()
	:randnow(0)
	, randnow2(0)
	, randnow3(0)
	, randnow4(0)
	, randnow5(0)
	, randnow6(0)
	, randnow7(0)
	, randnow8(0)
	, randnow9(0)
	, randnow10(0)
{
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	CTaskManager::Instance()->Add(this);
}

CASoccerGimmick::~CASoccerGimmick()
{
	// Soccerのモデルデータを破棄
	if (mpSoccerModel != nullptr)
	{
		delete mpSoccerModel;
	}

	// Soccerを破棄
	for (int i = 0; i < mSoccers.size(); i++)
	{
		delete mSoccers[i];
	}
	// 一応リストもクリアしておく
	mSoccers.clear();

	// タスクマネージャーから自身を取り除く
	CTaskManager::Instance()->Remove(this);
}

void CASoccerGimmick::Init()
{
	// 木のモデル読み込み
	mpSoccerModel = new CModel();
	mpSoccerModel->Load(MODEL_FSOCCER);
	if (CApplication::StageCount == 0)
	{
		randnow = 4 + rand() % 17;
		randnow2 = 4 + rand() % 17;
		randnow3 = 4 + rand() % 17;
		randnow4 = 4 + rand() % 17;
		randnow5 = 4 + rand() % 17;
		randnow6 = 4 + rand() % 17;
		randnow7 = 4 + rand() % 17;
		randnow8 = 4 + rand() % 17;
		randnow9 = 4 + rand() % 17;
		randnow10 = 4 + rand() % 17;
	}
	if (CApplication::StageCount == 1)
	{
		randnow = 4 + rand() % 17;
		randnow2 = 4 + rand() % 17;
		randnow3 = 4 + rand() % 17;
		randnow4 = 4 + rand() % 17;
		randnow5 = 4 + rand() % 17;
		randnow6 = 4 + rand() % 17;
		randnow7 = 4 + rand() % 17;
		randnow8 = 4 + rand() % 17;
		randnow9 = 4 + rand() % 17;
		randnow10 = 4 + rand() % 17;
	}
	if (CApplication::StageCount == 2)
	{
		randnow = 4 + rand() % 17;
		randnow2 = 4 + rand() % 17;
		randnow3 = 4 + rand() % 17;
		randnow4 = 4 + rand() % 17;
		randnow5 = 4 + rand() % 17;
		randnow6 = 4 + rand() % 17;
		randnow7 = 4 + rand() % 17;
		randnow8 = 4 + rand() % 17;
		randnow9 = 4 + rand() % 17;
		randnow10 = 4 + rand() % 17;
	}

	if (CASoccer::hdhd == 2)
	{
		/*if (CPlayer::CountCraft == 0)
		{
			CreateSoccer(CVector(randnow, 23.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(randnow2, 23.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(randnow3, 23.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(randnow4, 23.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(randnow5, 23.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CPlayer::CountCraft == 1)
		{
			CreateSoccer(CVector(randnow, 23.0f, 140.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(randnow2, 23.0f, 140.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(randnow3, 23.0f, 140.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(randnow4, 23.0f, 140.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(randnow5, 23.0f, 140.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		CASoccer::hdhd = 0;*/
	}

	if (CApplication::SelectStage == 5)
	{
		if (CApplication::StageCount == 0)
		{
			CreateSoccer(CVector(randnow, 23.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(randnow2, 23.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(randnow3, 23.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(randnow4, 23.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(randnow5, 23.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CApplication::StageCount == 1)
		{
			CreateSoccer(CVector(randnow, 23.0f, 140.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(randnow2, 23.0f, 140.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(randnow3, 23.0f, 140.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(randnow4, 23.0f, 140.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(randnow5, 23.0f, 140.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
	}
	if (CApplication::SelectStage == 6)
	{
		if (CApplication::StageCount == 0)
		{
		}
		if (CApplication::StageCount == 1)
		{
		}
		if (CApplication::StageCount == 2)
		{
		}
	}
}

void CASoccerGimmick::CreateSoccer(CVector& pos, CVector& rot, CVector& scale)
{
	if (mpSoccerModel == nullptr) return;

	// 木を生成してリストに追加
	CASoccer* soccer = new CASoccer(mpSoccerModel, pos, rot, scale);
	mSoccers.push_back(soccer);
}

void CASoccerGimmick::Update()
{
}