#include "CCharacter3.h"
#include "CApplication.h"

CCharacter3::CCharacter3()
	:mpModel(nullptr)
	, mTag(ETag::EZERO)
{
	SetPauseType(TaskPauseType::eGame);

	//タスクリストに追加
//	CApplication::TaskManager()->Add(this);
	CTaskManager::Instance()->Add(this);
}

CCharacter3::CCharacter3(int priority)
	:mpModel(nullptr)
	, mTag(ETag::EZERO)
{
	SetPauseType(TaskPauseType::eGame);

	mPriority = priority;
	CTaskManager::Instance()->Add(this);
}

CCharacter3::ETag CCharacter3::Tag()
{
	return mTag;
}

CCharacter3::~CCharacter3()
{
	//タスクリストから削除
//	CApplication::TaskManager()->Remove(this);
	CTaskManager::Instance()->Remove(this);
}

void CCharacter3::Model(CModel* m)
{
	mpModel = m;
}

//描画処理
void CCharacter3::Render()
{
	mpModel->Render(Matrix());
}

//キャラクター削除
void CCharacter3::Kill()
{
	mEnabled = false;
}

//キャラクターが死んでいるかどうか
bool CCharacter3::IsDeath() const
{
	//HPが０以下なら死んでいる
	return mHp <= 0;
}

//CLEARしたかどうか
bool CCharacter3::IsClear() const
{
	//ステージカウントが4ならCLEAR
	return CApplication::StageCount == 5;
}