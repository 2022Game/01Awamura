#include "CIMoveFieldGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CIMoveFieldGimmick::CIMoveFieldGimmick()
{
	//srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CIMoveFieldGimmick::~CIMoveFieldGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mIMoveField.size(); i++)
	{
		mIMoveField[i]->Kill();
	}
	// 一応リストもクリアしておく
	mIMoveField.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CIMoveFieldGimmick::Init()
{
	// クリア土台のモデル読み込み
	mpMoveIModel = CResourceManager::Get<CModel>("Ifield");
	// ワープの土台を生成
	//ステージ0
	if (CField::mStageCount == 3)
	{
		
	}
}

void CIMoveFieldGimmick::CreateIMoveField(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpMoveIModel == nullptr) return;

	// 土台を生成してリストに追加
	CIMoveField* ifield = new CIMoveField(mpMoveIModel, pos, scale,2.5f);
	mIMoveField.push_back(ifield);
}

void CIMoveFieldGimmick::Update()
{

}