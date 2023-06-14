#include "CTask.h"

//�R���X�g���N�^
CTask::CTask()
	: mpNext(nullptr)
	, mpPrev(nullptr)
	, mPriority((int)TaskPriority::eDefault)
	, mEnabled(true)
	, mPauseType(TaskPauseType::eDefault)
{
}

//�f�X�g���N�^
CTask::~CTask()
{
}

//�X�V
void CTask::Update()
{
}

//�`��
void CTask::Render()
{
}

//�|�[�Y�̎�ނ�ݒ�
void CTask::SetPauseType(TaskPauseType type)
{
	mPauseType = type;
}

//�|�[�Y�̎�ނ��擾
TaskPauseType CTask::GetPauseType() const
{
	return mPauseType;
}