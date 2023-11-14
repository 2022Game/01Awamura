#include "CClearStageGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

////�N���A�y��
//#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"

//int rand(void);
//void srand(unsigned int seed);

CClearStageGimmick::CClearStageGimmick()
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CClearStageGimmick::~CClearStageGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mClearStage.size(); i++)
	{
		mClearStage[i]->Kill();
		//delete mClearStage[i];
	}
	// �ꉞ���X�g���N���A���Ă���
	mClearStage.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CClearStageGimmick::Init()
{
	// �N���A�y��̃��f���ǂݍ���
	mpClearStageModel = new CModel();
	mpClearStageModel->Load("Field\\Object\\Coin2.obj", "Field\\Object\\Coin2.mtl");

	// �N���A����p�̓y��𐶐�
	//�X�e�[�W�P
	if (CField::mStageCount == 1 && CField::mStageCreateSwitch == 1)
	{
		CreateClearStage(mpClearStageModel,
		CVector(0.0f, 5.0f, -20.0f),  CVector(5.5f, 5.0f, 5.25f));
	}
	//�X�e�[�W�Q
	if (CField::mStageCount == 2 && CField::mStageCreateSwitch == 1)
	{
		CreateClearStage(mpClearStageModel,
		CVector(0.0f, 0.0f, -20.0f), CVector(5.5f, 5.0f, 5.25f));
	}
	//�X�e�[�W3
	if (CField::mStageCount == 3 && CField::mStageCreateSwitch == 1)
	{
		CreateClearStage(mpClearStageModel,
			CVector(0.0f, 0.0f, -20.0f), CVector(5.5f, 5.0f, 5.25f));
	}
	//�X�e�[�W4
	if (CField::mStageCount == 4 && CField::mStageCreateSwitch == 1)
	{
		CreateClearStage(mpClearStageModel,
			CVector(20.0f, 0.0f, -390.0f), CVector(5.5f, 5.0f, 5.25f));
	}
	//�X�e�[�W5
	if (CField::mStageCount == 5 && CField::mStageCreateSwitch == 1)
	{
		CreateClearStage(mpClearStageModel,
			CVector(20.0f, 0.0f, -440.0f), CVector(5.5f, 5.0f, 5.25f));
	}
}

void CClearStageGimmick::CreateClearStage(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpClearStageModel == nullptr) return;

	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	CClearStage* coin = new CClearStage(mpClearStageModel, pos, scale);
	mClearStage.push_back(coin);
}

void CClearStageGimmick::Update()
{

}