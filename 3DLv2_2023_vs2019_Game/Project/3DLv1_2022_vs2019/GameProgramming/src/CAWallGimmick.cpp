#include "CAWallGimmick.h"
#include "CTaskManager.h"
#include "CApplication.h"

//�_���Ȃ��
#define MODEL_FWALL "res\\Wall2.obj","res\\Wall2.mtl"

CAWallGimmick::CAWallGimmick()
{
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	CTaskManager::Instance()->Add(this);
}

CAWallGimmick::~CAWallGimmick()
{
	// �n�}�[�̃��f���f�[�^��j��
	if (mpWallModel != nullptr)
	{
		delete mpWallModel;
	}

	// �n�}�[��j��
	for (int i = 0; i < mWalls.size(); i++)
	{
		delete mWalls[i];
	}
	// �ꉞ���X�g���N���A���Ă���
	mWalls.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	CTaskManager::Instance()->Remove(this);
}

void CAWallGimmick::Init()
{
	// Wall�̃��f���ǂݍ���
	/*mpWallModel = new CModel();
	mpWallModel->Load(MODEL_FWALL);*/
	mpWallModel = CApplication::Wall();

	// Wall�𐶐�
	//�X�e�[�W�P�X�^�[�g����
	if (CApplication::StageCount == 1)
	{
		CreateWall(CVector(10.0f, 22.9f, 1.5f), CVector(), CVector(1.8f, 5.8f, 2.8f));
	}
	////�X�e�[�W�Q�X�^�[�g����
	if (CApplication::StageCount == 2)
	{
		CreateWall(CVector(10.0f, 22.9f, 51.5f), CVector(), CVector(1.8f, 5.8f, 2.8f));
	}
	////�X�e�[�W�R�X�^�[�g����
	if (CApplication::StageCount == 3)
	{
		CreateWall(CVector(10.0f, 22.9f, 100.5f), CVector(), CVector(1.8f, 5.8f, 2.8f));
	}
}

void CAWallGimmick::CreateWall(CVector& pos, CVector& rot, CVector& scale)
{
	if (mpWallModel == nullptr) return;

	// �n�}�[�𐶐����ă��X�g�ɒǉ�
	CAWall* wall = new CAWall(mpWallModel, pos, rot, scale);
	mWalls.push_back(wall);
}

void CAWallGimmick::Update()
{
}