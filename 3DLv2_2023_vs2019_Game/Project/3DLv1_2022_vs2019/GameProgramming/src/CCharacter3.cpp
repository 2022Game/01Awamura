#include "CCharacter3.h"
#include "CApplication.h"

CCharacter3::CCharacter3()
	:mpModel(nullptr)
	, mTag(ETag::EZERO)
{
	SetPauseType(TaskPauseType::eGame);

	//�^�X�N���X�g�ɒǉ�
//	CApplication::TaskManager()->Add(this);
	CTaskManager::Instance()->Add(this);
}

CCharacter3::CCharacter3(int priority)
	:mpModel(nullptr)
	, mTag(ETag::EZERO)
{
	SetPauseType(TaskPauseType::eGame);

	mPriority = priority;
	CTaskManager::Instance()->Add(this);
}

CCharacter3::ETag CCharacter3::Tag()
{
	return mTag;
}

CCharacter3::~CCharacter3()
{
	//�^�X�N���X�g����폜
//	CApplication::TaskManager()->Remove(this);
	CTaskManager::Instance()->Remove(this);
}

void CCharacter3::Model(CModel* m)
{
	mpModel = m;
}

//�`�揈��
void CCharacter3::Render()
{
	mpModel->Render(Matrix());
}

//�L�����N�^�[�폜
void CCharacter3::Kill()
{
	mEnabled = false;
}

//�L�����N�^�[������ł��邩�ǂ���
bool CCharacter3::IsDeath() const
{
	//HP���O�ȉ��Ȃ玀��ł���
	return mHp <= 0;
}

//CLEAR�������ǂ���
bool CCharacter3::IsClear() const
{
	//�X�e�[�W�J�E���g��4�Ȃ�CLEAR
	return CApplication::StageCount == 5;
}