#include "CSwitchLGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CSwitchLGimmick::CSwitchLGimmick()
{
	// ��������
	Init();
}

CSwitchLGimmick::~CSwitchLGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mLSwitch.size(); i++)
	{
		mLSwitch[i]->Kill();
	}
	// �ꉞ���X�g���N���A���Ă���
	mLSwitch.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CSwitchLGimmick::Init()
{
	// �N���A�y��̃��f���ǂݍ���
	mpMoveSwitchLModel = new CModel();
	mpMoveSwitchLModel->Load("Field\\Object\\switchBlue.obj", "Field\\Object\\switchBlue.mtl");

	// ���[�v�̓y��𐶐�
	//�X�e�[�W0
	if (CField::mStageCount == 3)
	{
		CreateSwitch(mpMoveSwitchLModel,
			CVector(-15.0f, -5.0f, 240.0f), CVector(10.0f, 10.0f, 10.0f));
	}
}

void CSwitchLGimmick::CreateSwitch(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpMoveSwitchLModel == nullptr) return;

	//// �y��𐶐����ă��X�g�ɒǉ�
	CSwitchLObject* switchlfield = new CSwitchLObject(mpMoveSwitchLModel, pos, scale);
	mLSwitch.push_back(switchlfield);
}

void CSwitchLGimmick::Update()
{

}