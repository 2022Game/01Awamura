#pragma once
#include "CStageBase.h"

//�X�e�[�W�u�����v
class CStageEntrance : public CStageBase
{
public:
	//�R���X�g���N�^
	CStageEntrance();
	//�f�X�g���N�^
	~CStageEntrance();

	//�X�e�[�W�ǂݍ���
	void Load() override;
	//�X�e�[�W�j��
	void Unload() override;

private:
};