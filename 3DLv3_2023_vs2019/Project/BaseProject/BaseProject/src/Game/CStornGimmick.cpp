#include "CStornGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"



//int rand(void);
//void srand(unsigned int seed);

CStornGimmick::CStornGimmick()
{
	//srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CStornGimmick::~CStornGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mStorn.size(); i++)
	{
		mStorn[i]->Kill();
	}
	// 一応リストもクリアしておく
	mStorn.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CStornGimmick::Init()
{
	// 坂道土台のモデル読み込み
	mpStornModel = new CModel();
	mpStornModel->Load("Field\\Storn.obj", "Field\\Storn.mtl");

	// 坂道の土台を生成
	if (CField::mStageCount == 2)
	{
		CreateStorn(mpStornModel,
			CVector(0.0f, 70.0f, -300.0f), CVector(10.0f, 10.0f, 10.0f),CVector(0.0f,-50.0f,0.0f),45.0f);
	}
}

void CStornGimmick::CreateStorn(CModel* model, const CVector& pos, const CVector& scale ,const CVector& move,float moveTime)
{
	if (mpStornModel == nullptr) return;

	// クリア土台を生成してリストに追加
	CStorn* storn = new CStorn(mpStornModel, pos, scale,move,45.0f);
	mStorn.push_back(storn);

	/*CStorn* storn = new CStorn(mpStornModel, pos, scale, move);
	mStorn.push_back(storn);
	CVector offset = CVector(0.0f, 0.0f, 5.0f);
	storn = new CStorn(mpStornModel, CVector(10.0f, 70.0f, -300.0f), CVector(10.0f, 10.0f, 10.0f), CVector(0.0f,-1.0f,0.0f));
	mStorn.push_back(storn);*/
}

void CStornGimmick::Update()
{
}