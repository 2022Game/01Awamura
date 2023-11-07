#include "CFloorGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//��
#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"

//int rand(void);
//void srand(unsigned int seed);

CFloorGimmick::CFloorGimmick()
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CFloorGimmick::~CFloorGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mFloor.size(); i++)
	{
		mFloor[i]->Kill();
	}
	// �ꉞ���X�g���N���A���Ă���
	mFloor.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CFloorGimmick::Init()
{
	// �N���A�y��̃��f���ǂݍ���
	mpFloorModel = new CModel();
	mpFloorModel->Load("Field\\Object\\Coin2.obj", "Field\\Object\\Coin2.mtl");

	// �N���A����p�̓y��𐶐�
	//�X�e�[�W�P
	if (CField::mStageCount == 1 && CField::mStageCreateSwitch == 1)
	{
		CreateFloor(mpFloorModel,
			CVector(120.0f, 0.0f, -440.0f), CVector(5.5f, 5.0f, 5.25f));
	}
	//�X�e�[�W�Q
	if (CField::mStageCount == 2 && CField::mStageCreateSwitch == 1)
	{
		
	}
	//�X�e�[�W3
	if (CField::mStageCount == 3 && CField::mStageCreateSwitch == 1)
	{
		
	}
	//�X�e�[�W4
	if (CField::mStageCount == 4 && CField::mStageCreateSwitch == 1)
	{
		
	}
	//�X�e�[�W5
	if (CField::mStageCount == 5 && CField::mStageCreateSwitch == 1)
	{
		CreateFloor(mpFloorModel,
			CVector(20.0f, 0.0f, -440.0f), CVector(5.5f, 5.0f, 5.25f));
	}
}

void CFloorGimmick::CreateFloor(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpFloorModel == nullptr) return;

	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	CFloor* coin = new CFloor(mpFloorModel, pos, scale);
	mFloor.push_back(coin);
}

void CFloorGimmick::Update()
{

}