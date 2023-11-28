#include "CStornGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"
#include "Maths.h"

#include <stdlib.h>

#include "time.h"



//int rand(void);
//void srand(unsigned int seed);

CStornGimmick::CStornGimmick()
	:randpos(0)
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
			CVector(Math::Rand(-100, 100), 240.0f, -260.0f), CVector(10.0f, 10.0f, 10.0f));
		CreateStorn(mpStornModel,
			CVector(Math::Rand(-100, 100), 240.0f, -260.0f), CVector(10.0f, 10.0f, 10.0f));
		CreateStorn(mpStornModel,
			CVector(Math::Rand(-100, 100), 240.0f, -260.0f), CVector(10.0f, 10.0f, 10.0f));
		CreateStorn(mpStornModel,
			CVector(Math::Rand(-100, 100), 240.0f, -260.0f), CVector(10.0f, 10.0f, 10.0f));
		CreateStorn(mpStornModel,
			CVector(Math::Rand(-100, 100), 240.0f, -260.0f), CVector(10.0f, 10.0f, 10.0f));
		CreateStorn(mpStornModel,
			CVector(Math::Rand(-100, 100), 240.0f, -260.0f), CVector(10.0f, 10.0f, 10.0f));
		CreateStorn(mpStornModel,
			CVector(Math::Rand(-100, 100), 240.0f, -260.0f), CVector(10.0f, 10.0f, 10.0f));
		CreateStorn(mpStornModel,
			CVector(Math::Rand(-100, 100), 240.0f, -260.0f), CVector(10.0f, 10.0f, 10.0f));
		CreateStorn(mpStornModel,
			CVector(Math::Rand(-100, 100), 240.0f, -260.0f), CVector(10.0f, 10.0f, 10.0f));
		CreateStorn(mpStornModel,
			CVector(Math::Rand(-100, 100), 240.0f, -260.0f), CVector(10.0f, 10.0f, 10.0f));
		CreateStorn(mpStornModel,
			CVector(Math::Rand(-100, 100), 240.0f, -260.0f), CVector(10.0f, 10.0f, 10.0f));
		CreateStorn(mpStornModel,
			CVector(Math::Rand(-100, 100), 240.0f, -260.0f), CVector(10.0f, 10.0f, 10.0f));
		CreateStorn(mpStornModel,
			CVector(Math::Rand(-100, 100), 240.0f, -260.0f), CVector(10.0f, 10.0f, 10.0f));
		CreateStorn(mpStornModel,
			CVector(Math::Rand(-100, 100), 240.0f, -260.0f), CVector(10.0f, 10.0f, 10.0f));
		CreateStorn(mpStornModel,
			CVector(Math::Rand(-100, 100), 240.0f, -260.0f), CVector(10.0f, 10.0f, 10.0f));
	}
}

void CStornGimmick::CreateStorn(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpStornModel == nullptr) return;

	// クリア土台を生成してリストに追加
	CStorn* storn = new CStorn(mpStornModel, pos, scale,0.0f);
	mStorn.push_back(storn);
}

void CStornGimmick::Update()
{
	
}