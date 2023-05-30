#include "CAHamahGimmick.h"
#include "CTaskManager.h"

//�n���}�[�����S
#define MODEL_FHAMAH "res\\apple2.obj","res\\apple2.mtl"

CAHamahGimmick::CAHamahGimmick()
{
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	CTaskManager::Instance()->Add(this);
}

CAHamahGimmick::~CAHamahGimmick()
{
	// �n�}�[�̃��f���f�[�^��j��
	if (mpHamahModel != nullptr)
	{
		delete mpHamahModel;
	}

	// �n�}�[��j��
	for (int i = 0; i < mHamahs.size(); i++)
	{
		delete mHamahs[i];
	}
	// �ꉞ���X�g���N���A���Ă���
	mHamahs.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	CTaskManager::Instance()->Remove(this);
}

void CAHamahGimmick::Init()
{
	// �n�}�[�̃��f���ǂݍ���
	mpHamahModel = new CModel();
	mpHamahModel->Load(MODEL_FHAMAH);

	// �n�}�[�𐶐�
	CreateHamah(CVector(10.0f, 24.9f, 8.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateHamah(CVector(11.5f, 24.9f, 16.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateHamah(CVector(13.0f, 24.9f, 23.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateHamah(CVector(11.5f, 24.9f, 31.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateHamah(CVector(10.0f, 24.9f, 39.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
}

void CAHamahGimmick::CreateHamah(CVector& pos, CVector& rot, CVector& scale)
{
	if (mpHamahModel == nullptr) return;

	// �n�}�[�𐶐����ă��X�g�ɒǉ�
	CAHamah* hamah = new CAHamah(mpHamahModel, pos, rot, scale);
	mHamahs.push_back(hamah);
}

void CAHamahGimmick::Update()
{
}