#include "CStage5.h"
#include "CClearStage.h"
#include "CFloor.h"
#include "CPlayer.h"
#include "CCamera.h"
#include "CDisappearFloor.h"
#include "CCoverObject.h"
#include "CNeedle.h"
#include "CTransparentField.h"
#include "Maths.h"

//�R���X�g���N�^
CStage5::CStage5()
	:RandPos(0)
	, RandPos2(0)
	,RandPos3(0)
	, RandPosX(0)
	, RandPosX2(0)
	,RandPosZ(0)
	,RandPosZ2(0)
	,PosY(0)
	,PosY2(0)
	,RandPosDate(0)
	,RandPosDate2(0)
{
	mStageNo = 5;
	PosY = 380.0f;
	PosY2 = -200.0f;
}

//�f�X�g���N�^
CStage5::~CStage5()
{

}

//�X�e�[�W�ǂݍ���
void CStage5::Load()
{
	// �N���A�y��̃��f���ǂݍ���
	CModel* clearStageModel = CResourceManager::Get<CModel>("Clearstage");

	//���ʂ̑���ǂݍ���
	CModel* floorModel = CResourceManager::Get<CModel>("FieldCube");

	//�����̑���ǂݍ���
	CModel* cubecolModel = CResourceManager::Get<CModel>("Cubecol");

	//���̓ǂݍ���
	CModel* needleModel = CResourceManager::Get<CModel>("Needle");

	//�N���A�y����쐬
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, -300.0f, 0.0f), CVector(1.0f, 5.0f, 1.0f));
	AddTask(coin);

	//���ʂ̑���
	/*CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, 590.0f, 0.0f), CVector(0.5f, 2.0f, 0.5f));
	AddTask(floor);*/

	/*CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, 500.0f, 0.0f), CVector(1.0f, 2.0f, 1.0f));
	AddTask(floor);

	floor = new CFloor(floorModel,
		CVector(0.0f, 400.0f, 0.0f), CVector(0.5f, 2.0f, 0.5f));
	AddTask(floor);
	floor = new CFloor(floorModel,
		CVector(0.0f, 300.0f, 0.0f), CVector(0.5f, 2.0f, 0.5f));
	AddTask(floor);*/

	/*CDisappearFloor* dfloor = new CDisappearFloor
	(
		CVector(0.0f, 500.0f, 0.0f), CVector(1.0f, 2.0f, 1.0f),
		ETag::ePlayer, ELayer::ePlayer
	);*/
	
	for (int a = 0; a < 7; a++)
	{
		/*CCoverObject* coverfloor = new CCoverObject
		(
			CVector(0.0f, PosY2, 0.0f), CVector(1.0f, 2.0f, 1.0f),
			ETag::ePlayer, ELayer::ePlayer);
		AddTask(coverfloor);*/

		CDisappearFloor* dfloor = new CDisappearFloor
		(
			CVector(-12.5f, PosY2, 12.5f), CVector(0.5f, 2.0f, 0.5f),
			ETag::ePlayer, ELayer::ePlayer
		);
		AddTask(dfloor);
		dfloor = new CDisappearFloor
		(
			CVector(12.5f, PosY2, 12.5f), CVector(0.5f, 2.0f, 0.5f),
			ETag::ePlayer, ELayer::ePlayer
		);
		AddTask(dfloor);
		dfloor = new CDisappearFloor
		(
			CVector(-12.5f, PosY2, -12.5f), CVector(0.5f, 2.0f, 0.5f),
			ETag::ePlayer, ELayer::ePlayer
		);
		AddTask(dfloor);
		dfloor = new CDisappearFloor
		(
			CVector(12.5f, PosY2, -12.5f), CVector(0.5f, 2.0f, 0.5f),
			ETag::ePlayer, ELayer::ePlayer
		);
		AddTask(dfloor);
		PosY2 = PosY2 + 100.0f;
	}


	for (int i = 0; i < 7; i++)
	{
		//�����쐬
		RandPos = Math::Rand(0, 3);
		RandPosDate = RandPos;
		switch (RandPos)
		{
		case 0:
			RandPosX = 12.5f;
			RandPosZ = 12.5f;
			break;
		case 1:
			RandPosX = -12.5f;
			RandPosZ = 12.5f;
			break;
		case 2:
			RandPosX = 12.5f;
			RandPosZ = -12.5f;
			break;
		case 3:
			RandPosX = -12.5f;
			RandPosZ = -12.5f;
			break;
		};
		//�j
		CNeedle* needle = new CNeedle(needleModel,
			CVector(RandPosX, PosY, RandPosZ), CVector(3.0f, 2.0f, 3.0f));
		AddTask(needle);
		//�j�p�̓����蔻��
		CTransparentField* transfloor = new CTransparentField
		(
			cubecolModel, CVector(RandPosX, PosY, RandPosZ), CVector(0.50f, 1.0f, 0.50f)
		);
		AddTask(transfloor);
		if (i > 3)
		{
			RandPos2 = Math::Rand(0, 3);
			while (RandPos == RandPos2)
			{
				RandPos2 = Math::Rand(0, 3);
			}
			RandPosDate2 = RandPos2;
			RandPos = RandPos2;
			switch (RandPos)
			{
			case 0:
				RandPosX = 12.5f;
				RandPosZ = 12.5f;
				break;
			case 1:
				RandPosX = -12.5f;
				RandPosZ = 12.5f;
				break;
			case 2:
				RandPosX = 12.5f;
				RandPosZ = -12.5f;
				break;
			case 3:
				RandPosX = -12.5f;
				RandPosZ = -12.5f;
				break;
			};
			//�j
			CNeedle* needle = new CNeedle(needleModel,
				CVector(RandPosX, PosY, RandPosZ), CVector(3.0f, 2.0f, 3.0f));
			AddTask(needle);
			//�j�p�̓����蔻��
			CTransparentField* transfloor = new CTransparentField
			(
				cubecolModel, CVector(RandPosX, PosY, RandPosZ), CVector(0.50f, 1.0f, 0.50f)
			);
			AddTask(transfloor);
		}
		if (i > 4)
		{
			RandPos3 = Math::Rand(0, 3);
			while (RandPos3 == RandPosDate2 || RandPos3 == RandPosDate)
			{
				RandPos3 = Math::Rand(0, 3);
			}
			RandPos = RandPos3;
			switch (RandPos)
			{
			case 0:
				RandPosX = 12.5f;
				RandPosZ = 12.5f;
				break;
			case 1:
				RandPosX = -12.5f;
				RandPosZ = 12.5f;
				break;
			case 2:
				RandPosX = 12.5f;
				RandPosZ = -12.5f;
				break;
			case 3:
				RandPosX = -12.5f;
				RandPosZ = -12.5f;
				break;
			};
			//�j
			CNeedle* needle = new CNeedle(needleModel,
				CVector(RandPosX, PosY, RandPosZ), CVector(3.0f, 2.0f, 3.0f));
			AddTask(needle);
			//�j�p�̓����蔻��
			CTransparentField* transfloor = new CTransparentField
			(
				cubecolModel, CVector(RandPosX, PosY, RandPosZ), CVector(0.50f, 1.0f, 0.50f)
			);
			AddTask(transfloor);
		}
		PosY = PosY - 100.0f;
	}

	CDisappearFloor* dfloor = new CDisappearFloor
	(
		CVector(0.0f, 500.0f, 0.0f), CVector(1.0f, 2.0f, 1.0f),
		ETag::ePlayer, ELayer::ePlayer
	);
	//�����ȓy��
	/*CTransparentField* transfloor = new CTransparentField
	(
		floorModel,CVector(12.5f, 370.0f, -12.5f), CVector(0.5f, 1.0f, 0.5f)
	);
	AddTask(transfloor);*/

	//�v���C���[�̊J�n�ʒu��ݒ�
	CPlayer* player = CPlayer::Instance();
	CVector playerPos = CVector(0.0f, 550.0f, 0.0f);
	if (player != nullptr)
	{
		player->SetStartPosition(playerPos);
	}

	//�J�����̈ʒu�ƌ�����ݒ�
	CCamera* mainCamera = CCamera::MainCamera();
	if (mainCamera != nullptr)
	{
		CVector eye = playerPos + CVector(0.0f, 75.0f, 0.0f);
		CVector at = playerPos;
		CVector forward = (at - eye).Normalized();
		CVector side = CVector::Cross(forward, CVector::back);
		CVector up = CVector::Cross(side, forward);
		mainCamera->LookAt(eye, at, up);
		mainCamera->SetFollowTargetTf(player);
	}
}

//�X�e�[�W�j��
void CStage5::Unload()
{
	//�x�[�X�̃X�e�[�W�j������
	CStageBase::Unload();
}