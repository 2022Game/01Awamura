#pragma once
#include "CStageBase.h"

//�X�e�[�W6�u���邮��꒵�уX�e�[�W�v
class CStage6 : public CStageBase
{
public:
	//�R���X�g���N�^
	CStage6();
	//�f�X�g���N�^
	~CStage6();

	//�X�e�[�W�ǂݍ���
	void Load() override;
	//�X�e�[�W�j��
	void Unload() override;

private:
};