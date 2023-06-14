#include "CAWoodGimmick.h"
#include "CTaskManager.h"

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
	/*CreateWood(CVector(10.0f, 24.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateWood(CVector(11.5f, 24.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateWood(CVector(13.0f, 24.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateWood(CVector(11.5f, 24.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateWood(CVector(10.0f, 24.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateWood(CVector(13.0f, 24.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateWood(CVector(14.5f, 24.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateWood(CVector(17.0f, 24.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateWood(CVector(14.5f, 24.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateWood(CVector(13.0f, 24.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateWood(CVector(16.0f, 24.9f, 57.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateWood(CVector(17.5f, 24.9f, 65.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateWood(CVector(19.0f, 24.9f, 73.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateWood(CVector(17.5f, 24.9f, 81.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateWood(CVector(16.0f, 24.9f, 89.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));*/
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