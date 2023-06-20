#include "CACoinGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"

//�y��Coin
#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"

CACoinGimmick::CACoinGimmick()
{
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	CTaskManager::Instance()->Add(this);
	
}

CACoinGimmick::~CACoinGimmick()
{
	// �R�C���̃��f���f�[�^��j��
	if (mpCoinModel != nullptr)
	{
		delete mpCoinModel;
	}

	// �R�C����j��
	for (int i = 0; i < mCoins.size(); i++)
	{
		delete mCoins[i];
	}
	// �ꉞ���X�g���N���A���Ă���
	mCoins.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	CTaskManager::Instance()->Remove(this);
}

void CACoinGimmick::Init()
{
	// �R�C���̃��f���ǂݍ���
	mpCoinModel = new CModel();
	mpCoinModel->Load(MODEL_FCOIN);

	// �R�C���𐶐�
	//�X�e�[�W�P
	if (CApplication::StageCount == 0)
	{
		CreateCoin(CVector(10.0f, 0.1f, 6.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(11.5f, 0.1f, 14.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(13.0f, 0.1f, 22.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(11.5f, 0.1f, 30.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(10.0f, 0.1f, 38.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}
	////�X�e�[�W�Q
	if (CApplication::StageCount == 1)
	{
		CreateCoin(CVector(10.0f, 0.1f, 54.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateCoin(CVector(11.5f, 0.1f, 62.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateCoin(CVector(13.0f, 0.1f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateCoin(CVector(11.5f, 0.1f, 78.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
			CreateCoin(CVector(10.0f, 0.1f, 86.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}
	////�X�e�[�W�R
	if (CApplication::StageCount == 2)
	{
		CreateCoin(CVector(10.0f, 0.1f, 102.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(11.5f, 0.1f, 110.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(13.0f, 0.1f, 118.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(11.5f, 0.1f, 126.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(10.0f, 0.1f, 134.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}
}

void CACoinGimmick::CreateCoin(CVector& pos, CVector& rot, CVector& scale)
{
	if (mpCoinModel == nullptr) return;

	// �R�C���𐶐����ă��X�g�ɒǉ�
	CACoin* coin = new CACoin(mpCoinModel, pos, rot, scale);
	mCoins.push_back(coin);
}

void CACoinGimmick::Update()
{
	//if (�v���C���[���R�C���ɐڒn������)
	{
		for (int i = 0; i < mCoins.size(); i++)
		{
			CACoin* coin = mCoins[i];
			if (coin->SCount == 0)
			{
				coin->SCount = 1;
			}
		}
	}
}