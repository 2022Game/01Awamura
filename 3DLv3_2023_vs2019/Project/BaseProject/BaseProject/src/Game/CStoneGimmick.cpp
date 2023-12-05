#include "CStoneGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"
#include "Maths.h"

#include <stdlib.h>

#include "time.h"



//int rand(void);
//void srand(unsigned int seed);

CStoneGimmick::CStoneGimmick()
	:randpos(0)
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CStoneGimmick::~CStoneGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mStone.size(); i++)
	{
		mStone[i]->Kill();
	}
	// �ꉞ���X�g���N���A���Ă���
	mStone.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CStoneGimmick::Init()
{
	// �⓹�y��̃��f���ǂݍ���
	mpStoneModel = new CModel();
	mpStoneModel->Load("Field\\Stone.obj", "Field\\Stone.mtl");

	// �⓹�̓y��𐶐�
	if (CField::mStageCount == 2)
	{
		
	}
}

void CStoneGimmick::CreateStone(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpStoneModel == nullptr) return;

	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	CStone* stone = new CStone(mpStoneModel, pos, scale,0.0f);
	mStone.push_back(stone);
}

void CStoneGimmick::Update()
{
	
}