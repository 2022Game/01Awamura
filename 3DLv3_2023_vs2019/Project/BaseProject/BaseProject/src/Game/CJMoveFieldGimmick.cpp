#include "CJMoveFieldGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CJMoveFieldGimmick::CJMoveFieldGimmick()
{
	//srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CJMoveFieldGimmick::~CJMoveFieldGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mJMoveField.size(); i++)
	{
		mJMoveField[i]->Kill();
	}
	// 一応リストもクリアしておく
	mJMoveField.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CJMoveFieldGimmick::Init()
{
	// クリア土台のモデル読み込み
	mpMoveJModel = new CModel();
	mpMoveJModel->Load("Field\\Object\\Jfield.obj", "Field\\Object\\Jfield.mtl");

	// ワープの土台を生成
	//ステージ0
	if (CField::mStageCount == 3)
	{
		CreateJMoveField(mpMoveJModel,
			CVector(0.0f, 10.0f, -60.0f), CVector(10.0f, 10.0f, 10.0f));
	}
}

void CJMoveFieldGimmick::CreateJMoveField(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpMoveJModel == nullptr) return;

	// 土台を生成してリストに追加
	CJMoveField* jfield = new CJMoveField(mpMoveJModel, pos, scale,1.0f);
	mJMoveField.push_back(jfield);
}

void CJMoveFieldGimmick::Update()
{

}