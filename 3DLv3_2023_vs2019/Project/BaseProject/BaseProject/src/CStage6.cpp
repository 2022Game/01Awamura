#include "CStage6.h"
#include "CClearStage.h"
#include "CPlayer.h"
#include "CFloor.h"
#include "CMoveField.h"
#include "CCamera.h"
#include "CClearCube.h"

//�R���X�g���N�^
CStage6::CStage6()
{
	mStageNo = 6;
}

//�f�X�g���N�^
CStage6::~CStage6()
{

}

//�X�e�[�W�ǂݍ���
void CStage6::Load()
{
	//���ʂ̑���ǂݍ���
	CModel* floorModel = CResourceManager::Get<CModel>("FieldCube");

	//�\���y��ǂݍ���
	CModel* moveTenModel = CResourceManager::Get<CModel>("Tenfield");

	//�\���y��ǂݍ���
	CModel* moveTenPurpleModel = CResourceManager::Get<CModel>("TenfieldPurple");

	//�\���y��ǂݍ���
	CModel* moveTenSkyblueModel = CResourceManager::Get<CModel>("TenfieldSkyblue");

	//�\���y��ǂݍ���
	CModel* moveTenYellowModel = CResourceManager::Get<CModel>("TenfieldYellow");

	// �N���A�y��̃��f���ǂݍ���
	CModel* clearCubeStageModel = CResourceManager::Get<CModel>("Clearcube");

	//���ʂ̑���
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f,-10.0f, 240.0f), CVector(5.0f, 4.0f, 0.5f));
	AddTask(floor);

	//�\���y����쐬
	CMoveField* tenfield = new CMoveField(moveTenModel,
		CVector(0.0f, -5.0f, 182.5f), CVector(12.5f, 12.5f, 12.5f)
		, 0.0f);
	AddTask(tenfield);

	tenfield = new CMoveField(moveTenPurpleModel,
		CVector(0.0f, -6.0f, 122.5f), CVector(12.5f, 12.5f, 12.5f)
		, 0.0f);
	AddTask(tenfield);

	tenfield = new CMoveField(moveTenSkyblueModel,
		CVector(0.0f, -7.0f, 62.5f), CVector(12.5f, 12.5f, 12.5f)
		, 0.0f);
	AddTask(tenfield);

	tenfield = new CMoveField(moveTenYellowModel,
		CVector(0.0f, -8.0f, 2.5f), CVector(12.5f, 12.5f, 12.5f)
		, 0.0f);
	AddTask(tenfield);

	//�N���A�y����쐬
	CClearCube* coin = new CClearCube(clearCubeStageModel,
		CVector(0.0f, -7.0f, -62.0f), CVector(5.0f, 1.0f, 1.0f));
	AddTask(coin);

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
		CVector eye = playerPos + CVector(0.0f, 50.0f, 100.0f);
		CVector at = playerPos;
		CVector forward = (at - eye).Normalized();
		CVector side = CVector::Cross(forward, CVector::up);
		CVector up = CVector::Cross(side, forward);
		mainCamera->LookAt(eye, at, up);
		mainCamera->SetFollowTargetTf(player);
	}
}

//�X�e�[�W�j��
void CStage6::Unload()
{
	//�x�[�X�̃X�e�[�W�j������
	CStageBase::Unload();
}