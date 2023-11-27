#include "CStornGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"



//int rand(void);
//void srand(unsigned int seed);

CStornGimmick::CStornGimmick()
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CStornGimmick::~CStornGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mStorn.size(); i++)
	{
		mStorn[i]->Kill();
	}
	// �ꉞ���X�g���N���A���Ă���
	mStorn.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CStornGimmick::Init()
{
	// �⓹�y��̃��f���ǂݍ���
	mpStornModel = new CModel();
	mpStornModel->Load("Field\\Storn.obj", "Field\\Storn.mtl");

	// �⓹�̓y��𐶐�
	if (CField::mStageCount == 2)
	{
		CreateStorn(mpStornModel,
			CVector(0.0f, 120.0f, -250.0f), CVector(10.0f, 10.0f, 10.0f));

		CreateStorn(mpStornModel,
			CVector(0.0f,80.0f, 0.0f), CVector(10.0f, 10.0f, 10.0f));
	}
}

void CStornGimmick::CreateStorn(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpStornModel == nullptr) return;

	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	CStorn* storn = new CStorn(mpStornModel, pos, scale,0.0f);
	mStorn.push_back(storn);
}

void CStornGimmick::Update()
{
}