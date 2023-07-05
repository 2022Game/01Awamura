#include "CASoccerGimmick.h"
#include "CTaskManager.h"
#include "CApplication.h"
//#include "CAHamahGimmick.h"

//伝説のボール
#define MODEL_FSOCCER "res\\soccer1.obj","res\\soccer1.mtl"

CASoccerGimmick::CASoccerGimmick()
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
	

	if (CApplication::StageCount == 0 && CASoccer::hdhd == 2)
	{
		CreateSoccer(CVector(13.0f, 24.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateSoccer(CVector(10.0f, 24.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateSoccer(CVector(15.0f, 24.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateSoccer(CVector(20.0f, 24.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}

	// 木を生成
	if (CApplication::SelectStage == 5)
	{
		if (CApplication::StageCount == 0)
		{
			CreateSoccer(CVector(13.0f, 24.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(10.0f, 24.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(15.0f, 24.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(20.0f, 24.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CApplication::StageCount == 1)
		{
		}
		if (CApplication::StageCount == 2)
		{
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