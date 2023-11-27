#include "CTMoveFieldGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CTMoveFieldGimmick::CTMoveFieldGimmick()
{
	//srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CTMoveFieldGimmick::~CTMoveFieldGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mTMoveField.size(); i++)
	{
		mTMoveField[i]->Kill();
	}
	// 一応リストもクリアしておく
	mTMoveField.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CTMoveFieldGimmick::Init()
{
	// クリア土台のモデル読み込み
	mpMoveTModel = new CModel();
	mpMoveTModel->Load("Field\\Object\\Tfield.obj", "Field\\Object\\Tfield.mtl");

	// ワープの土台を生成
	//ステージ0
	if (CField::mStageCount == 3)
	{
		CreateTMoveField(mpMoveTModel,
			CVector(0.0f, 0.0f, 0.0f), CVector(10.0f, 10.0f, 10.0f));
	}
}

void CTMoveFieldGimmick::CreateTMoveField(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpMoveTModel == nullptr) return;

	// 土台を生成してリストに追加
	CTMoveField* tenfield = new CTMoveField(mpMoveTModel, pos, scale);
	mTMoveField.push_back(tenfield);
}

void CTMoveFieldGimmick::Update()
{

}