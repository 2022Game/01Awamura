#include "CBollFieldGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CBollFieldGimmick::CBollFieldGimmick()
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CBollFieldGimmick::~CBollFieldGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mBollField.size(); i++)
	{
		mBollField[i]->Kill();
	}
	// �ꉞ���X�g���N���A���Ă���
	mBollField.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CBollFieldGimmick::Init()
{
	// �N���A�y��̃��f���ǂݍ���
	mpBollFieldModel = CResourceManager::Get<CModel>("Bollfield");

	if (CField::mStageCount == 4)
	{
		
	}
}

void CBollFieldGimmick::CreateBollField(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpBollFieldModel == nullptr) return;

	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	CBollField* warp = new CBollField(mpBollFieldModel, pos, scale);
	mBollField.push_back(warp);
}

void CBollFieldGimmick::Update()
{

}