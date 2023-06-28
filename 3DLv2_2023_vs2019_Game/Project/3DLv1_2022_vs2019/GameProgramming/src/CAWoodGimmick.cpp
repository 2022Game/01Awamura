#include "CAWoodGimmick.h"
#include "CTaskManager.h"
#include "CApplication.h"

//�`���̖�
#define MODEL_FWOOD "res\\WWWW.obj","res\\WWWW.mtl"

CAWoodGimmick::CAWoodGimmick()
{
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	CTaskManager::Instance()->Add(this);
}

CAWoodGimmick::~CAWoodGimmick()
{
	// �؂̃��f���f�[�^��j��
	if (mpWoodModel != nullptr)
	{
		delete mpWoodModel;
	}

	// �؂�j��
	for (int i = 0; i < mWoods.size(); i++)
	{
		delete mWoods[i];
	}
	// �ꉞ���X�g���N���A���Ă���
	mWoods.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	CTaskManager::Instance()->Remove(this);
}

void CAWoodGimmick::Init()
{
	// �؂̃��f���ǂݍ���
	mpWoodModel = new CModel();
	mpWoodModel->Load(MODEL_FWOOD);

	// �؂𐶐�
	if (CApplication::SelectStage == 2)
	{
		if (CApplication::StageCount == 0)
		{
			CreateWood(CVector(4.0f, 22.9f, 7.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 15.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 23.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 31.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 39.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 7.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 15.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 23.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 31.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 39.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 7.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 15.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 23.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 31.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 39.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CApplication::StageCount == 1)
		{
			CreateWood(CVector(4.0f, 22.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CApplication::StageCount == 2)
		{
			CreateWood(CVector(4.0f, 22.9f, 107.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 115.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 123.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 131.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 139.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 107.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 115.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 123.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 131.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 139.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 107.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 115.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 123.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 131.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 139.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
	}
	if (CApplication::SelectStage == 3)
	{
		if (CApplication::StageCount == 0)
		{
			CreateWood(CVector(4.0f, 22.9f, 7.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 15.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 23.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 31.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 39.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 7.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 15.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 23.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 31.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 39.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 7.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 15.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 23.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 31.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 39.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CApplication::StageCount == 1)
		{
			CreateWood(CVector(4.0f, 22.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CApplication::StageCount == 2)
		{
			CreateWood(CVector(4.0f, 22.9f, 107.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 115.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 123.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 131.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(4.0f, 22.9f, 139.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 107.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 115.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 123.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 131.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(12.0f, 22.9f, 139.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 107.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 115.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 123.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 131.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateWood(CVector(20.0f, 22.9f, 139.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
	}
}

void CAWoodGimmick::CreateWood(CVector& pos, CVector& rot, CVector& scale)
{
	if (mpWoodModel == nullptr) return;

	// �؂𐶐����ă��X�g�ɒǉ�
	CAWood* wood = new CAWood(mpWoodModel, pos, rot, scale);
	mWoods.push_back(wood);
}

void CAWoodGimmick::Update()
{
}