#include "CStage7.h"
#include "CClearStage.h"
#include "CFloor.h"
#include "CPlayer.h"
#include "CCamera.h"
#include "CDisappearFloor.h"
#include "Maths.h"

//�R���X�g���N�^
CStage7::CStage7()
	:RandPos(0)
	, RandPos2(0)
	, RandPos3(0)
	, RandPosX(0)
	, RandPosX2(0)
	, RandPosZ(0)
	, RandPosZ2(0)
	, PosY(0)
	, PosY2(0)
	, RandPosDate(0)
	, RandPosDate2(0)
	, RandPosDate3(0)
	, RandPosDate4(0)
	, RandPosDate5(0)
	, RandPosDate6(0)
	,z(8)
{
	mStageNo = 7;
	PosY = 380.0f;
	PosY2 = -200.0f;
	PosZ = 215.0f;
}

//�f�X�g���N�^
CStage7::~CStage7()
{

}

//�X�e�[�W�ǂݍ���
void CStage7::Load()
{
	// �N���A�y��̃��f���ǂݍ���
	CModel* clearStageModel = CResourceManager::Get<CModel>("Clearstage");

	//���ʂ̑���ǂݍ���
	CModel* floorModel = CResourceManager::Get<CModel>("FieldCube");

	//�����̑���ǂݍ���
	CModel* cubecolModel = CResourceManager::Get<CModel>("Cubecol");

	//�N���A�y����쐬
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, -300.0f, 0.0f), CVector(0.8f, 5.0f, 0.8f));
	AddTask(coin);

	//���ʂ̑���
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, -10.0f, 240.0f), CVector(4.4f, 4.0f, 0.5f));
	AddTask(floor);
	floor = new CFloor(floorModel,
		CVector(0.0f, -10.0f, 43.5f), CVector(4.4f, 4.0f, 0.5f));
	AddTask(floor);

	for (int a = 0; a < 7; a++)
	{
		//�d�����Ȃ������_���̐����p�̔z��
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
		for (int i = 0; i < 7; i++)
		{
			//�d�����Ȃ������_���̐���
			int x;
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
				RandPosX = 24.5f;
				break;
			case 2:
				RandPosX = -24.5f;
				break;
			case 3:
				RandPosX = -49.0f;
				break;
			case 4:
				RandPosX = 49.0f;
				break;
			case 5:
				RandPosX = -73.5f;
				break;
			case 6:
				RandPosX = 73.5f;
				break;
			case 7:
				RandPosX = 98.0f;
				break;
			case 8:
				RandPosX = -98.0f;
				break;
			};
			//���ߓy��
			CDisappearFloor* dfloor = new CDisappearFloor
			(
				CVector(RandPosX, -10.0f, PosZ), CVector(0.5f, 4.0f, 0.5f),
				ETag::ePlayer, ELayer::ePlayer
			);
		}
		PosZ = PosZ - 24.5f;
	}

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
		CVector eye = playerPos + CVector(0.0f, 150.0f, 150.0f);
		CVector at = playerPos;
		CVector forward = (at - eye).Normalized();
		CVector side = CVector::Cross(forward, CVector::back);
		CVector up = CVector::Cross(side, forward);
		mainCamera->LookAt(eye, at, up);
		mainCamera->SetFollowTargetTf(player);
	}
}

//�X�e�[�W�j��
void CStage7::Unload()
{
	//�x�[�X�̃X�e�[�W�j������
	CStageBase::Unload();
}