#pragma once
#include "CStageBase.h"

//�X�e�[�W2�u��΍⓹�X�e�[�W�v
class CStage2 : public CStageBase
{
public:
	//�R���X�g���N�^
	CStage2();
	//�f�X�g���N�^
	~CStage2();

	//�X�e�[�W�ǂݍ���
	void Load() override;
	//�X�e�[�W�j��
	void Unload() override;

private:
};