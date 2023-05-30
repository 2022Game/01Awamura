#include "CAHamahGimmick.h"
#include "CTaskManager.h"

//ハンマーリンゴ
#define MODEL_FHAMAH "res\\apple2.obj","res\\apple2.mtl"

CAHamahGimmick::CAHamahGimmick()
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

	// ハマーを生成
	CreateHamah(CVector(10.0f, 24.9f, 8.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateHamah(CVector(11.5f, 24.9f, 16.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateHamah(CVector(13.0f, 24.9f, 23.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateHamah(CVector(11.5f, 24.9f, 31.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateHamah(CVector(10.0f, 24.9f, 39.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
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