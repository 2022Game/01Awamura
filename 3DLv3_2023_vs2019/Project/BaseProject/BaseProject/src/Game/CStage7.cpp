#include "CStage7.h"
#include "CClearStage.h"
#include "CFloor.h"
#include "CPlayer.h"
#include "CCamera.h"
#include "CDisappearFloor.h"
#include "Maths.h"
#include "CCleardelta.h"
#include "CGameManager.h"

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

	CVector2 pos = CVector2(0.0f, 0.0f);
	CVector2 size = CVector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	ETextAlignH textAlignH = ETextAlignH::eCenter;
	std::string text = "������X�e�[�W\n�S�Ẵp�l���𓥂�";

	//�e�L�X�g�̉e
	mpTextShadow = new CText
	(
		nullptr, 24,
		pos + CVector2(2.0f, 2.0f),
		size,
		CColor(0.0f, 0.0f, 0.0f),
		ETaskPriority::eTextShadow
	);

	mpTextShadow->SetTextAlignH(textAlignH);
	mpTextShadow->SetText(text.c_str());
	AddTask(mpTextShadow);

	//�e�L�X�g�{��
	mpText = new CText
	(
		nullptr, 24,
		pos, size,
		CColor(1.0f, 1.0f, 1.0f),
		ETaskPriority::eText
	);
	mpText->SetTextAlignH(textAlignH);
	mpText->SetText(text.c_str());
	AddTask(mpText);
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

	//�Ƃ񂪂�R�[���y��̃��f���ǂݍ���
	CModel* deltaModel = CResourceManager::Get<CModel>("Cleardelta");

	//�N���A�y����쐬
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, -300.0f, -100.0f), CVector(0.8f, 5.0f, 0.8f));
	AddTask(coin);

	//�Ƃ񂪂�y����쐬
	CCleardelta* cleardelta = new CCleardelta(deltaModel,
		CVector(0.0f, -300.0f, -100.0f), CVector(5.0f, 5.0f, 5.0f));
	AddTask(cleardelta);

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
			AddTask(dfloor);
			CDisappearFloor::mFadeCount++;
		}
		PosZ = PosZ - 24.5f;
	}
	CDisappearFloor::mFadeCountBox = CDisappearFloor::mFadeCount;

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