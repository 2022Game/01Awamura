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

CField::CField()
	: CObjectBase(ETag::eField, ETaskPriority::eBackground)
	, mpClearStageGimmick(nullptr)
	,mpFloorGimmick(nullptr)
	,mpAxeGimmick(nullptr)
{
	/*mpModel = new CModel();
	mpModel->Load("Field\\field.obj", "Field\\field.mtl");

	mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel)*/;

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

	// �����Ȃ����@
	//new CMoveFloor
	//(
	//	mpCubeModel,
	//	CVector(20.0f, 2.0f, 0.0f), CVector(0.5f, 4.0f, 1.25f),
	//	CVector(0.0f, 0.0f, 0.0f), 5.0f
	//);

	//// �����Ȃ����@
	//new CMoveFloor
	//(
	//	mpCubeModel,
	//	CVector(20.0f, 2.0f, -20.0f), CVector(0.5f, 4.0f, 1.25f),
	//	CVector(0.0f, 0.0f, 0.0f), 5.0f
	//);

	// �����Ȃ����@
	new CMoveFloor
	(
		mpCubeModel,
		CVector(0.0f, 2.0f, -60.0f), CVector(0.5f, 4.0f, 5.0f),
		CVector(0.0f, 0.0f, 0.0f), 5.0f
	);

	//�N���A��
	new CClearStage
	(
		mpClearModel,
		CVector(-20.0f,0.0f, -140.0f),CVector(5.5f, 5.0f, 5.25f)
	);
	new CClearStage
	(
		mpClearModel,
		CVector(20.0f, 0.0f, -140.0f), CVector(5.5f, 5.0f, 5.25f)
	);

	//�e�X�g�p�ɃN���A���f�����g�p
	/*new CFloor
	(
		mpClearModel,
		CVector(0.0f, 220.0f, -140.0f), CVector(5.5f, 5.0f, 5.25f)
	);*/
	/*new CAxe
	(
		mpAxeModel,
		CVector(0.0f, 200.0f, -140.0f), CVector(5.5f, 5.0f, 5.25f)
	);*/
	//// �������@
	//new CMoveFloor
	//(
	//	mpCubeModel,
	//	CVector(60.0f, 2.0f, 0.0f), CVector(0.25f, 4.0f, 0.25f),
	//	CVector(20.0f, 0.0f, 0.0f), 5.0f
	//);
	//// �����Ȃ����A
	//new CMoveFloor
	//(
	//	mpCubeModel,
	//	CVector(100.0f, 20.0f, 0.0f), CVector(0.25f, 4.0f, 0.25f),
	//	CVector(0.0f, 0.0f, 0.0f), 5.0f
	//);
	//// ��]���鏰�@
	//new CRotateFloor
	//(
	//	mpCubeModel,
	//	CVector(135.0f, 10.0f, 0.0f), CVector(1.0f, 4.0f, 0.25f),
	//	0.5f
	//);
	//// �����Ȃ����A
	//new CMoveFloor
	//(
	//	mpCubeModel,
	//	CVector(135.0f, 20.0f, -35.0f), CVector(0.25f, 4.0f, 0.25f),
	//	CVector(0.0f, 0.0f, 0.0f), 5.0f
	//);
	//// �����Ȃ����A
	//new CMoveFloor
	//(
	//	mpCubeModel,
	//	CVector(135.0f, 70.0f, -52.5f), CVector(0.25f, 4.0f, 0.25f),
	//	CVector(0.0f, 50.0f, 0.0f), 5.0f
	//);
}

void CField::Update()
{
	if (mClearCount == 1 && mClearCountSwitch == 1)
	{
		mStageCount++;
		if (mStageCount == 1)
		{
			if (mpClearStageGimmick != nullptr)
			{
				mpClearStageGimmick->Kill();
				mpClearStageGimmick = nullptr;
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
			/*if (mpFloorGimmick != nullptr)
			{
				mpFloorGimmick->Kill();
				mpFloorGimmick = nullptr;
			}*/
			//mpFloorGimmick = new CFloorGimmick();
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
