#pragma once
#include "CCharacter.h"

#define KABE "111.png"//��

class CZkau : public CCharacter
{
private:
public:
	//�Փˏ���2
	void Collision();
	//�Փˏ���4
	void Collision(CCharacter* m, CCharacter* o);
	//CZkau(X���W,Y���W,��,����,�摜�E,�摜��,�摜��,�摜��,�e�N�X�`���̃|�C���^)
	CZkau(float x, float y, float w, float h,  CTexture* pt);
	void Update();
};