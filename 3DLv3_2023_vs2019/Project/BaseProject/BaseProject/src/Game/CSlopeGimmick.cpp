#include "CSlopeGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"



//int rand(void);
//void srand(unsigned int seed);

CSlopeGimmick::CSlopeGimmick()
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CSlopeGimmick::~CSlopeGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mSlope.size(); i++)
	{
		mSlope[i]->Kill();
	}
	// �ꉞ���X�g���N���A���Ă���
	mSlope.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CSlopeGimmick::Init()
{
	// �⓹�y��̃��f���ǂݍ���
	mpSlopeModel = CResourceManager::Get<CModel>("Slope");
	// �⓹�̓y��𐶐�
	if (CField::mStageCount == 2)
	{
		
	}
}

void CSlopeGimmick::CreateSlope(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpSlopeModel == nullptr) return;

	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	CSlope* warp = new CSlope(mpSlopeModel, pos, scale);
	mSlope.push_back(warp);
}

void CSlopeGimmick::Update()
{

}