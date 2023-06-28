#include "CAHamahGimmick.h"
#include "CTaskManager.h"
#include "CApplication.h"
#include <stdlib.h>

#include "time.h"

//ハンマーリンゴ
#define MODEL_FHAMAH "res\\apple2.obj","res\\apple2.mtl"

int rand(void);
void srand(unsigned int seed);

CAHamahGimmick::CAHamahGimmick()
	:randnow(0)
	, randnow2(0)
	, randnow3(0)
	, randnow4(0)
	, randnow5(0)
{
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	CTaskManager::Instance()->Add(this);
}

CAHamahGimmick::~CAHamahGimmick()
{
	// ハマーのモデルデータを破棄
	if (mpHamahModel != nullptr)
	{
		delete mpHamahModel;
	}

	// ハマーを破棄
	for (int i = 0; i < mHamahs.size(); i++)
	{
		delete mHamahs[i];
	}
	// 一応リストもクリアしておく
	mHamahs.clear();

	// タスクマネージャーから自身を取り除く
	CTaskManager::Instance()->Remove(this);
}

void CAHamahGimmick::Init()
{
	// ハマーのモデル読み込み
	mpHamahModel = new CModel();
	mpHamahModel->Load(MODEL_FHAMAH);
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

	// ハマーを生成
	if (CApplication::SelectStage == 1)
	{
		if (CApplication::StageCount == 0)
		{
			CreateHamah(CVector(randnow, 23.9f, 7.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateHamah(CVector(randnow2, 23.9f, 15.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateHamah(CVector(randnow3, 23.9f, 25.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateHamah(CVector(randnow4, 23.9f, 33.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateHamah(CVector(randnow5, 23.9f, 41.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CApplication::StageCount == 1)
		{
			CreateHamah(CVector(randnow, 23.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateHamah(CVector(randnow2, 23.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateHamah(CVector(randnow3, 23.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateHamah(CVector(randnow4, 23.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateHamah(CVector(randnow5, 23.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CApplication::StageCount == 2)
		{
			CreateHamah(CVector(randnow, 23.9f, 105.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateHamah(CVector(randnow2, 23.9f, 113.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateHamah(CVector(randnow3, 23.9f, 121.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateHamah(CVector(randnow4, 23.9f, 129.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateHamah(CVector(randnow5, 23.9f, 137.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
	}
}

void CAHamahGimmick::CreateHamah(CVector& pos, CVector& rot, CVector& scale)
{
	if (mpHamahModel == nullptr) return;

	// ハマーを生成してリストに追加
	CAHamah* hamah = new CAHamah(mpHamahModel, pos, rot, scale);
	mHamahs.push_back(hamah);
}

void CAHamahGimmick::Update()
{
}