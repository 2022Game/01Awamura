#include "CGameManager.h"
#include "CStageManager.h"
#include "Maths.h"

CGameManager* CGameManager::spInstance = nullptr;

//�R���X�g���N�^
CGameManager::CGameManager()
	:mStageNo(0)
	,mStageNoswitch(0)
	,mStageClearCount(0)
	,mState(EGameState::eReady)
	,mStateStep(0)
	,mElapsedTime(0.0f)
	,RandCount(7)
{
	n[0] = 1;
	n[1] = 2;
	n[2] = 3;
	n[3] = 4;
	n[4] = 5;
	n[5] = 6;
	n[6] = 7;
	n[7] = 8;
}

//�f�X�g���N�^
CGameManager::~CGameManager()
{

}

//�C���X�^���X�擾
CGameManager* CGameManager::Instance()
{
	if (spInstance == nullptr)
	{
		spInstance = new CGameManager();
	}
	return spInstance;
}

//�Q�[���J�n
void CGameManager::GameStart()
{
	//������ԂłȂ���΃Q�[���J�n�͂��Ȃ�
	if (GameState() != EGameState::eReady)return;

	//�ŏ��̃X�e�[�W��ǂݍ���
	CStageManager::LoadStage(Instance()->mStageNo);

	//�Q�[���J�n
	Instance()->ChangeState(EGameState::eGame);
}

//�X�e�[�W�N���A
void CGameManager::StageClear()
{
	Instance()->ChangeState(EGameState::eStageClear);
}

//�Q�[���I�[�o�[
void CGameManager::GameOver()
{
	Instance()->ChangeState(EGameState::eGameOver);
}

//���݂̃Q�[���̏�Ԃ��擾
EGameState CGameManager::GameState()
{
	return Instance()->mState;
}

//���݂̃X�e�[�W�ԍ����擾
int CGameManager::StageNo()
{
	return Instance()->mStageNo;
}

//���݂̃X�e�[�W�i�s���擾
int CGameManager::StageClearCount()
{
	return Instance()->mStageClearCount;
}

//���݂̃Q�[���̏�Ԃ�؂�ւ���
void CGameManager::ChangeState(EGameState state)
{
	if (mState == state)return;
	mState = state;
	mStateStep = 0;
	mElapsedTime = 0.0f;
}

//������Ԃ̍X�V����
void CGameManager::UpdateReady()
{

}

//�Q�[�����̍X�V����
void CGameManager::UpdateGame()
{

}

//�X�e�[�W�N���A���̍X�V����
void CGameManager::UpdateStageClear()
{
	//�X�e�[�W��CLEAR�������ɃJ�E���g��+����
	mStageClearCount++;

	//�X�e�[�W���N���A�����玟�̃X�e�[�W��ǂݍ���
	//�d�����Ȃ������_���̐����p�̔z��
	//�X�e�[�W�͂S�܂�
	if (mStageClearCount < 5)
	{
		int x;
		x = 0;
		mStageNoswitch = Math::Rand(0, RandCount);
		x = mStageNoswitch;
		mStageNo = n[mStageNoswitch];
		n[x] = n[RandCount];
		RandCount = RandCount - 1;
		CStageManager::LoadStage(mStageNo);
	}

	//�X�e�[�W���S��CLEAR������I��
	if (mStageClearCount >= 5)
	{
		mStageNo = 0;
		CStageManager::LoadStage(mStageNo);
	}

	//�X�e�[�W�̓ǂݍ��݂��I���΃Q�[���J�n
	ChangeState(EGameState::eGame);
}

//�Q�[���N���A���̍X�V����
void CGameManager::UpdateGameClear()
{

}

//�Q�[���I�[�o�[���̍X�V����
void CGameManager::UpdateGameOver()
{

}

//�X�V
void CGameManager::Update()
{
	//���݂̏�Ԃɍ��킹���X�V�������s��
	switch (mState)
	{
		//������
	case EGameState::eReady:
		UpdateReady();
		break;
		//�Q�[����
	case EGameState::eGame:
		UpdateGame();
		break;
		//�X�e�[�W�N���A
	case EGameState::eStageClear:
		UpdateStageClear();
		break;
		//�Q�[���N���A
	case EGameState::eGameClear:
		UpdateGameClear();
		break;
		//�Q�[���I�[�o�[
	case EGameState::eGameOver:
		UpdateGameOver();
		break;
	}
}