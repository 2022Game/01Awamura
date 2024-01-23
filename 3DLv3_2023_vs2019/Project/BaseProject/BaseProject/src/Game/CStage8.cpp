#include "CStage8.h"
#include "CClearCube.h"
#include "CFloor.h"
#include "Maths.h"
#include "CPlayer.h"
#include "CCamera.h"
#include "CIceField.h"
#include "CCube.h"
#include "CGameManager.h"

//�R���X�g���N�^
CStage8::CStage8()
	:PosZ(0)
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
		CVector(0.0f, -10.0f, 0.0f), CVector(4.5f, 4.0f, 1.0f));
	AddTask(floor);

	PosZ = -35.0f;

	for (int a = 0; a < 10; a++)
	{
		//�d�����Ȃ������_���̐����p�̔z��
		int z;
		int n[9];
		n[0] = 0;
		n[1] = 1;
		n[2] = 2;
		n[3] = 3;
		n[4] = 4;
		n[5] = 5;
		n[6] = 6;
		n[7] = 7;
		n[8] = 8;
		z = 8;
		for (int i = 0; i < 2; i++)
		{
			//�d�����Ȃ������_���̐���
			int x;
			int RandPos;
			int RandPosX;
			x = Math::Rand(0, z);
			RandPos = n[x];
			n[x] = n[z];
			z = z - 1;
			//�������y����쐬
			switch (RandPos)
			{
			case 0:
				RandPosX = 0.0f;
				break;
			case 1:
				RandPosX = 25.0f;
				break;
			case 2:
				RandPosX = 50.0f;
				break;
			case 3:
				RandPosX = 75.0f;
				break;
			case 4:
				RandPosX = 100.0f;
				break;
			case 5:
				RandPosX = -25.0f;
				break;
			case 6:
				RandPosX = -50.0f;
				break;
			case 7:
				RandPosX = -75.0f;
				break;
			case 8:
				RandPosX = -100.0f;
				break;
			};
			//���ߓy��
			CCube* cube = new CCube(cubeModel,
				CVector(RandPosX, 10.0f, PosZ), CVector(0.5f, 4.0f, 0.5f));
			AddTask(cube);
		}
		PosZ = PosZ - 25.25f;
	}

	//���鑫��
	CIceField* icefield = new CIceField(icefieldModel,
		CVector(0.0f, -10.0f, -150.0f), CVector(4.5f, 4.0f, 5.0f));
	AddTask(icefield);

	//�N���A�y����쐬
	CClearCube* coin = new CClearCube(clearCubeStageModel,
		CVector(0.0f, -10.0f, -300.0f), CVector(4.5f, 4.0f, 1.0f));
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
		CVector eye = playerPos + CVector(0.0f, 375.0f, 130.0f);
		CVector at = playerPos;
		CVector forward = (at - eye).Normalized();
		CVector side = CVector::Cross(forward, CVector::back);
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