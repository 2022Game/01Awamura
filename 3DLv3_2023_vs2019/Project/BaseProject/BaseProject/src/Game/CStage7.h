#pragma once
#include "CStageBase.h"
#include "CText.h"

//�X�e�[�W7�u�������X�e�[�W�v
class CStage7 : public CStageBase
{
public:
	//�R���X�g���N�^
	CStage7();
	//�f�X�g���N�^
	~CStage7();

	//�X�e�[�W�ǂݍ���
	void Load() override;
	//�X�e�[�W�j��
	void Unload() override;

private:
	CText* mpText;
	CText* mpTextShadow;
	int n;
	int z;
	int RandPos;
	int RandPos2;
	int RandPos3;
	int RandPosDate;
	int RandPosDate2;
	int RandPosDate3;
	int RandPosDate4;
	int RandPosDate5;
	int RandPosDate6;
	float RandPosX;
	float RandPosX2;
	float RandPosZ;
	float RandPosZ2;
	float PosY;
	float PosY2;
	float PosZ;
};