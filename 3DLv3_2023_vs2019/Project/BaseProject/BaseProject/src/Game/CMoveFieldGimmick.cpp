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
	mpMoveFieldModel = new CModel();
	mpMoveFieldModel->Load("Field\\Object\\10field.obj", "Field\\Object\\10field.mtl");

	// ���[�v�̓y��𐶐�
	//�X�e�[�W0
	if (CField::mStageCount == 1)
	{
		CreateMoveField(mpMoveFieldModel,
			CVector(0.0f, 2.0f, -20.0f), CVector(0.5f, 4.0f, 5.0f));
	}
}

void CMoveFieldGimmick::CreateMoveField(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpMoveFieldModel == nullptr) return;

	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	CMoveField* warp = new CMoveField(mpMoveFieldModel, pos, scale);
	mMoveField.push_back(warp);
}

void CMoveFieldGimmick::Update()
{

}