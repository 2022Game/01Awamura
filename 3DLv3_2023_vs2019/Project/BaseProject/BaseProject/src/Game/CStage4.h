#pragma once
#include "CStageBase.h"

//�X�e�[�W4�u���邮��꒵�уX�e�[�W�v
class CStage4 : public CStageBase
{
public:
	//�R���X�g���N�^
	CStage4();
	//�f�X�g���N�^
	~CStage4();

	//�X�e�[�W�ǂݍ���
	void Load() override;
	//�X�e�[�W�j��
	void Unload() override;

private:
};