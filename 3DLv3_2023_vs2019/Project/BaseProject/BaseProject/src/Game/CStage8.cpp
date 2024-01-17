#include "CStage8.h"
#include "CClearCube.h"
#include "CFloor.h"
#include "Maths.h"
#include "CPlayer.h"
#include "CCamera.h"
#include "CIceField.h"
#include "CCube.h"

//�R���X�g���N�^
CStage8::CStage8()
{
	mStageNo = 8;
}

//�f�X�g���N�^
CStage8::~CStage8()
{

}

//�X�e�[�W�ǂݍ���
void CStage8::Load()
{
	//���ʂ̑���ǂݍ���
	CModel* floorModel = CResourceManager::Get<CModel>("FieldCube");

	//�Ǔǂݍ���
	CModel* cubeModel = CResourceManager::Get<CModel>("Cube");

	//���鑫��ǂݍ���
	CModel* icefieldModel = CResourceManager::Get<CModel>("IceField");

	// �N���A�y��̃��f���ǂݍ���
	CModel* clearCubeStageModel = CResourceManager::Get<CModel>("Clearcube");


	//���ʂ̑���
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, -10.0f, 0.0f), CVector(5.0f, 4.0f, 1.0f));
	AddTask(floor);

	//��
	CCube* cube = new CCube(cubeModel,
		CVector(0.0f, 10.0f, -100.0f), CVector(0.5f, 5.0f, 0.5f));
	AddTask(cube);

	//���鑫��
	CIceField* icefield = new CIceField(icefieldModel,
		CVector(0.0f, -10.0f, -150.0f), CVector(5.0f, 4.0f, 5.0f));
	AddTask(icefield);

	//�N���A�y����쐬
	CClearCube* coin = new CClearCube(clearCubeStageModel,
		CVector(0.0f, -10.0f, -300.0f), CVector(5.0f, 4.0f, 1.0f));
	AddTask(coin);

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
void CStage8::Unload()
{
	//�x�[�X�̃X�e�[�W�j������
	CStageBase::Unload();
}