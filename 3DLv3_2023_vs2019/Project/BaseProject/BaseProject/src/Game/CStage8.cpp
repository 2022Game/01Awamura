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
{
	mStageNo = 8;
}

//�f�X�g���N�^
CStage8::~CStage8()
{

}

//�ǂɂԂ���܂ňړ����āA�ʂ����}�X���ړ����[�g�ɐݒ肷��
int CStage8::PaveTheRoute(int x, int y, int moveX, int moveY)
{
	int moved = 0;

	//�ǂɂԂ��邩�A�͈͊O�ɏo��܂ŌJ��Ԃ�
	while (0 <= x && x < BLOCK_COUNT_X
		&& 0 <= y && y < BLOCK_COUNT_Y)
	{
		//���݂̃}�X�Ƀu���b�N���z�u����Ă����烋�[�v�I��
		if (mBlockData[x][y] == 1)break;
		
		//�ʂ��}�X�ł���Έړ����[�g�ɐݒ�
		mBlockData[x][y] = 2;
		//���̃}�X�ֈړ�
		x += moveX;
		y += moveY;
		//�ړ������}�X�̐������Z
		moved += abs(moveX) + abs(moveY);
	}

	return max(moved - 1,0);
}

//�u���b�N�̔z�u�f�[�^���쐬
void CStage8::CreateBlockData()
{
	//�u���b�N�̔z�u�f�[�^��������
	memset(mBlockData, 0, sizeof(mBlockData));

	int x = 0; //�������̌��݈ʒu
	int y = 0; //�c�����̌��݈ʒu

	//�X�^�[�g�ʒu����O��3��ڂɃ����_���ŕǂ�z�u����B
	x = Math::Rand(0, BLOCK_COUNT_X - 1);
	mBlockData[x][2] = 1;

	int moveX = 0; //���E�̈ړ���
	int moveY = 1; //�O��̈ړ���
	int moved = 0; //�ړ������}�X�̐�

	//�S�[���ɂ��ǂ蒅���܂ŌJ��Ԃ�
	while (true)
	{
		//�ǂɂԂ���܂ł܂������i���
		//mBlockData�ɕ��������[�g�̏ꏊ�ɂQ������
		moved = PaveTheRoute(x, y, moveX, moveY);
		//�O�񂪏c�����̈ړ��ł���΁A���͉������̈ړ����s��
		if (moveX == 0)
		{
			//�c�����̌��݈ʒu�Ɉړ������}�X�����Z
			y += moved;

			//���͍��E�ǂ���Ɉړ����邩�����_���Ɍ���
			bool isLeft = Math::Rand(0, 1) == 0;
			//���肵�������Ɉړ��ł���}�X�̐������߂�
			moved = isLeft ? x - 1 : (BLOCK_COUNT_X - 1) - x - 1;
			//1�}�X���i�߂Ȃ��̂ł���΁A
			if (moved <= 0)
			{
				//�ړ������𔽓]���āA�ړ��ł���}�X�̐����Čv�Z
				isLeft = !isLeft;
				moved = isLeft ? x - 1 : (BLOCK_COUNT_X - 1) - x - 1;
			}
			//�e�����̈ړ��ʂ�ݒ�
			//����͍��E�̈ړ��Ȃ̂ŁA�O��̈ړ��ʂ�0�ɂ���
			moveX = isLeft ? -1 : 1;
			moveY = 0;

			//�ړ�����}�X�̐��������_���Ō��肷��
			moved = moved > 1 ? Math::Rand(1, moved) : moved;
			//�ړ���̃}�X�Ƀu���b�N��z�u����
			mBlockData[x + moveX * (moved + 1)][y] = 1;
		}
		//�O�񂪉������̈ړ��ł���΁A���͏c�����̈ړ����s��
		else
		{
			//�������̌��݈ʒu�Ɉړ������}�X�����Z
			x += moveX * moved;
			//�e���K�̈ړ��ʂ�ݒ�
			//����͑O�ړ��Ȃ̂ŁA���E�̈ړ��ʂ͂O�ɂ���
			moveX = 0;
			moveY = 1;
			//�ړ��ł���}�X�̐������߂�
			moved = (BLOCK_COUNT_Y - 1) - y;
			//�ړ��ł���}�X�̐����R�}�X�ȏ�ł����
			if (moved >= 3)
			{
				//�ǂ�z�u����
				moved = moved > 3 ? Math::Rand(2, moved - 1) : moved - 1;
				mBlockData[x][y + moved + 1] = 1;
			}
			//�ړ��ł���}�X���Q�}�X�ȉ��ł����
			else
			{
				//���̂܂܃S�[���܂Ń��[�g��ݒ肵��
				//���̃��[�v�𔲂���
				moved = PaveTheRoute(x, y, moveX, moveY);
				break;
			}
		}
	}

	//�쐬�����u���b�N�̔z�u�f�[�^����
	//���ۂɔz�u����ǂ̃I�u�W�F�N�g�𐶐�
	CModel* cubeModel = CResourceManager::Get<CModel>("Cube");
	for (int i = 0; i < BLOCK_COUNT_X; i++)
	{
		//�z�u����X���W�����߂�
		float posX = Math::Lerp(-100.0f, 100.0f, (float)i / (BLOCK_COUNT_X - 1));
		for (int j = 0; j < BLOCK_COUNT_Y; j++)
		{
			//�z�u����ǂ�Z���W�����߂�
			float posZ = Math::Lerp(-35.0f, -260.0f, (float)j / (BLOCK_COUNT_Y - 1));
		
			//�����Ȃ��ꏊ�ł���΁A���̃}�X��
			if (mBlockData[i][j] == 0)continue;
			//if (mBlockData[i][j] == 2)continue;

			bool isRoute = mBlockData[i][j] == 2;
			float posY = isRoute ? -9.9f : 10.0f;

			//Cube�I�u�W�F�N�g���쐬
			CCube* cube = new CCube
			(
				cubeModel,
				CVector(posX, 10.0f, posZ), 
				CVector(0.5f, 4.0f, 0.5f)
			);

			CColor color = isRoute ? CColor::magenta : CColor::white;
			cube->SetColor(color);
			cube->SetEnableCol(!isRoute);

			AddTask(cube);
		}
	}
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

	//�u���b�N�̔z�u�f�[�^���쐬
	CreateBlockData();

	//PosZ = -35.0f;

	//for (int a = 0; a < 10; a++)
	//{
	//	//�d�����Ȃ������_���̐����p�̔z��
	//	int z;
	//	int n[9];
	//	n[0] = 0;
	//	n[1] = 1;
	//	n[2] = 2;
	//	n[3] = 3;
	//	n[4] = 4;
	//	n[5] = 5;
	//	n[6] = 6;
	//	n[7] = 7;
	//	n[8] = 8;
	//	z = 8;
	//	for (int i = 0; i < 2; i++)
	//	{
	//		//�d�����Ȃ������_���̐���
	//		int x;
	//		int RandPos;
	//		int RandPosX;
	//		x = Math::Rand(0, z);
	//		RandPos = n[x];
	//		n[x] = n[z];
	//		z = z - 1;
	//		//�������y����쐬
	//		switch (RandPos)
	//		{
	//		case 0:
	//			RandPosX = 0.0f;
	//			break;
	//		case 1:
	//			RandPosX = 25.0f;
	//			break;
	//		case 2:
	//			RandPosX = 50.0f;
	//			break;
	//		case 3:
	//			RandPosX = 75.0f;
	//			break;
	//		case 4:
	//			RandPosX = 100.0f;
	//			break;
	//		case 5:
	//			RandPosX = -25.0f;
	//			break;
	//		case 6:
	//			RandPosX = -50.0f;
	//			break;
	//		case 7:
	//			RandPosX = -75.0f;
	//			break;
	//		case 8:
	//			RandPosX = -100.0f;
	//			break;
	//		};
	//		//���ߓy��
	//		CCube* cube = new CCube(cubeModel,
	//			CVector(RandPosX, 10.0f, PosZ), CVector(0.5f, 4.0f, 0.5f));
	//		AddTask(cube);
	//	}
	//	PosZ = PosZ - 25.25f;
	//}

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