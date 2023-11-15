#include "CField.h"
#include "CCollisionManager.h"
#include "CMoveFloor.h"
#include "CRotateFloor.h"
#include "CClearStage.h"
#include "CFloor.h"
#include "CFloorGimmick.h"
#include "CClearStageGimmick.h"

int CField::mClearCount = 0;
int CField::mStageCount = 0;
int CField::mClearCountSwitch = 0;
int CField::mStageCreateSwitch = 0;
int CField::mStageReset = 0;
int CField::mStartSwitch = 0;

CField::CField()
	: CObjectBase(ETag::eField, ETaskPriority::eBackground)
	, mpClearStageGimmick(nullptr)
	,mpFloorGimmick(nullptr)
	,mpAxeGimmick(nullptr)
{
	/*mpModel = new CModel();
	mpModel->Load("Field\\field.obj", "Field\\field.mtl");

	mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel, true);*/;

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

	if (mpColliderSphere != nullptr)
	{
		delete mpColliderSphere;
		mpColliderSphere = nullptr;
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

	if (mpAxeModel != nullptr)
	{
		delete mpAxeModel;
		mpAxeModel = nullptr;
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

	//// 動かない床①
	//new CMoveFloor
	//(
	//	mpCubeModel,
	//	CVector(0.0f, 2.0f, -20.0f), CVector(0.5f, 4.0f, 5.0f),
	//	CVector(0.0f, 0.0f, 0.0f), 5.0f
	//);

	////クリア床
	//new CFloor
	//(
	//	mpCubeModel,
	//	CVector(0.0f,10.0f, -100.0f),CVector(0.5f, 5.0f, -0.5f)
	//);
	//new CClearStage
	//(
	//	mpClearModel,
	//	CVector(20.0f, 0.0f, -60.0f), CVector(5.5f, 5.0f, 5.25f)
	//);
}

void CField::Update()
{
	//初期ステージ
	if (mStageCount == 0 && mStartSwitch == 0)
	{
		mpFloorGimmick = new CFloorGimmick();
		mpWarpGimmick = new CWarpGimmick();
		mStartSwitch = 1;
	}
	//ステージ１
	if (mClearCount == 1 && mClearCountSwitch == 1)
	{
		mStageCount++;
		if (mStageCount == 1)
		{
			if (mpWarpGimmick != nullptr)
			{
				mpWarpGimmick->Kill();
				mpWarpGimmick = nullptr;
			}
			if (mpFloorGimmick != nullptr)
			{
				mpFloorGimmick->Kill();
				mpFloorGimmick = nullptr;
			}
			mpClearStageGimmick = new CClearStageGimmick();
			mpAxeGimmick = new CAxeGimmick();
			mpFloorGimmick = new CFloorGimmick();
			mClearCount = 0;
			mClearCountSwitch = 0;
			mStageCreateSwitch = 0;
		}
		//ステージ２
		if (mStageCount == 2)
		{
			if (mpClearStageGimmick != nullptr)
			{
				mpClearStageGimmick->Kill();
				mpClearStageGimmick = nullptr;
			}
			if (mpAxeGimmick != nullptr)
			{
				mpAxeGimmick->Kill();
				mpAxeGimmick = nullptr;
			}
			if (mpFloorGimmick != nullptr)
			{
				mpFloorGimmick->Kill();
				mpFloorGimmick = nullptr;
			}
			mpFloorGimmick = new CFloorGimmick();
			mpClearStageGimmick = new CClearStageGimmick();
			mClearCount = 0;
			mClearCountSwitch = 0;
			mStageCreateSwitch = 0;
		}
		if (mStageCount == 3)
		{
			if (mpClearStageGimmick != nullptr)
			{
				mpClearStageGimmick->Kill();
				mpClearStageGimmick = nullptr;
			}
			/*if (mpFloorGimmick != nullptr)
			{
				mpFloorGimmick->Kill();
				mpFloorGimmick = nullptr;
			}*/
			mpClearStageGimmick = new CClearStageGimmick();
			mClearCount = 0;
			mClearCountSwitch = 0;
			mStageCreateSwitch = 0;
		}
		if (mStageCount == 4)
		{
			if (mpClearStageGimmick != nullptr)
			{
				mpClearStageGimmick->Kill();
				mpClearStageGimmick = nullptr;
			}
			/*if (mpFloorGimmick != nullptr)
			{
				mpFloorGimmick->Kill();
				mpFloorGimmick = nullptr;
			}*/
			mpClearStageGimmick = new CClearStageGimmick();
			mClearCount = 0;
			mClearCountSwitch = 0;
			mStageCreateSwitch = 0;
		}
		if (mStageCount == 5)
		{
			if (mpClearStageGimmick != nullptr)
			{
				mpClearStageGimmick->Kill();
				mpClearStageGimmick = nullptr;
			}
			mpClearStageGimmick = new CClearStageGimmick();
			mClearCount = 0;
			mClearCountSwitch = 0;
			mStageCreateSwitch = 0;
		}
	}
}

void CField::Render()
{
	//mpModel->Render(Matrix());
}
