#include "CSwitchRGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CSwitchRGimmick::CSwitchRGimmick()
{
	// ��������
	Init();
}

CSwitchRGimmick::~CSwitchRGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mRSwitch.size(); i++)
	{
		mRSwitch[i]->Kill();
	}
	// �ꉞ���X�g���N���A���Ă���
	mRSwitch.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CSwitchRGimmick::Init()
{
	// �N���A�y��̃��f���ǂݍ���
	mpMoveSwitchRModel = new CModel();
	mpMoveSwitchRModel->Load("Field\\Object\\switchRed.obj", "Field\\Object\\switchRed.mtl");

	// ���[�v�̓y��𐶐�
	//�X�e�[�W0
	if (CField::mStageCount == 3)
	{
		
	}
}

void CSwitchRGimmick::CreateSwitch(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpMoveSwitchRModel == nullptr) return;

	//// �y��𐶐����ă��X�g�ɒǉ�
	CSwitchRObject* switchrfield = new CSwitchRObject(mpMoveSwitchRModel, pos, scale);
	mRSwitch.push_back(switchrfield);
}

void CSwitchRGimmick::Update()
{

}