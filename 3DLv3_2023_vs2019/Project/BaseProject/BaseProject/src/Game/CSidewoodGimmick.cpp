#include "CSidewoodGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"
#include "Maths.h"

#include <stdlib.h>

#include "time.h"



//int rand(void);
//void srand(unsigned int seed);

CSidewoodGimmick::CSidewoodGimmick()
	:randpos(0)
{
	//srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CSidewoodGimmick::~CSidewoodGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mSidewood.size(); i++)
	{
		mSidewood[i]->Kill();
	}
	// 一応リストもクリアしておく
	mSidewood.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CSidewoodGimmick::Init()
{
	// 坂道土台のモデル読み込み
	mpSidewoodModel = new CModel();
	mpSidewoodModel->Load("Field\\Killbranc.obj", "Field\\Killbranc.mtl");

	// 坂道の土台を生成
	if (CField::mStageCount == 4)
	{
		
	}
}

void CSidewoodGimmick::CreateSidewood(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpSidewoodModel == nullptr) return;

	// クリア土台を生成してリストに追加
	CSidewood* sidewood = new CSidewood(mpSidewoodModel, pos, scale, 1.0f);
	mSidewood.push_back(sidewood);

	CVector offset = CVector(0.0f, 0.0f, 5.0f);
	sidewood = new CSidewood(mpSidewoodModel, CVector(0.0f, 6.0f, -30.0f), CVector(5.5f, 5.0f, 5.25f), 1.0f);
	mSidewood.push_back(sidewood);
}

void CSidewoodGimmick::Update()
{

}