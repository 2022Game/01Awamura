#include "CFloorGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CFloorGimmick::CFloorGimmick()
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CFloorGimmick::~CFloorGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mFloor.size(); i++)
	{
		mFloor[i]->Kill();
	}
	// �ꉞ���X�g���N���A���Ă���
	mFloor.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CFloorGimmick::Init()
{
	// �N���A�y��̃��f���ǂݍ���
	mpFloorModel = CResourceManager::Get<CModel>("Floor");
	// ���[�v�̓y��𐶐�
	//�X�e�[�W0
	if (CField::mStageCount == 0)
	{
	}
	if (CField::mStageCount == 1)
	{
	}
	if (CField::mStageCount == 2)
	{
	}
	if (CField::mStageCount == 3)
	{
		
	}
	if (CField::mStageCount == 4)
	{
		CreateFloor(mpFloorModel,
			CVector(0.0f, -10.0f, 0.0f), CVector(5.0f, 4.0f, 1.0f));
	}
}

void CFloorGimmick::CreateFloor(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpFloorModel == nullptr) return;

	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	CFloor* warp = new CFloor(mpFloorModel, pos, scale);
	mFloor.push_back(warp);
}

void CFloorGimmick::Update()
{

}