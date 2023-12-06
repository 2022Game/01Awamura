#include "CKillwoodGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"
#include "Maths.h"

#include <stdlib.h>

#include "time.h"



//int rand(void);
//void srand(unsigned int seed);

CKillwoodGimmick::CKillwoodGimmick()
	:randpos(0)
{
	//srand((unsigned int)time(NULL));
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CKillwoodGimmick::~CKillwoodGimmick()
{
	//// �N���A�y���j��
	for (int i = 0; i < mKillwood.size(); i++)
	{
		mKillwood[i]->Kill();
	}
	// �ꉞ���X�g���N���A���Ă���
	mKillwood.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	//CTaskManager::Instance()->Remove(this);
}

void CKillwoodGimmick::Init()
{
	// �⓹�y��̃��f���ǂݍ���
	mpKillwoodModel = CResourceManager::Get<CModel>("Killwood");
	// �⓹�̓y��𐶐�
	if (CField::mStageCount == 4)
	{

	}
}

void CKillwoodGimmick::CreateKillwood(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpKillwoodModel == nullptr) return;

	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	CKillwood* killwood = new CKillwood(mpKillwoodModel, pos, scale, 1.0f);
	mKillwood.push_back(killwood);
}

void CKillwoodGimmick::Update()
{

}