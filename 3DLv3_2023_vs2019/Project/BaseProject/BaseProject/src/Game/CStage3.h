#pragma once
#include "CStageBase.h"

//�X�e�[�W3�u���邮��p�Y���Q�[���v
class CStage3 : public CStageBase
{
public:
	//�R���X�g���N�^
	CStage3();
	//�f�X�g���N�^
	~CStage3();

	//�X�e�[�W�ǂݍ���
	void Load() override;
	//�X�e�[�W�j��
	void Unload() override;

private:
};