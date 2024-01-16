#include "CStage8.h"
#include "CClearCube.h"
#include "CFloor.h"
#include "Maths.h"
#include "CPlayer.h"
#include "CCamera.h"

//�R���X�g���N�^
CStage8::CStage8()
{
	mStageNo = 2;
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

	// �N���A�y��̃��f���ǂݍ���
	CModel* clearCubeStageModel = CResourceManager::Get<CModel>("Clearcube");


	//���ʂ̑���
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, -10.0f, 0.0f), CVector(5.0f, 4.0f, 1.0f));
	AddTask(floor);

	//�N���A�y����쐬
	CClearCube* coin = new CClearCube(clearCubeStageModel,
		CVector(0.0f, 70.0f, -300.0f), CVector(5.0f, 1.0f, 1.0f));
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