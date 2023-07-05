

#include "CAClearStage.h"
#include "CTaskManager.h"
#include "CCollisionManager.h"
#include "CEffect.h"
#include "CColliderMesh.h"
#include "CApplication.h"

//土台Coin
#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"

CAClearStage::CAClearStage()
{
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	CTaskManager::Instance()->Add(this);

}

CAClearStage::~CAClearStage()
{
	// コインのモデルデータを破棄
	if (mpCoinModel != nullptr)
	{
		delete mpCoinModel;
	}

	// コインを破棄
	for (int i = 0; i < mClearStages.size(); i++)
	{
		delete mClearStages[i];
	}
	// 一応リストもクリアしておく
	mClearStages.clear();

	// タスクマネージャーから自身を取り除く
	CTaskManager::Instance()->Remove(this);
}

void CAClearStage::Init()
{
	// コインのモデル読み込み
	mpCoinModel = new CModel();
	mpCoinModel->Load(MODEL_FCOIN);

	// コインを生成
	//ステージ１スタート生成
	if (CApplication::StageCount == 0)
	{
		ClearStage(CVector(10.0f, 0.1f, -2.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}
	////ステージ２スタート生成
	if (CApplication::StageCount == 0)
	{
		ClearStage(CVector(10.0f, 0.1f, 48.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}
	////ステージ３スタート生成
	if (CApplication::StageCount == 1)
	{
		ClearStage(CVector(10.0f, 0.1f, 98.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}
	////ゲームクリア生成
	if (CApplication::StageCount == 2)
	{
		ClearStage(CVector(10.0f, 0.1f, 148.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}
}

void CAClearStage::ClearStage(CVector& pos, CVector& rot, CVector& scale)
{
	if (mpCoinModel == nullptr) return;

	// コインを生成してリストに追加
	CACoinClearStage* coin = new CACoinClearStage(mpCoinModel, pos, rot, scale);
	mClearStages.push_back(coin);
}

void CAClearStage::Update()
{
	//if (プレイヤーがコインに接地したら)
	{
		for (int i = 0; i < mClearStages.size(); i++)
		{
			CACoinClearStage* coin = mClearStages[i];
			if (coin->SCount == 0)
			{
				coin->SCount = 1;
			}
		}
	}
}

//衝突処理
//CCollision(コライダ１、コライダ２）
void CAClearStage::Collision(CCollider* m, CCollider* o) {
	switch (m->Type())
	{
	case CCollider::EType::ETRIANGLE:
		if (o->Type() == CCollider::EType::ELINE)
		{
			if (CCollider::Collision(m, o)) {
				mEnabled = false;
			}
		}
		CVector adjust;
		break;
	}
}

void CAClearStage::Collision()
{
	mColliderMesh.ChangePriority();
	mColliderMesh1.ChangePriority();
	//コライダの優先度変更
	mCollider1.ChangePriority();
	mCollider2.ChangePriority();
	mCollider3.ChangePriority();
	//衝突処理を実行
	CCollisionManager::Instance()->Collision(&mCollider1, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mCollider2, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mCollider3, COLLISIONRANGE);
}