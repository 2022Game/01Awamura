#include "CACoinGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CResourceManager.h"

#include <stdlib.h>

#include "time.h"

//�y��Coin
#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"

int rand(void);
void srand(unsigned int seed);

CACoinGimmick::CACoinGimmick()
	:randnow(0)
	,randnow2(0)
	, randnow3(0)
	, randnow4(0)
	, randnow5(0)
	,randnow6(0)
	,mmmmm(0)
{
	srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	CTaskManager::Instance()->Add(this);
	
}

CACoinGimmick::~CACoinGimmick()
{
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
	mpCoinModel = GET_MODEL("Coin");

	if (CApplication::StageCount == 0)
	{
		randnow = 4 + rand() % 17;
		randnow2 = 4 + rand() % 17;
		randnow3 = 4 + rand() % 17;
		randnow4 = 4 + rand() % 17;
		randnow5 = 4 + rand() % 17;
		randnow6 = 4 + rand() % 17;
	}
	if (CApplication::StageCount == 1)
	{
		randnow = 4 + rand() % 17;
		randnow2 = 4 + rand() % 17;
		randnow3 = 4 + rand() % 17;
		randnow4 = 4 + rand() % 17;
		randnow5 = 4 + rand() % 17;
		randnow6 = 4 + rand() % 17;
	}
	if (CApplication::StageCount == 2)
	{
		randnow = 4 + rand() % 17;
		randnow2 = 4 + rand() % 17;
		randnow3 = 4 + rand() % 17;
		randnow4 = 4 + rand() % 17;
		randnow5 = 4 + rand() % 17;
		randnow6 = 4 + rand() % 17;
	}

	// �R�C���𐶐�
	//�X�e�[�W�P
	if (CApplication::StageCount == 0)
	{
		CreateCoin(CVector(randnow, 22.9f, 6.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow2, 22.9f, 13.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow3, 22.9f, 20.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow4, 22.9f, 27.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow5, 22.9f, 34.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow6, 22.9f, 41.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}
	////�X�e�[�W�Q
	if (CApplication::StageCount == 1)
	{
		CreateCoin(CVector(randnow, 22.9f, 56.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow2, 22.9f, 63.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow3, 22.9f, 70.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow4, 22.9f, 77.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow5, 22.9f, 84.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow6, 22.9f, 91.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	}
	////�X�e�[�W�R
	if (CApplication::StageCount == 2)
	{
		CreateCoin(CVector(randnow, 22.9f,106.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow2, 22.9f, 113.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow3, 22.9f, 120.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow4, 22.9f, 127.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow5, 22.9f, 134.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
		CreateCoin(CVector(randnow6, 22.9f, 141.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
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