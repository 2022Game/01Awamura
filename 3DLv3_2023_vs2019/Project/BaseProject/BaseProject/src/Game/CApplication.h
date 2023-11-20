#pragma once
#include "CModel.h"

class CApplication
{
private:
	CModel mBackGround;
public:
	~CApplication();

	//最初に一度だけ実行するプログラム
	void Start();
	//繰り返し実行するプログラム
	void Update();
};