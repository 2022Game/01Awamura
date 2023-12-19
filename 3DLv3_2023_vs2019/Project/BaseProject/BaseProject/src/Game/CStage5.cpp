#include "CStage5.h"
#include "CClearStage.h"
#include "CFloor.h"
#include "CPlayer.h"
#include "CCamera.h"
#include "CDisappearFloor.h"
#include "CDisappearFloor2.h"
#include "CNeedle.h"
#include "CTransparentField.h"

//�R���X�g���N�^
CStage5::CStage5()
{
	mStageNo = 5;
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

	//���̓ǂݍ���
	CModel* needleModel = CResourceManager::Get<CModel>("Needle");

	//�N���A�y����쐬
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, -225.0f, 0.0f), CVector(1.0f, 5.0f, 1.0f));
	AddTask(coin);

	//���ʂ̑���
	/*CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, 590.0f, 0.0f), CVector(0.5f, 2.0f, 0.5f));
	AddTask(floor);*/

	//���ߓy��
	CDisappearFloor* dfloor = new CDisappearFloor
	(
		CVector(-12.5f, 400.0f, 12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	AddTask(dfloor);
	dfloor = new CDisappearFloor
	(
		CVector(12.5f, 400.0f, 12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	AddTask(dfloor);
	dfloor = new CDisappearFloor
	(
		CVector(-12.5f, 400.0f, -12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	AddTask(dfloor);
	dfloor = new CDisappearFloor
	(
		CVector(12.5f, 400.0f, -12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	AddTask(dfloor);

	dfloor = new CDisappearFloor
	(
		CVector(-12.5f, 200.0f, 12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	AddTask(dfloor);
	dfloor = new CDisappearFloor
	(
		CVector(12.5f, 200.0f, 12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	AddTask(dfloor);
	dfloor = new CDisappearFloor
	(
		CVector(-12.5f, 200.0f, -12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	AddTask(dfloor);
	dfloor = new CDisappearFloor
	(
		CVector(12.5f, 200.0f, -12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	AddTask(dfloor);

	//���ߓy��Q
	CDisappearFloor2* dfloor2 = new CDisappearFloor2
	(
		CVector(0.0f, 500.0f, 0.0f), CVector(1.0f, 2.0f, 1.0f),
		ETag::ePlayer, ELayer::ePlayer
	);

	dfloor2 = new CDisappearFloor2
	(
		CVector(12.5f, 300.0f, 12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);

	dfloor2 = new CDisappearFloor2
	(
		CVector(12.5f, 300.0f, -12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);

	dfloor2 = new CDisappearFloor2
	(
		CVector(-12.5f, 300.0f, 12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);
	dfloor2 = new CDisappearFloor2
	(
		CVector(-12.5f, 300.0f, -12.5f), CVector(0.5f, 2.0f, 0.5f),
		ETag::ePlayer, ELayer::ePlayer
	);


	//�����쐬
	CNeedle* needle = new CNeedle(needleModel,
		CVector(12.5f, 380.0f, -12.5f), CVector(3.0f, 2.0f, 3.0f));
	AddTask(needle);

	//�����ȓy��
	CTransparentField* transfloor = new CTransparentField
	(
		floorModel,CVector(12.5f, 370.0f, -12.5f), CVector(0.5f, 1.0f, 0.5f)
	);
	AddTask(transfloor);

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
		CVector eye = playerPos + CVector(0.0f, 75.0f, 1.0f);
		CVector at = playerPos;
		CVector forward = (at - eye).Normalized();
		CVector side = CVector::Cross(forward, CVector::up);
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