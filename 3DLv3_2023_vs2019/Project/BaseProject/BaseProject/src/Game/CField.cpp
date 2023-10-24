#include "CField.h"
#include "CCollisionManager.h"
#include "CMoveFloor.h"
#include "CRotateFloor.h"
#include "CClearStage.h"
#include "CClearStageGimmick.h"

int CField::mClearCount = 0;
int CField::mStageCount = 0;
int CField::mClearCountSwitch = 0;
int CField::mStageCreateSwitch = 0;
int CField::mStageReset = 0;

CField::CField()
	: CObjectBase(ETag::eField, ETaskPriority::eBackground)
	, mpClearStageGimmick(nullptr)
{
	mpModel = new CModel();
	mpModel->Load("Field\\field.obj", "Field\\field.mtl");

	mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel);

	/*mpStageManager = new CStageManager();*/

	CreateFieldObjects();
}

CField::~CField()
{
	if (mpModel != nullptr)
	{
		delete mpModel;
		mpModel = nullptr;
	}

	if (mpColliderMesh != nullptr)
	{
		delete mpColliderMesh;
		mpColliderMesh = nullptr;
	}

	if (mpCubeModel != nullptr)
	{
		delete mpCubeModel;
		mpCubeModel = nullptr;
	}

	if (mpCylinderModel != nullptr)
	{
		delete mpCubeModel;
		mpCubeModel = nullptr;
	}
}

void CField::CreateFieldObjects()
{
	mpCubeModel = new CModel();
	mpCubeModel->Load("Field\\Object\\cube.obj", "Field\\Object\\cube.mtl");

	mpCylinderModel = new CModel();
	mpCylinderModel->Load("Field\\Object\\cylinder.obj", "Field\\Object\\cylinder.mtl");

	mpClearModel = new CModel();
	mpClearModel->Load("Field\\Object\\Coin2.obj", "Field\\Object\\Coin2.mtl");

	/*new CMoveFloor
	(
		mpCubeModel,
		CVector(0.0f, 2.0f, -50.0f), CVector(1.0f, 4.0f, 1.0f),
		CVector(50.0f, 0.0f, 0.0f), 5.0f
	);
	new CRotateFloor
	(
		mpCylinderModel,
		CVector(-40.0f, 15.0f, 20.0f), CVector(1.0f, 4.0f, 1.0f),
		1.0f
	);*/

	// “®‚©‚È‚¢°‡@
	new CMoveFloor
	(
		mpCubeModel,
		CVector(20.0f, 2.0f, 0.0f), CVector(0.5f, 4.0f, 1.25f),
		CVector(0.0f, 0.0f, 0.0f), 5.0f
	);

	// “®‚©‚È‚¢°‡@
	new CMoveFloor
	(
		mpCubeModel,
		CVector(20.0f, 2.0f, -20.0f), CVector(0.5f, 4.0f, 1.25f),
		CVector(0.0f, 0.0f, 0.0f), 5.0f
	);

	// “®‚©‚È‚¢°‡@
	new CMoveFloor
	(
		mpCubeModel,
		CVector(20.0f, 2.0f, -40.0f), CVector(0.5f, 4.0f, 1.25f),
		CVector(0.0f, 0.0f, 0.0f), 5.0f
	);

	//ƒNƒŠƒA°
	new CClearStage
	(
		mpClearModel,
		CVector(20.0f,0.0f, -140.0f),CVector(5.5f, 5.0f, 5.25f)
	);
	new CClearStage
	(
		mpClearModel,
		CVector(60.0f, 0.0f, -140.0f), CVector(5.5f, 5.0f, 5.25f)
	);
	//// “®‚­°‡@
	//new CMoveFloor
	//(
	//	mpCubeModel,
	//	CVector(60.0f, 2.0f, 0.0f), CVector(0.25f, 4.0f, 0.25f),
	//	CVector(20.0f, 0.0f, 0.0f), 5.0f
	//);
	//// “®‚©‚È‚¢°‡A
	//new CMoveFloor
	//(
	//	mpCubeModel,
	//	CVector(100.0f, 20.0f, 0.0f), CVector(0.25f, 4.0f, 0.25f),
	//	CVector(0.0f, 0.0f, 0.0f), 5.0f
	//);
	//// ‰ñ“]‚·‚é°‡@
	//new CRotateFloor
	//(
	//	mpCubeModel,
	//	CVector(135.0f, 10.0f, 0.0f), CVector(1.0f, 4.0f, 0.25f),
	//	0.5f
	//);
	//// “®‚©‚È‚¢°‡A
	//new CMoveFloor
	//(
	//	mpCubeModel,
	//	CVector(135.0f, 20.0f, -35.0f), CVector(0.25f, 4.0f, 0.25f),
	//	CVector(0.0f, 0.0f, 0.0f), 5.0f
	//);
	//// “®‚©‚È‚¢°‡A
	//new CMoveFloor
	//(
	//	mpCubeModel,
	//	CVector(135.0f, 70.0f, -52.5f), CVector(0.25f, 4.0f, 0.25f),
	//	CVector(0.0f, 50.0f, 0.0f), 5.0f
	//);
}

void CField::Update()
{
	printf("%d,", mStageCount);
	printf("%d,", mClearCountSwitch);
	if (mClearCount == 1 && mClearCountSwitch == 1)
	{
		mStageCount++;
		if (mStageCount == 1)
		{
			mpClearStageGimmick = new CClearStageGimmick();
			mClearCount = 0;
			mClearCountSwitch = 0;
			mStageCreateSwitch = 0;
		}
		if (mStageCount == 2)
		{
			delete mpClearStageGimmick;
			mpClearStageGimmick = nullptr;
			mpClearStageGimmick = new CClearStageGimmick();
			mClearCount = 0;
			mClearCountSwitch = 0;
			mStageCreateSwitch = 0;
		}
		if (mStageCount == 3)
		{
			delete mpClearStageGimmick;
			mpClearStageGimmick = nullptr;
			mpClearStageGimmick = new CClearStageGimmick();
			mClearCount = 0;
			mClearCountSwitch = 0;
			mStageCreateSwitch = 0;
		}
		if (mStageCount == 4)
		{
			delete mpClearStageGimmick;
			mpClearStageGimmick = nullptr;
			mpClearStageGimmick = new CClearStageGimmick();
			mClearCount = 0;
			mClearCountSwitch = 0;
			mStageCreateSwitch = 0;
		}
		if (mStageCount == 5)
		{
			delete mpClearStageGimmick;
			mpClearStageGimmick = nullptr;
			mpClearStageGimmick = new CClearStageGimmick();
			mClearCount = 0;
			mClearCountSwitch = 0;
			mStageCreateSwitch = 0;
		}
	}
}

void CField::Render()
{
	mpModel->Render(Matrix());
}
