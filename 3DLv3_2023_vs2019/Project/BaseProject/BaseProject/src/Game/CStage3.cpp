#include "CStage3.h"
#include "CClearStage.h"
#include "CFloor.h"
#include "CSwitchLObject.h"
#include "CSwitchRObject.h"
#include "CMoveField.h"
#include "CIMoveField.h"
#include "CTMoveField.h"
#include "CJMoveField.h"
#include "CLMoveField.h"


//コンストラクタ
CStage3::CStage3()
{
	mStageNo = 3;
}

//デストラクタ
CStage3::~CStage3()
{

}

//ステージ読み込み
void CStage3::Load()
{
	//普通の足場読み込み
	CModel* floorModel = new CModel();
	floorModel->Load("Field\\Object\\cube.obj", "Field\\Object\\cube.mtl");
	mCreateModels.push_back(floorModel);

	// クリア土台のモデル読み込み
	CModel* clearStageModel = new CModel();
	clearStageModel->Load("Field\\Object\\cylinder.obj", "Field\\Object\\cylinder.mtl");
	mCreateModels.push_back(clearStageModel);

	// 左スイッチのモデル読み込み
	CModel* switchLModel = new CModel();
	switchLModel->Load("Field\\Object\\switchBlue.obj", "Field\\Object\\switchBlue.mtl");
	mCreateModels.push_back(switchLModel);

	// 右スイッチのモデル読み込み
	CModel* switchRModel = new CModel();
	switchRModel->Load("Field\\Object\\switchRed.obj", "Field\\Object\\switchRed.mtl");
	mCreateModels.push_back(switchRModel);

	//十字土台読み込み
	CModel* moveTenModel = new CModel();
	moveTenModel->Load("Field\\Object\\10field.obj", "Field\\Object\\10field.mtl");
	mCreateModels.push_back(moveTenModel);

	// I字土台読み込み
	CModel* moveIModel = new CModel();
	moveIModel->Load("Field\\Object\\Ifield.obj", "Field\\Object\\Ifield.mtl");
	mCreateModels.push_back(moveIModel);

	// T字土台のモデル読み込み
	CModel* moveTModel = new CModel();
	moveTModel->Load("Field\\Object\\Tfield.obj", "Field\\Object\\Tfield.mtl");
	mCreateModels.push_back(moveTModel);

	//J字土台のモデル読み込み
	CModel* moveJModel = new CModel();
	moveJModel->Load("Field\\Object\\Jfield.obj", "Field\\Object\\Jfield.mtl");
	mCreateModels.push_back(moveJModel);

	//L字土台のモデル読み込み
	CModel* moveLModel = new CModel();
	moveLModel->Load("Field\\Object\\Lfield.obj", "Field\\Object\\Lfield.mtl");
	mCreateModels.push_back(moveLModel);

	//普通の足場
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, -10.0f, 240.0f), CVector(5.0f, 4.0f, 0.5f));
	AddTask(floor);

	//クリア土台を作成
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, 0.0f, -70.0f), CVector(1.0f, 1.0f, 1.0f));
	AddTask(coin);

	//左スイッチを作成
	CSwitchLObject* switchl = new CSwitchLObject(switchLModel,
		CVector(-15.0f, -5.0f, 240.0f), CVector(10.0f, 10.0f, 10.0f));
	AddTask(switchl);

	//右スイッチを作成
	CSwitchRObject* switchr = new CSwitchRObject(switchRModel,
		CVector(15.0f, -5.0f, 240.0f), CVector(10.0f, 10.0f, 10.0f));
	AddTask(switchr);

	//十字土台を作成
	CMoveField* tenfield = new CMoveField(moveTenModel,
		CVector(0.0f, -5.0f, 10.0f), CVector(12.5f, 12.5f, 12.5f)
		,0.0f);
	AddTask(tenfield);

	//I字土台を作成
	CIMoveField* ifield = new CIMoveField(moveIModel,
		CVector(80.0f, -5.0f, 180.0f), CVector(12.5f, 12.5f, 12.5f)
		,0.0f);
	AddTask(ifield);

	//T字土台を作成
	CTMoveField* tfield = new CTMoveField(moveTModel,
		CVector(0.0f, -5.0f, 180.0f), CVector(12.5f, 12.5f, 12.5f)
		,0.0f);
	AddTask(tfield);
	tfield = new CTMoveField(moveTModel,
		CVector(80.0f, -5.0f, 100.0f), CVector(12.5f, 12.5f, 12.5f)
		, 0.0f);
	AddTask(tfield);
	tfield = new CTMoveField(moveTModel,
		CVector(-80.0f, -5.0f, 100.0f), CVector(12.5f, 12.5f, 12.5f)
		, 0.0f);
	AddTask(tfield);
	tfield = new CTMoveField(moveTModel,
		CVector(80.0f, -5.0f, -50.0f), CVector(12.5f, 12.5f, 12.5f)
		, 0.0f);
	AddTask(tfield);
	tfield = new CTMoveField(moveTModel,
		CVector(-80.0f, -5.0f, -50.0f), CVector(12.5f, 12.5f, 12.5f)
		, 0.0f);
	AddTask(tfield);

	//J字土台を作成
	CJMoveField* jfield = new CJMoveField(moveJModel,
		CVector(0.0f, 0.0f, -70.0f), CVector(1.0f, 1.0f, 1.0f)
		, 0.0f);
	AddTask(jfield);
	jfield = new CJMoveField(moveJModel,
		CVector(-80.0f, -5.0f, 20.0f), CVector(12.5f, 12.5f, 12.5f)
		, 0.0f);
	AddTask(jfield);

	//L字土台を作成
	CLMoveField* lfield = new CLMoveField(moveLModel,
		CVector(0.0f, 0.0f, -70.0f), CVector(1.0f, 1.0f, 1.0f)
		, 0.0f);
	AddTask(lfield);
	lfield = new CLMoveField(moveLModel,
		CVector(80.0f, -5.0f, 20.0f), CVector(12.5f, 12.5f, 12.5f)
		, 0.0f);
	AddTask(lfield);
}

//ステージ破棄
void CStage3::Unload()
{
	//ベースのステージ破棄処理
	CStageBase::Unload();
}