#include "CMoveFieldGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CMoveFieldGimmick::CMoveFieldGimmick()
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CMoveFieldGimmick::~CMoveFieldGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mMoveField.size(); i++)
	{
		mMoveField[i]->Kill();
	}
	// �ꉞ���X�g���N���A���Ă���
	mMoveField.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CMoveFieldGimmick::Init()
{
	// �N���A�y��̃��f���ǂݍ���
	mpMoveTenModel = new CModel();
	mpMoveTenModel->Load("Field\\Object\\10field.obj", "Field\\Object\\10field.mtl");

	// ���[�v�̓y��𐶐�
	//�X�e�[�W0
	if (CField::mStageCount == 3)
	{
		CreateMoveField(mpMoveTenModel,
			CVector(0.0f, 0.0f, 0.0f), CVector(10.0f, 10.0f, 10.0f));
	}
}

void CMoveFieldGimmick::CreateMoveField(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpMoveTenModel == nullptr) return;

	//// �y��𐶐����ă��X�g�ɒǉ�
	//CMoveField* tenfield = new CMoveField(mpMoveTenModel, pos, scale);
	//mMoveField.push_back(tenfield);

	CMoveField* tenfield = new CMoveField(mpMoveTenModel, pos, scale,1.0f);
	mMoveField.push_back(tenfield);
	//CVector offset = CVector(0.0f, 0.0f, 5.0f);
	//tenfield = new CMoveField(mpMoveTenModel, CVector(0.0f, 200.0f, -80.0f), CVector(5.5f, 5.0f, 5.25f), 5.0f, -45.0f);
	//mMoveField.push_back(tenfield);
}

void CMoveFieldGimmick::Update()
{

}