#pragma once
#include "CCharacter.h"

#define KABE "111.png"//��

class CZkah : public CCharacter
{
private:
public:
	//�Փˏ����Q
	void Collision();
	//�Փˏ����S
	void Collision(CCharacter* m, CCharacter* o);
	//CZkah(X���W,Y���W,��,����,�摜�E,�摜��,�摜��,�摜��,�e�N�X�`���̃|�C���^)
	CZkah(float x, float y, float w, float h,CTexture* pt);
	void Update();
};