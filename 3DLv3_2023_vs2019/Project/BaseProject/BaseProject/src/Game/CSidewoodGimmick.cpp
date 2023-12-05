#include "CSidewoodGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"
#include "Maths.h"

#include <stdlib.h>

#include "time.h"



//int rand(void);
//void srand(unsigned int seed);

CSidewoodGimmick::CSidewoodGimmick()
	:randpos(0)
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CSidewoodGimmick::~CSidewoodGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mSidewood.size(); i++)
	{
		mSidewood[i]->Kill();
	}
	// �ꉞ���X�g���N���A���Ă���
	mSidewood.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CSidewoodGimmick::Init()
{
	// �⓹�y��̃��f���ǂݍ���
	mpSidewoodModel = new CModel();
	mpSidewoodModel->Load("Field\\Killbranc.obj", "Field\\Killbranc.mtl");

	// �⓹�̓y��𐶐�
	if (CField::mStageCount == 4)
	{
		
	}
}

void CSidewoodGimmick::CreateSidewood(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpSidewoodModel == nullptr) return;

	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	CSidewood* sidewood = new CSidewood(mpSidewoodModel, pos, scale, 1.0f);
	mSidewood.push_back(sidewood);

	CVector offset = CVector(0.0f, 0.0f, 5.0f);
	sidewood = new CSidewood(mpSidewoodModel, CVector(0.0f, 6.0f, -30.0f), CVector(5.5f, 5.0f, 5.25f), 1.0f);
	mSidewood.push_back(sidewood);
}

void CSidewoodGimmick::Update()
{

}