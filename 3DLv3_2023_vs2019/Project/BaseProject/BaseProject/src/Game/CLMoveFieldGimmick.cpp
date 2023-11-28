#include "CLMoveFieldGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CLMoveFieldGimmick::CLMoveFieldGimmick()
{
	//srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CLMoveFieldGimmick::~CLMoveFieldGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mLMoveField.size(); i++)
	{
		mLMoveField[i]->Kill();
	}
	// 一応リストもクリアしておく
	mLMoveField.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CLMoveFieldGimmick::Init()
{
	// クリア土台のモデル読み込み
	mpMoveLModel = new CModel();
	mpMoveLModel->Load("Field\\Object\\Lfield.obj", "Field\\Object\\Lfield.mtl");

	// ワープの土台を生成
	//ステージ0
	if (CField::mStageCount == 3)
	{
		CreateLMoveField(mpMoveLModel,
			CVector(0.0f, 10.0f, -40.0f), CVector(10.0f, 10.0f, 10.0f));
	}
}

void CLMoveFieldGimmick::CreateLMoveField(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpMoveLModel == nullptr) return;

	// 土台を生成してリストに追加
	CLMoveField* Lfield = new CLMoveField(mpMoveLModel, pos, scale,1.0f);
	mLMoveField.push_back(Lfield);
}

void CLMoveFieldGimmick::Update()
{

}