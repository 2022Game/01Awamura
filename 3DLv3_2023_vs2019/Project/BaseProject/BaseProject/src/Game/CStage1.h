#pragma once
#include "CStageBase.h"

//�X�e�[�W�P�u���U��q�X�e�[�W�v
class CStage1 : public CStageBase
{
public:
	//�R���X�g���N�^
	CStage1();
	//�f�X�g���N�^
	~CStage1();

	//�X�e�[�W�ǂݍ���
	void Load() override;
	//�X�e�[�W�j��
	void Unload() override;

private:
};