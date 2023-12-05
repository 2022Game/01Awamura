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


//�R���X�g���N�^
CStage3::CStage3()
{
	mStageNo = 3;
}

//�f�X�g���N�^
CStage3::~CStage3()
{

}

//�X�e�[�W�ǂݍ���
void CStage3::Load()
{
	//���ʂ̑���ǂݍ���
	CModel* floorModel = new CModel();
	floorModel->Load("Field\\Object\\cube.obj", "Field\\Object\\cube.mtl");
	mCreateModels.push_back(floorModel);

	// �N���A�y��̃��f���ǂݍ���
	CModel* clearStageModel = new CModel();
	clearStageModel->Load("Field\\Object\\cylinder.obj", "Field\\Object\\cylinder.mtl");
	mCreateModels.push_back(clearStageModel);

	// ���X�C�b�`�̃��f���ǂݍ���
	CModel* switchLModel = new CModel();
	switchLModel->Load("Field\\Object\\switchBlue.obj", "Field\\Object\\switchBlue.mtl");
	mCreateModels.push_back(switchLModel);

	// �E�X�C�b�`�̃��f���ǂݍ���
	CModel* switchRModel = new CModel();
	switchRModel->Load("Field\\Object\\switchRed.obj", "Field\\Object\\switchRed.mtl");
	mCreateModels.push_back(switchRModel);

	//�\���y��ǂݍ���
	CModel* moveTenModel = new CModel();
	moveTenModel->Load("Field\\Object\\10field.obj", "Field\\Object\\10field.mtl");
	mCreateModels.push_back(moveTenModel);

	// I���y��ǂݍ���
	CModel* moveIModel = new CModel();
	moveIModel->Load("Field\\Object\\Ifield.obj", "Field\\Object\\Ifield.mtl");
	mCreateModels.push_back(moveIModel);

	// T���y��̃��f���ǂݍ���
	CModel* moveTModel = new CModel();
	moveTModel->Load("Field\\Object\\Tfield.obj", "Field\\Object\\Tfield.mtl");
	mCreateModels.push_back(moveTModel);

	//J���y��̃��f���ǂݍ���
	CModel* moveJModel = new CModel();
	moveJModel->Load("Field\\Object\\Jfield.obj", "Field\\Object\\Jfield.mtl");
	mCreateModels.push_back(moveJModel);

	//L���y��̃��f���ǂݍ���
	CModel* moveLModel = new CModel();
	moveLModel->Load("Field\\Object\\Lfield.obj", "Field\\Object\\Lfield.mtl");
	mCreateModels.push_back(moveLModel);

	//���ʂ̑���
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, -10.0f, 240.0f), CVector(5.0f, 4.0f, 0.5f));
	AddTask(floor);

	//�N���A�y����쐬
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, 0.0f, -70.0f), CVector(1.0f, 1.0f, 1.0f));
	AddTask(coin);

	//���X�C�b�`���쐬
	CSwitchLObject* switchl = new CSwitchLObject(switchLModel,
		CVector(-15.0f, -5.0f, 240.0f), CVector(10.0f, 10.0f, 10.0f));
	AddTask(switchl);

	//�E�X�C�b�`���쐬
	CSwitchRObject* switchr = new CSwitchRObject(switchRModel,
		CVector(15.0f, -5.0f, 240.0f), CVector(10.0f, 10.0f, 10.0f));
	AddTask(switchr);

	//�\���y����쐬
	CMoveField* tenfield = new CMoveField(moveTenModel,
		CVector(0.0f, -5.0f, 10.0f), CVector(12.5f, 12.5f, 12.5f)
		,0.0f);
	AddTask(tenfield);

	//I���y����쐬
	CIMoveField* ifield = new CIMoveField(moveIModel,
		CVector(80.0f, -5.0f, 180.0f), CVector(12.5f, 12.5f, 12.5f)
		,0.0f);
	AddTask(ifield);

	//T���y����쐬
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

	//J���y����쐬
	CJMoveField* jfield = new CJMoveField(moveJModel,
		CVector(0.0f, 0.0f, -70.0f), CVector(1.0f, 1.0f, 1.0f)
		, 0.0f);
	AddTask(jfield);
	jfield = new CJMoveField(moveJModel,
		CVector(-80.0f, -5.0f, 20.0f), CVector(12.5f, 12.5f, 12.5f)
		, 0.0f);
	AddTask(jfield);

	//L���y����쐬
	CLMoveField* lfield = new CLMoveField(moveLModel,
		CVector(0.0f, 0.0f, -70.0f), CVector(1.0f, 1.0f, 1.0f)
		, 0.0f);
	AddTask(lfield);
	lfield = new CLMoveField(moveLModel,
		CVector(80.0f, -5.0f, 20.0f), CVector(12.5f, 12.5f, 12.5f)
		, 0.0f);
	AddTask(lfield);
}

//�X�e�[�W�j��
void CStage3::Unload()
{
	//�x�[�X�̃X�e�[�W�j������
	CStageBase::Unload();
}