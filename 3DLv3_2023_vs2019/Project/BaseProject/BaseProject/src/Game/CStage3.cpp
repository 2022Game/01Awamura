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
#include "CPlayer.h"
#include "CCamera.h"
#include "CGameManager.h"

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
	CModel* floorModel = CResourceManager::Get<CModel>("FieldCube");

	// �N���A�y��̃��f���ǂݍ���
	CModel* clearStageModel = CResourceManager::Get<CModel>("Clearstage");

	// ���X�C�b�`�̃��f���ǂݍ���
	CModel* switchLModel = CResourceManager::Get<CModel>("Lswitch");

	// �E�X�C�b�`�̃��f���ǂݍ���
	CModel* switchRModel = CResourceManager::Get<CModel>("Rswitch");

	//�\���y��ǂݍ���
	CModel* moveTenModel = CResourceManager::Get<CModel>("Tenfield");

	// I���y��ǂݍ���
	CModel* moveIModel = CResourceManager::Get<CModel>("Ifield");

	// T���y��̃��f���ǂݍ���
	CModel* moveTModel = CResourceManager::Get<CModel>("Tfield");

	//J���y��̃��f���ǂݍ���
	CModel* moveJModel = CResourceManager::Get<CModel>("Jfield");

	//L���y��̃��f���ǂݍ���
	CModel* moveLModel = CResourceManager::Get<CModel>("Lfield");

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
		CVector(0.0f, -5.0f, 10.0f), CVector(13.5f, 12.5f, 13.5f)
		,0.0f);
	AddTask(tenfield);

	//I���y����쐬
	CIMoveField* ifield = new CIMoveField(moveIModel,
		CVector(80.0f, -5.0f, 178.5f), CVector(13.5f, 12.5f, 13.5f)
		,0.0f);
	AddTask(ifield);

	//T���y����쐬
	CTMoveField* tfield = new CTMoveField(moveTModel,
		CVector(0.0f, -5.0f, 178.5f), CVector(13.5f, 12.5f, 13.5f)
		,0.0f);
	AddTask(tfield);
	tfield = new CTMoveField(moveTModel,
		CVector(80.0f, -5.0f, 100.0f), CVector(13.5f, 12.5f, 13.5f)
		, 0.0f);
	AddTask(tfield);
	tfield = new CTMoveField(moveTModel,
		CVector(-80.0f, -5.0f, 100.0f), CVector(13.5f, 12.5f, 13.5f)
		, 0.0f);
	AddTask(tfield);
	tfield = new CTMoveField(moveTModel,
		CVector(70.0f, -5.0f, -50.0f), CVector(13.5f, 12.5f, 13.5f)
		, 0.0f);
	AddTask(tfield);
	tfield = new CTMoveField(moveTModel,
		CVector(-70.0f, -5.0f, -50.0f), CVector(13.5f, 12.5f, 13.5f)
		, 0.0f);
	AddTask(tfield);

	//J���y����쐬
	CJMoveField* jfield = new CJMoveField(moveJModel,
		CVector(0.0f, -5.0f, 110.0f), CVector(13.5f, 12.5f, 13.5f)
		, 0.0f);
	AddTask(jfield);
	jfield = new CJMoveField(moveJModel,
		CVector(-80.0f, -5.0f, 20.0f), CVector(13.5f, 12.5f, 13.5f)
		, 0.0f);
	AddTask(jfield);

	//L���y����쐬
	CLMoveField* lfield = new CLMoveField(moveLModel,
		CVector(80.0f, -5.0f, 20.0f), CVector(13.5f, 12.5f, 13.5f)
		, 0.0f);
	AddTask(lfield);
	lfield = new CLMoveField(moveLModel,
		CVector(-80.0f, -5.0f, 178.5f), CVector(13.5f, 12.5f, 13.5f)
		, 0.0f);
	AddTask(lfield);

	//�v���C���[�̊J�n�ʒu��ݒ�
	CPlayer* player = CPlayer::Instance();
	CVector playerPos = CVector(0.0f, 30.0f, 240.0f);
	if (player != nullptr)
	{
		player->SetStartPosition(playerPos);
	}

	//�J�����̈ʒu�ƌ�����ݒ�
	CCamera* mainCamera = CCamera::MainCamera();
	if (mainCamera != nullptr)
	{
		CVector eye = playerPos + CVector(0.0f, 150.0f, 200.0f);
		CVector at = playerPos;
		CVector forward = (at - eye).Normalized();
		CVector side = CVector::Cross(forward, CVector::up);
		CVector up = CVector::Cross(side, forward);
		mainCamera->LookAt(eye, at, up);
		mainCamera->SetFollowTargetTf(player);
	}
}

//�X�e�[�W�j��
void CStage3::Unload()
{
	//�x�[�X�̃X�e�[�W�j������
	CStageBase::Unload();
}