#include "CAxeGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CAxeGimmick::CAxeGimmick()
{
	//srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CAxeGimmick::~CAxeGimmick()
{
	////斧を破棄
	for (int i = 0; i < mAxe.size(); i++)
	{
		mAxe[i]->Kill();
		//delete mClearStage[i];
	}
	// 一応リストもクリアしておく
	mAxe.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CAxeGimmick::Init()
{
	// クリア土台のモデル読み込み
	mpAxeModel = new CModel();
	//mpClearStageModel->Load("Field\\ono7.obj", "Field\\ono7.mtl");
	mpAxeModel->Load("Field\\ono7.obj", "Field\\ono7.mtl");

	// クリア判定用の土台を生成
	//ステージ１
	if (CField::mStageCount == 1 && CField::mStageCreateSwitch == 1)
	{
		CreateAxe(mpAxeModel,CVector(0.0f, 200.0f, -140.0f), CVector(5.5f, 5.0f, 5.25f));
	}
}

void CAxeGimmick::CreateAxe(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpAxeModel == nullptr) return;

	// クリア土台を生成してリストに追加
	CAxe* axe = new CAxe(mpAxeModel, pos, scale,5.0f,45.0f);
	mAxe.push_back(axe);
	CVector offset = CVector(0.0f, 0.0f, 5.0f);
	axe = new CAxe(mpAxeModel, CVector(0.0f, 200.0f, -80.0f), CVector(5.5f, 5.0f, 5.25f), 5.0f, -45.0f);
	mAxe.push_back(axe);
	/*axe = new CAxe(mpAxeModel, CVector(0.0f, 200.0f, -120.0f), CVector(5.5f, 5.0f, 5.25f), 5.0f, -45.0f);
	mAxe.push_back(axe);*/
}

void CAxeGimmick::Update()
{
	
}