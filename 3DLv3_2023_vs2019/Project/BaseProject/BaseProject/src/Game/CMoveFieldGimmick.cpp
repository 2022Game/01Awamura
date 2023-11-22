#include "CMoveFieldGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CMoveFieldGimmick::CMoveFieldGimmick()
{
	//srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CMoveFieldGimmick::~CMoveFieldGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mMoveField.size(); i++)
	{
		mMoveField[i]->Kill();
	}
	// 一応リストもクリアしておく
	mMoveField.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CMoveFieldGimmick::Init()
{
	// クリア土台のモデル読み込み
	mpMoveFieldModel = new CModel();
	mpMoveFieldModel->Load("Field\\Object\\10field.obj", "Field\\Object\\10field.mtl");

	// ワープの土台を生成
	//ステージ0
	if (CField::mStageCount == 1)
	{
		CreateMoveField(mpMoveFieldModel,
			CVector(0.0f, 2.0f, -20.0f), CVector(0.5f, 4.0f, 5.0f));
	}
}

void CMoveFieldGimmick::CreateMoveField(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpMoveFieldModel == nullptr) return;

	// クリア土台を生成してリストに追加
	CMoveField* warp = new CMoveField(mpMoveFieldModel, pos, scale);
	mMoveField.push_back(warp);
}

void CMoveFieldGimmick::Update()
{

}