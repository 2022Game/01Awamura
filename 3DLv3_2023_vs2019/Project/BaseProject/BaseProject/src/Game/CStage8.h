#pragma once
#include "CStageBase.h"

//�������̔z�u��
#define BLOCK_COUNT_X 9
//�c�����̔z�u��
#define BLOCK_COUNT_Y 10
//�u���b�N��z�u����ő吔
#define MAX_BLOCK_COUNT 30
//�X�e�[�W2�u��΍⓹�X�e�[�W�v
class CStage8 : public CStageBase
{
public:
	//�R���X�g���N�^
	CStage8();
	//�f�X�g���N�^
	~CStage8();

	//�X�e�[�W�ǂݍ���
	void Load() override;
	//�X�e�[�W�j��
	void Unload() override;

private:
	//�ǂɂԂ���܂ňړ����āA�ʂ����}�X���ړ����[�g�ɂ���B
	int PaveTheRoute(int x, int y, int moveX, int moveY);

	//�u���b�N�̔z�u�f�[�^���쐬
	void CreateBlockData();

	//�u���b�N�̔z�u�f�[�^
	//(0:�Ȃɂ��Ȃ��A�P�F�u���b�N�z�u�A�Q�F�ړ����[�g�j
	int mBlockData[BLOCK_COUNT_X][BLOCK_COUNT_Y];
	//int mBlockData[9][10];
};