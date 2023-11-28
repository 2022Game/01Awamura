#include "CLMoveFieldGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CLMoveFieldGimmick::CLMoveFieldGimmick()
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CLMoveFieldGimmick::~CLMoveFieldGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mLMoveField.size(); i++)
	{
		mLMoveField[i]->Kill();
	}
	// �ꉞ���X�g���N���A���Ă���
	mLMoveField.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CLMoveFieldGimmick::Init()
{
	// �N���A�y��̃��f���ǂݍ���
	mpMoveLModel = new CModel();
	mpMoveLModel->Load("Field\\Object\\Lfield.obj", "Field\\Object\\Lfield.mtl");

	// ���[�v�̓y��𐶐�
	//�X�e�[�W0
	if (CField::mStageCount == 3)
	{
		CreateLMoveField(mpMoveLModel,
			CVector(0.0f, 10.0f, -40.0f), CVector(10.0f, 10.0f, 10.0f));
	}
}

void CLMoveFieldGimmick::CreateLMoveField(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpMoveLModel == nullptr) return;

	// �y��𐶐����ă��X�g�ɒǉ�
	CLMoveField* Lfield = new CLMoveField(mpMoveLModel, pos, scale,1.0f);
	mLMoveField.push_back(Lfield);
}

void CLMoveFieldGimmick::Update()
{

}