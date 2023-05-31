#include "CACoinGimmick.h"
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
	CreateCoin(CVector(10.0f, 0.1f, 31.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateCoin(CVector(11.5f, 0.1f, 23.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateCoin(CVector(13.0f, 0.1f, 16.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateCoin(CVector(11.5f, 0.1f, 8.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	CreateCoin(CVector(10.0f, 0.1f, 3.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	////�X�e�[�W�Q
	//CreateCoin(CVector(10.0f, 0.1f, 76.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	//CreateCoin(CVector(11.5f, 0.1f, 68.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	//CreateCoin(CVector(13.0f, 0.1f, 61.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	//CreateCoin(CVector(11.5f, 0.1f, 53.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	//CreateCoin(CVector(10.0f, 0.1f, 46.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	////�X�e�[�W�R
	//CreateCoin(CVector(10.0f, 0.1f, 76.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	//CreateCoin(CVector(11.5f, 0.1f, 68.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	//CreateCoin(CVector(13.0f, 0.1f, 61.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	//CreateCoin(CVector(11.5f, 0.1f, 53.5f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	//CreateCoin(CVector(10.0f, 0.1f, 46.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
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