#pragma once
#include "CCharacter.h"
#include "CUi.h"

#define MU "111.png"//��

class CZkabe : public CCharacter
{
private:
	
public:
	static int sNow;
	static int Now();
	//�Փˏ���2
	void Collision();
	//�Փˏ���4
	void Collision(CCharacter* m, CCharacter* o);
	//CZkau1(X���W,Y���W,��,����,�摜�E,�摜��,�摜��,�摜��,�e�N�X�`���̃|�C���^)
	CZkabe(float x, float y, float w, float h, float l, float r, float b, float t, CTexture* pt);
	void Update();
};