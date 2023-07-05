#include "CASoccerGimmick.h"
#include "CTaskManager.h"
#include "CApplication.h"
//#include "CAHamahGimmick.h"

//�`���̃{�[��
#define MODEL_FSOCCER "res\\soccer1.obj","res\\soccer1.mtl"

CASoccerGimmick::CASoccerGimmick()
{
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	CTaskManager::Instance()->Add(this);
}

CASoccerGimmick::~CASoccerGimmick()
{
	// Soccer�̃��f���f�[�^��j��
	if (mpSoccerModel != nullptr)
	{
		delete mpSoccerModel;
	}

	// Soccer��j��
	for (int i = 0; i < mSoccers.size(); i++)
	{
		delete mSoccers[i];
	}
	// �ꉞ���X�g���N���A���Ă���
	mSoccers.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	CTaskManager::Instance()->Remove(this);
}

void CASoccerGimmick::Init()
{
	// �؂̃��f���ǂݍ���
	mpSoccerModel = new CModel();
	mpSoccerModel->Load(MODEL_FSOCCER);
	

	if (CApplication::StageCount == 0 && CASoccer::hdhd == 2)
	{
		CreateSoccer(CVector(13.0f, 24.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateSoccer(CVector(10.0f, 24.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateSoccer(CVector(15.0f, 24.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateSoccer(CVector(20.0f, 24.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}

	// �؂𐶐�
	if (CApplication::SelectStage == 5)
	{
		if (CApplication::StageCount == 0)
		{
			CreateSoccer(CVector(13.0f, 24.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(10.0f, 24.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(15.0f, 24.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateSoccer(CVector(20.0f, 24.0f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		}
		if (CApplication::StageCount == 1)
		{
		}
		if (CApplication::StageCount == 2)
		{
		}
	}
	if (CApplication::SelectStage == 6)
	{
		if (CApplication::StageCount == 0)
		{
		}
		if (CApplication::StageCount == 1)
		{
		}
		if (CApplication::StageCount == 2)
		{
		}
	}
}

void CASoccerGimmick::CreateSoccer(CVector& pos, CVector& rot, CVector& scale)
{
	if (mpSoccerModel == nullptr) return;

	// �؂𐶐����ă��X�g�ɒǉ�
	CASoccer* soccer = new CASoccer(mpSoccerModel, pos, rot, scale);
	mSoccers.push_back(soccer);
}

void CASoccerGimmick::Update()
{
}