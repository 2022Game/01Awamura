#include "CStage2.h"
#include "CClearCube.h"
#include "CSlope.h"
#include "CFloor.h"
#include "CStone.h"
#include "Maths.h"
#include "CPlayer.h"
#include "CCamera.h"
#include "CAppearFloor.h"

//�R���X�g���N�^
CStage2::CStage2()
{
	mStageNo = 2;
}

//�f�X�g���N�^
CStage2::~CStage2()
{

}

//�X�e�[�W�ǂݍ���
void CStage2::Load()
{
	//���ʂ̑���ǂݍ���
	CModel* floorModel = CResourceManager::Get<CModel>("FieldCube");

	// �N���A�y��̃��f���ǂݍ���
	CModel* clearCubeStageModel = CResourceManager::Get<CModel>("Clearcube");

	// �⓹�y��̃��f���ǂݍ���
	CModel* slopeModel = CResourceManager::Get<CModel>("Slope");

	// ��΂̃��f���ǂݍ���
	CModel* stoneModel = CResourceManager::Get<CModel>("Stone");


	//���ʂ̑���
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, -10.0f, 0.0f), CVector(5.0f, 4.0f, 1.0f));
	AddTask(floor);

	//�N���A�y����쐬
	CClearCube* coin = new CClearCube(clearCubeStageModel,
		CVector(0.0f, 70.0f, -300.0f), CVector(5.0f, 1.0f, 1.0f));
	AddTask(coin);

	//�⓹���쐬
	CSlope* slope = new CSlope(slopeModel,
		CVector(0.0f, -10.0f, -150.0f), CVector(5.0f, 4.0f, 5.0f));
	AddTask(slope);

	//��΂��쐬
	for (int i = 0; i < 15 ; i++)
	{
		CStone* stone = new CStone(stoneModel,
			CVector(Math::Rand(-100, 100), 240.0f, -260.0f), CVector(10.0f, 10.0f, 10.0f), 0.0f);
		AddTask(stone);
	}

	CAppearFloor* afloor = new CAppearFloor
	(
		CVector(0.0f, -10.0f, 37.5f), CVector(0.5f, 4.0f, 0.5f),
		ETag::eStone, ELayer::eStone
	);
	AddTask(afloor);

	afloor = new CAppearFloor
	(
		CVector(0.0f, -10.0f, 37.5f + 25.0f), CVector(0.5f, 4.0f, 0.5f),
		ETag::eStone, ELayer::eStone
	);
	AddTask(afloor);

	//�v���C���[�̊J�n�ʒu��ݒ�
	CPlayer* player = CPlayer::Instance();
	CVector playerPos = CVector(0.0f, 30.0f, 0.0f);
	if (player != nullptr)
	{
		player->SetStartPosition(playerPos);
	}

	//�J�����̈ʒu�ƌ�����ݒ�
	CCamera* mainCamera = CCamera::MainCamera();
	if (mainCamera != nullptr)
	{
		CVector eye = CVector(0.0f, 50.0f, 75.0f);
		CVector at = playerPos;
		CVector forward = (at - eye).Normalized();
		CVector side = CVector::Cross(forward, CVector::up);
		CVector up = CVector::Cross(side, forward);
		mainCamera->LookAt(eye, at, up);
		mainCamera->SetFollowTargetTf(player);
	}
}

//�X�e�[�W�j��
void CStage2::Unload()
{
	//�x�[�X�̃X�e�[�W�j������
	CStageBase::Unload();
}