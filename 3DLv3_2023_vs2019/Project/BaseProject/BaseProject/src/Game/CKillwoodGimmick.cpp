#include "CKillwoodGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"
#include "Maths.h"

#include <stdlib.h>

#include "time.h"



//int rand(void);
//void srand(unsigned int seed);

CKillwoodGimmick::CKillwoodGimmick()
	:randpos(0)
{
	//srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CKillwoodGimmick::~CKillwoodGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mKillwood.size(); i++)
	{
		mKillwood[i]->Kill();
	}
	// 一応リストもクリアしておく
	mKillwood.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CKillwoodGimmick::Init()
{
	// 坂道土台のモデル読み込み
	mpKillwoodModel = CResourceManager::Get<CModel>("Killwood");
	// 坂道の土台を生成
	if (CField::mStageCount == 4)
	{

	}
}

void CKillwoodGimmick::CreateKillwood(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpKillwoodModel == nullptr) return;

	// クリア土台を生成してリストに追加
	CKillwood* killwood = new CKillwood(mpKillwoodModel, pos, scale, 1.0f);
	mKillwood.push_back(killwood);
}

void CKillwoodGimmick::Update()
{

}