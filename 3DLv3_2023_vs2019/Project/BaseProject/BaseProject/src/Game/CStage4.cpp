#include "CStage4.h"
#include "CClearStage.h"
#include "CKillwood.h"
#include "CSidewood.h"
#include "CSideDownwood.h"
#include "CBollField.h"
#include "CCleardelta.h"
#include "CPlayer.h"
#include "CCamera.h"

//�R���X�g���N�^
CStage4::CStage4()
{
	mStageNo = 4;
}

//�f�X�g���N�^
CStage4::~CStage4()
{

}

//�X�e�[�W�ǂݍ���
void CStage4::Load()
{
	// �N���A�y��̃��f���ǂݍ���
	CModel* clearStageModel = CResourceManager::Get<CModel>("Clearstage");

	//��؂̃��f���ǂݍ���
	CModel* killwoodModel = CResourceManager::Get<CModel>("Killwood");

	//�|�؂̃��f���ǂݍ���
	CModel* sidewoodModel = CResourceManager::Get<CModel>("Sidewood");

	////�|�؂̃��f���ǂݍ���
	CModel* sidedownwoodModel = CResourceManager::Get<CModel>("SideDownwood");

	//�~�`�y��̃��f���ǂݍ���
	CModel* bollFieldModel = CResourceManager::Get<CModel>("Rainbow12345");
	//�e�X�g���I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I

	//�Ƃ񂪂�R�[���y��̃��f���ǂݍ���
	CModel* deltaModel = CResourceManager::Get<CModel>("Cleardelta");

	//�N���A�y����쐬
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, -5.0f, -30.0f), CVector(0.5f, 0.5f, 0.5f));
	AddTask(coin);

	//��؂��쐬
	CKillwood* killwood = new CKillwood(killwoodModel,
		CVector(0.0f, 0.0f, -30.0f), CVector(4.5f, 5.0f, 4.5f)
		,0.0f);
	AddTask(killwood);

	//�|�؂��쐬
	CSidewood* sidewood = new CSidewood(sidewoodModel,
		CVector(0.0f, 5.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f)
		,0.0f);
	AddTask(sidewood);
	/*sidewood = new CSidewood(sidewoodModel,
		CVector(0.0f, 5.0f, -30.0f), CVector(5.5f, 5.0f, 5.0f)
		, 0.0f);
	AddTask(sidewood);*/

	//��������|�؂��쐬
	CSideDownwood* sidedownwood = new CSideDownwood(sidewoodModel,
		CVector(0.0f, 120.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f)
		, 0.0f);
	AddTask(sidedownwood);
	sidedownwood = new CSideDownwood(sidewoodModel,
		CVector(0.0f, 150.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f)
		, 0.0f);
	AddTask(sidedownwood);


	//�~�`�y����쐬
	CBollField* bollField = new CBollField(bollFieldModel,
		CVector(0.0f, -20.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f));
	AddTask(bollField);

	//�Ƃ񂪂�y����쐬
	CCleardelta* cleardelta = new CCleardelta (deltaModel,
		CVector(0.0f,500.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f));
	AddTask(cleardelta);

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
void CStage4::Unload()
{
	//�x�[�X�̃X�e�[�W�j������
	CStageBase::Unload();
}