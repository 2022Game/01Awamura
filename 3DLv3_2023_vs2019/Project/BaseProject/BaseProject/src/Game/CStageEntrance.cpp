#include "CStageEntrance.h"
#include "CFloor.h"
#include "CWarp.h"
#include "CPlayer.h"
#include "CCamera.h"

//�R���X�g���N�^
CStageEntrance::CStageEntrance()
{
	mStageNo = 0;
	if (CGameManager::StageClearCount() >= 8)
	{
		CVector2 pos = CVector2(0.0f, 0.0f);
		CVector2 size = CVector2(WINDOW_WIDTH, WINDOW_HEIGHT);
		ETextAlignH textAlignH = ETextAlignH::eCenter;
		std::string text = "GameClear\n���͂�";

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
	else
	{
		CVector2 pos = CVector2(0.0f, 0.0f);
		CVector2 size = CVector2(WINDOW_WIDTH, WINDOW_HEIGHT);
		ETextAlignH textAlignH = ETextAlignH::eCenter;
		std::string text = "�G���g�����X�X�e�[�W\n���͂�";

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
}

//�f�X�g���N�^
CStageEntrance::~CStageEntrance()
{

}

//�X�e�[�W�ǂݍ���
void CStageEntrance::Load()
{
	// ���ʂ̓y��̃��f���ǂݍ���
	CModel* floorModel = CResourceManager::Get<CModel>("FieldCube");

	//���[�v���̓ǂݍ���
	CModel* warpModel = CResourceManager::Get<CModel>("Warp");

	//���ʂ̑���
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, 2.0f, -20.0f), CVector(0.5f, 4.0f, 5.0f));
	AddTask(floor);

	//���[�v�����쐬
	CWarp* warp = new CWarp(warpModel,
		CVector(0.0f, 10.0f, -20.0f), CVector(6.0f, 3.0f, 10.0f));
	AddTask(warp);

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
void CStageEntrance::Unload()
{
	//�x�[�X�̃X�e�[�W�j������
	CStageBase::Unload();
}