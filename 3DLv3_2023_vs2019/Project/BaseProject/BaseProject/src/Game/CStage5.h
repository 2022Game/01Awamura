#pragma once
#include "CStageBase.h"

//�X�e�[�W5�u�������X�e�[�W�v
class CStage5 : public CStageBase
{
public:
	//�R���X�g���N�^
	CStage5();
	//�f�X�g���N�^
	~CStage5();

	//�X�e�[�W�ǂݍ���
	void Load() override;
	//�X�e�[�W�j��
	void Unload() override;

private:
	int RandPos;
	float RandPosX;
	float RandPosZ;
	float PosY;
	float PosY2;
};