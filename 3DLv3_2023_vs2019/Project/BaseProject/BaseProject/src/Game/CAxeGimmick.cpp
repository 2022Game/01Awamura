#include "CAxeGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CAxeGimmick::CAxeGimmick()
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CAxeGimmick::~CAxeGimmick()
{
	////����j��
	for (int i = 0; i < mAxe.size(); i++)
	{
		mAxe[i]->Kill();
		//delete mClearStage[i];
	}
	// �ꉞ���X�g���N���A���Ă���
	mAxe.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CAxeGimmick::Init()
{
	// �N���A�y��̃��f���ǂݍ���
	mpAxeModel = new CModel();
	//mpClearStageModel->Load("Field\\ono7.obj", "Field\\ono7.mtl");
	mpAxeModel->Load("Field\\ono7.obj", "Field\\ono7.mtl");

	// �N���A����p�̓y��𐶐�
	//�X�e�[�W�P
	if (CField::mStageCount == 1 && CField::mStageCreateSwitch == 1)
	{
		CreateAxe(mpAxeModel,CVector(0.0f, 200.0f, -140.0f), CVector(5.5f, 5.0f, 5.25f));
	}
}

void CAxeGimmick::CreateAxe(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpAxeModel == nullptr) return;

	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	CAxe* axe = new CAxe(mpAxeModel, pos, scale,5.0f,45.0f);
	mAxe.push_back(axe);
	CVector offset = CVector(0.0f, 0.0f, 5.0f);
	axe = new CAxe(mpAxeModel, CVector(0.0f, 200.0f, -80.0f), CVector(5.5f, 5.0f, 5.25f), 5.0f, -45.0f);
	mAxe.push_back(axe);
	/*axe = new CAxe(mpAxeModel, CVector(0.0f, 200.0f, -120.0f), CVector(5.5f, 5.0f, 5.25f), 5.0f, -45.0f);
	mAxe.push_back(axe);*/
}

void CAxeGimmick::Update()
{
	
}