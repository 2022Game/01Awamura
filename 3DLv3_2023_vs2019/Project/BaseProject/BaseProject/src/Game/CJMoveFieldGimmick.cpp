#include "CJMoveFieldGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CJMoveFieldGimmick::CJMoveFieldGimmick()
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CJMoveFieldGimmick::~CJMoveFieldGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mJMoveField.size(); i++)
	{
		mJMoveField[i]->Kill();
	}
	// �ꉞ���X�g���N���A���Ă���
	mJMoveField.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CJMoveFieldGimmick::Init()
{
	// �N���A�y��̃��f���ǂݍ���
	mpMoveJModel = new CModel();
	mpMoveJModel->Load("Field\\Object\\Jfield.obj", "Field\\Object\\Jfield.mtl");

	// ���[�v�̓y��𐶐�
	//�X�e�[�W0
	if (CField::mStageCount == 3)
	{
		CreateJMoveField(mpMoveJModel,
			CVector(0.0f, 10.0f, -60.0f), CVector(10.0f, 10.0f, 10.0f));
	}
}

void CJMoveFieldGimmick::CreateJMoveField(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpMoveJModel == nullptr) return;

	// �y��𐶐����ă��X�g�ɒǉ�
	CJMoveField* jfield = new CJMoveField(mpMoveJModel, pos, scale,1.0f);
	mJMoveField.push_back(jfield);
}

void CJMoveFieldGimmick::Update()
{

}