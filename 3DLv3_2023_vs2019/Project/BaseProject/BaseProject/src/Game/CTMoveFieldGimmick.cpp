#include "CTMoveFieldGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CTMoveFieldGimmick::CTMoveFieldGimmick()
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CTMoveFieldGimmick::~CTMoveFieldGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mTMoveField.size(); i++)
	{
		mTMoveField[i]->Kill();
	}
	// �ꉞ���X�g���N���A���Ă���
	mTMoveField.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CTMoveFieldGimmick::Init()
{
	// �N���A�y��̃��f���ǂݍ���
	mpMoveTModel = new CModel();
	mpMoveTModel->Load("Field\\Object\\Tfield.obj", "Field\\Object\\Tfield.mtl");

	// ���[�v�̓y��𐶐�
	//�X�e�[�W0
	if (CField::mStageCount == 3)
	{
		CreateTMoveField(mpMoveTModel,
			CVector(0.0f, 0.0f, 0.0f), CVector(10.0f, 10.0f, 10.0f));
	}
}

void CTMoveFieldGimmick::CreateTMoveField(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpMoveTModel == nullptr) return;

	// �y��𐶐����ă��X�g�ɒǉ�
	CTMoveField* tenfield = new CTMoveField(mpMoveTModel, pos, scale);
	mTMoveField.push_back(tenfield);
}

void CTMoveFieldGimmick::Update()
{

}