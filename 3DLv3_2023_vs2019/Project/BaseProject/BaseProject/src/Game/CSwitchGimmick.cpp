#include "CSwitchGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CSwitchGimmick::CSwitchGimmick()
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CSwitchGimmick::~CSwitchGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mSwitch.size(); i++)
	{
		mSwitch[i]->Kill();
	}
	// �ꉞ���X�g���N���A���Ă���
	mSwitch.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CSwitchGimmick::Init()
{
	// �N���A�y��̃��f���ǂݍ���
	mpMoveSwitchModel = new CModel();
	mpMoveSwitchModel->Load("Field\\Object\\switchRed.obj", "Field\\Object\\switchRed.mtl");

	// ���[�v�̓y��𐶐�
	//�X�e�[�W0
	if (CField::mStageCount == 3)
	{
		CreateSwitch(mpMoveSwitchModel,
			CVector(0.0f, 0.0f, -1.5f), CVector(10.0f, 10.0f, 10.0f));
	}
}

void CSwitchGimmick::CreateSwitch(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpMoveSwitchModel == nullptr) return;

	//// �y��𐶐����ă��X�g�ɒǉ�
	//CSwitch* tenfield = new CSwitch(mpMoveTenModel, pos, scale);
	//mSwitch.push_back(tenfield);

	CSwitchObject* switchfield = new CSwitchObject(mpMoveSwitchModel, pos, scale, 1.0f);
	mSwitch.push_back(switchfield);
	//CVector offset = CVector(0.0f, 0.0f, 5.0f);
	//tenfield = new CSwitch(mpMoveTenModel, CVector(0.0f, 200.0f, -80.0f), CVector(5.5f, 5.0f, 5.25f), 5.0f, -45.0f);
	//mSwitch.push_back(tenfield);
}

void CSwitchGimmick::Update()
{

}