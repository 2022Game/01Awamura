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
	mpMoveSwitchLModel = CResourceManager::Get<CModel>("Lswitch");
	// ���[�v�̓y��𐶐�
	//�X�e�[�W0
	if (CField::mStageCount == 3)
	{

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