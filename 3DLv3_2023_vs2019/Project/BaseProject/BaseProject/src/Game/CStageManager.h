#pragma once
class CStageBase;

//�X�e�[�W�̊Ǘ��N���X
class CStageManager
{
public:
	//�X�e�[�W�ǂݍ���
	static void LoadStage(int no);
	//���݂̃X�e�[�W�j��
	static void UnloadStage();
	//�쐬�����^�X�N�����X�g�ɒǉ�
	static void AddTask(CTask* task);
	//�쐬�����^�X�N�����X�g�����菜��
	static void RemoveTask(CTask* task);
private:
	//�R���X�g���N�^
	CStageManager();
	//�f�X�g���N�^
	~CStageManager();

	//�X�e�[�W�}�l�[�W���[�̃C���X�^���X
	static CStageManager* spInstance;
	static CStageBase* spCurrentStage; // ���݂̃X�e�[�W
};