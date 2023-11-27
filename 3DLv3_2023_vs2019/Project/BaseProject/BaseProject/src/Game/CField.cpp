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
int CField::mDeleteSwitch = 0;

CField::CField()
	: CObjectBase(ETag::eField, ETaskPriority::eBackground)
	, mpClearStageGimmick(nullptr)
	,mpFloorGimmick(nullptr)
	,mpAxeGimmick(nullptr)
	,mpSlopeGimmick(nullptr)
	,mpWarpGimmick(nullptr)
	,mpClearCubeGimmick(nullptr)
	,mpStornGimmick(nullptr)
	,mpMoveFieldGimmick(nullptr)
	,mpTMoveFieldGimmick(nullptr)
	, mpIMoveFieldGimmick(nullptr)
	, mpLMoveFieldGimmick(nullptr)
	, mpJMoveFieldGimmick(nullptr)
{
	mpModel = new CModel();
	//仮のフィールドデータ　ピンクな背景モデルが有れば入れる
	mpModel->Load("Field\\Dublesky4.obj", "Field\\Dublesky4.mtl");

	//mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel, true);;

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
}

void CField::CreateFieldObjects()
{
	mpCubeModel = new CModel();
	mpCubeModel->Load("Field\\Object\\cube.obj", "Field\\Object\\cube.mtl");

	mpCylinderModel = new CModel();
	mpCylinderModel->Load("Field\\Object\\cylinder.obj", "Field\\Object\\cylinder.mtl");

	mpClearModel = new CModel();
	mpClearModel->Load("Field\\Object\\Coin2.obj", "Field\\Object\\Coin2.mtl");
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
	//ステージ生成
	if (mClearCount == 1 && mClearCountSwitch == 1)
	{
		//ステージ番号
		//mStageCount++;
		// テスト用
		mStageCount = 2;
		//ステージが切り替わった時に元のステージを削除
		if (mStageCount != mDeleteSwitch)
		{
			if (mpWarpGimmick != nullptr)
			{
				mpWarpGimmick->Kill();
				mpWarpGimmick = nullptr;
			}
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
			if (mpClearCubeGimmick != nullptr)
			{
				mpClearCubeGimmick->Kill();
				mpClearCubeGimmick = nullptr;
			}
			if (mpSlopeGimmick != nullptr)
			{
				mpSlopeGimmick->Kill();
				mpSlopeGimmick = nullptr;
			}
			if (mpMoveFieldGimmick != nullptr)
			{
				mpMoveFieldGimmick->Kill();
				mpMoveFieldGimmick = nullptr;
			}
			if (mpTMoveFieldGimmick != nullptr)
			{
				mpTMoveFieldGimmick->Kill();
				mpTMoveFieldGimmick = nullptr;
			}
			if (mpIMoveFieldGimmick != nullptr)
			{
				mpIMoveFieldGimmick->Kill();
				mpIMoveFieldGimmick = nullptr;
			}
			if (mpLMoveFieldGimmick != nullptr)
			{
				mpLMoveFieldGimmick->Kill();
				mpLMoveFieldGimmick = nullptr;
			}
			if (mpJMoveFieldGimmick != nullptr)
			{
				mpJMoveFieldGimmick->Kill();
				mpJMoveFieldGimmick = nullptr;
			}
			mDeleteSwitch = mStageCount;
		}
		//ステージ１
		if (mStageCount == 1)
		{
			mpClearStageGimmick = new CClearStageGimmick();
			mpAxeGimmick = new CAxeGimmick();
			mpFloorGimmick = new CFloorGimmick();
			mpWarpGimmick = new CWarpGimmick();
			mpStornGimmick = new CStornGimmick();
		}
		//ステージ２
		if (mStageCount == 2)
		{
			mpClearCubeGimmick = new CClearCubeGimmick();
			mpSlopeGimmick = new CSlopeGimmick();
			mpFloorGimmick = new CFloorGimmick();
			mpClearStageGimmick = new CClearStageGimmick();
			mpStornGimmick = new CStornGimmick();
		}
		//ステージ３
		if (mStageCount == 3)
		{
			mpStornGimmick = new CStornGimmick();
			mpClearStageGimmick = new CClearStageGimmick();
			//mpMoveFieldGimmick = new CMoveFieldGimmick();
			mpTMoveFieldGimmick = new CTMoveFieldGimmick();
			mpSwitchGimmick = new CSwitchGimmick();
			mpIMoveFieldGimmick = new CIMoveFieldGimmick();
			mpLMoveFieldGimmick = new CLMoveFieldGimmick();
			mpJMoveFieldGimmick = new CJMoveFieldGimmick();
		}
		//ステージ４
		if (mStageCount == 4)
		{
			mpClearStageGimmick = new CClearStageGimmick();
		}
		//ステージ５
		if (mStageCount == 5)
		{
			mpClearStageGimmick = new CClearStageGimmick();
		}

		//ステージ管理用
		mClearCount = 0;
		mClearCountSwitch = 0;
		mStageCreateSwitch = 0;
	}
}

void CField::Render()
{
	mpModel->Render(Matrix());
}
