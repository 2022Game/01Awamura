#pragma once
#include "CCharacter.h"

#define KABE "111.png"//��
#define TEXTURE1 "image.png"

class CZkau1 : public CCharacter
{
private:
public:
	//�Փˏ���2
	void Collision();
	//�Փˏ���4
	void Collision(CCharacter* m, CCharacter* o);
	//CZkau1(X���W,Y���W,��,����,�摜�E,�摜��,�摜��,�摜��,�e�N�X�`���̃|�C���^)
	CZkau1(float x, float y, float w, float h, CTexture* pt);
	void Update();
};