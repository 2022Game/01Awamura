#include "CStoneGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"
#include "Maths.h"

#include <stdlib.h>

#include "time.h"



//int rand(void);
//void srand(unsigned int seed);

CStoneGimmick::CStoneGimmick()
	:randpos(0)
{
	//srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CStoneGimmick::~CStoneGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mStone.size(); i++)
	{
		mStone[i]->Kill();
	}
	// 一応リストもクリアしておく
	mStone.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CStoneGimmick::Init()
{
	// 坂道土台のモデル読み込み
	mpStoneModel = new CModel();
	mpStoneModel->Load("Field\\Stone.obj", "Field\\Stone.mtl");

	// 坂道の土台を生成
	if (CField::mStageCount == 2)
	{
		
	}
}

void CStoneGimmick::CreateStone(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpStoneModel == nullptr) return;

	// クリア土台を生成してリストに追加
	CStone* stone = new CStone(mpStoneModel, pos, scale,0.0f);
	mStone.push_back(stone);
}

void CStoneGimmick::Update()
{
	
}