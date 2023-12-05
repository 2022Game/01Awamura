#include "CStage5.h"
#include "CClearStage.h"

//コンストラクタ
CStage5::CStage5()
{
	mStageNo = 5;
}

//デストラクタ
CStage5::~CStage5()
{

}

//ステージ読み込み
void CStage5::Load()
{
	// クリア土台のモデル読み込み
	CModel* clearStageModel = new CModel();
	clearStageModel->Load("Field\\Object\\cylinder.obj", "Field\\Object\\cylinder.mtl");
	mCreateModels.push_back(clearStageModel);

	//クリア土台を作成
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, -5.0f, -20.0f), CVector(1.0f, 1.0f, 1.0f));
	AddTask(coin);
}

//ステージ破棄
void CStage5::Unload()
{
	//ベースのステージ破棄処理
	CStageBase::Unload();
}