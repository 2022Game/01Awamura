#include "CStage1.h"
#include "CClearStage.h"
#include "CAxe.h"
#include "CFloor.h"
#include "CWarp.h"

//�R���X�g���N�^
CStage1::CStage1()
{
	mStageNo = 1;
}

//�f�X�g���N�^
CStage1::~CStage1()
{

}

//�X�e�[�W�ǂݍ���
void CStage1::Load()
{
	//���ʂ̑���ǂݍ���
	CModel* floorModel = CResourceManager::Get<CModel>("FieldCube");

	//���[�v���ǂݍ���
	CModel* warpModel = CResourceManager::Get<CModel>("Warp");

	// �N���A�y��̃��f���ǂݍ���
	CModel* clearStageModel = CResourceManager::Get<CModel>("Clearstage");

	// ���̃��f���ǂݍ���
	CModel* axeModel = CResourceManager::Get<CModel>("Axe");

	//���ʂ̑���
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, 2.0f, -20.0f), CVector(0.5f, 4.0f, 5.0f));
	AddTask(floor);

	//���[�v�����쐬
	CWarp* warp = new CWarp(warpModel,
		CVector(0.0f, 10.0f, -100.0f), CVector(6.0f, 3.0f, 10.0f));
	AddTask(warp);

	//�N���A�y����쐬
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, -5.0f, -20.0f), CVector(1.0f, 1.0f, 1.0f));
	AddTask(coin);

	//�����쐬
	CAxe* axe = new CAxe(axeModel,
		CVector(0.0f, 200.0f, -140.0f), CVector(5.5f, 5.0f, 5.25f)
		,5.0f, 45.0f);
	AddTask(axe);
	axe = new CAxe(axeModel,
		CVector(0.0f, 200.0f, -80.0f), CVector(5.5f, 5.0f, 5.25f)
		, 5.0f, -45.0f);
	AddTask(axe);
}

//�X�e�[�W�j��
void CStage1::Unload()
{
	//�x�[�X�̃X�e�[�W�j������
	CStageBase::Unload();
}