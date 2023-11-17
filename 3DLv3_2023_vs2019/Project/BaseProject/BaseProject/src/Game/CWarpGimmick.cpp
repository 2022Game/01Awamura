#include "CWarpGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//��
#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"

//int rand(void);
//void srand(unsigned int seed);

CWarpGimmick::CWarpGimmick()
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();
}

CWarpGimmick::~CWarpGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mWarp.size(); i++)
	{
		mWarp[i]->Kill();
	}
	// �ꉞ���X�g���N���A���Ă���
	mWarp.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CWarpGimmick::Init()
{
	// �N���A�y��̃��f���ǂݍ���
	mpWarpModel = new CModel();
	mpWarpModel->Load("Field\\Object\\cube.obj", "Field\\Object\\cube.mtl");

	// ���[�v�̓y��𐶐�
	//�X�e�[�W0
	if (CField::mStageCount == 0)
	{
		CreateWarp(mpWarpModel,
			CVector(0.0f, 20.0f, -100.0f), CVector(0.5f, 8.0f, -0.5f));
	}
}

void CWarpGimmick::CreateWarp(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpWarpModel == nullptr) return;

	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	CWarp* warp = new CWarp(mpWarpModel, pos, scale);
	mWarp.push_back(warp);
}

void CWarpGimmick::Update()
{

}