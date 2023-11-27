#include "CIMoveFieldGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CIMoveFieldGimmick::CIMoveFieldGimmick()
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CIMoveFieldGimmick::~CIMoveFieldGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mIMoveField.size(); i++)
	{
		mIMoveField[i]->Kill();
	}
	// �ꉞ���X�g���N���A���Ă���
	mIMoveField.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CIMoveFieldGimmick::Init()
{
	// �N���A�y��̃��f���ǂݍ���
	mpMoveIModel = new CModel();
	mpMoveIModel->Load("Field\\Object\\Ifield.obj", "Field\\Object\\Ifield.mtl");

	// ���[�v�̓y��𐶐�
	//�X�e�[�W0
	if (CField::mStageCount == 3)
	{
		CreateIMoveField(mpMoveIModel,
			CVector(0.0f, 10.0f, -80.0f), CVector(10.0f, 10.0f, 10.0f));
	}
}

void CIMoveFieldGimmick::CreateIMoveField(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpMoveIModel == nullptr) return;

	// �y��𐶐����ă��X�g�ɒǉ�
	CIMoveField* ifield = new CIMoveField(mpMoveIModel, pos, scale);
	mIMoveField.push_back(ifield);
}

void CIMoveFieldGimmick::Update()
{

}