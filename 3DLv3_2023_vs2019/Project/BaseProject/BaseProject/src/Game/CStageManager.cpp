#include "CStageManager.h"
#include "CStageBase.h"
#include "CStageEntrance.h"
#include "CStage1.h"
#include "CStage2.h"
#include "CStage3.h"
#include "CStage4.h"
#include "CStage5.h"
#include "CStage6.h"

CStageManager* CStageManager::spInstance = nullptr;
CStageBase* CStageManager::spCurrentStage = nullptr;

//�R���X�g���N�^
CStageManager::CStageManager()
{
	spInstance = this;
}

//�f�X�g���N�^
CStageManager::~CStageManager()
{
	spInstance = nullptr;

	//�X�e�[�W���ǂݍ��܂�Ă�����j��
	UnloadStage();
}

//�X�e�[�W�ǂݍ���
void CStageManager::LoadStage(int no)
{
	//���ɃX�e�[�W���ǂݍ��܂�Ă�����j��
	UnloadStage();

	//�X�e�[�W�ԍ��ɍ��킹�ăX�e�[�W��ǂݍ���
	switch (no)
	{
	case 0:spCurrentStage = new CStageEntrance(); break;
	case 1:spCurrentStage = new CStage1(); break;
	case 2:spCurrentStage = new CStage2(); break;
	case 3:spCurrentStage = new CStage3(); break;
	case 4:spCurrentStage = new CStage4(); break;
	case 5:spCurrentStage = new CStage5(); break;
	case 6:spCurrentStage = new CStage6(); break;

	//�w�肳��Ă��Ȃ��X�e�[�W�ɂȂ�����
	default:spCurrentStage = new CStage6(); break;
	}

	//�X�e�[�W���쐬�ł�����X�e�[�W��ǂݍ���
	if (spCurrentStage != nullptr)
	{
		spCurrentStage->Load();
	}
}

//���݂̃X�e�[�W��j��
void CStageManager::UnloadStage()
{
	if (spCurrentStage == nullptr)return;
	spCurrentStage->Unload();
	SAFE_DELETE(spCurrentStage);
}

//�쐬�����^�X�N�����X�g�ɒǉ�
void CStageManager::AddTask(CTask* task)
{
	if (spCurrentStage == nullptr)return;
	spCurrentStage->AddTask(task);
}

//�쐬�����^�X�N�����X�g�����菜��
void CStageManager::RemoveTask(CTask* task)
{
	if (spCurrentStage == nullptr)return;
	spCurrentStage->RemoveTask(task);
}