#include "CClearCubeGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

////�N���A�y��
//#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"

//int rand(void);
//void srand(unsigned int seed);

CClearCubeGimmick::CClearCubeGimmick()
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CClearCubeGimmick::~CClearCubeGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mClearCube.size(); i++)
	{
		mClearCube[i]->Kill();
		//delete mClearCube[i];
	}
	// �ꉞ���X�g���N���A���Ă���
	mClearCube.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CClearCubeGimmick::Init()
{
	// �N���A�y��̃��f���ǂݍ���
	mpClearCubeStageModel = new CModel();
	mpClearCubeStageModel->Load("Field\\Object\\Clearcube.obj", "Field\\Object\\Clearcube.mtl");

	// �N���A����p�̓y��𐶐�
	//�X�e�[�W�P
	if (CField::mStageCount == 2 && CField::mStageCreateSwitch == 1)
	{
	
	}
}

void CClearCubeGimmick::CreateClearCubeStage(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpClearCubeStageModel == nullptr) return;

	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	CClearCube* coin = new CClearCube(mpClearCubeStageModel, pos, scale);
	mClearCube.push_back(coin);
}

void CClearCubeGimmick::Update()
{

}