#pragma once
#include "CModel.h"

class CApplication
{
private:
	CModel mBackGround;
public:
	~CApplication();

	//�ŏ��Ɉ�x�������s����v���O����
	void Start();
	//�J��Ԃ����s����v���O����
	void Update();
};