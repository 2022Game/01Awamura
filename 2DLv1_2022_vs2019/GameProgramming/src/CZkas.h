#pragma once
#include "CCharacter.h"
#include "CSound.h"

#define KABE "111.png"//��

class CZkas : public CCharacter
{
private:
public:
	CSound mSound;
	//�Փˏ���2
	void Collision();
	//�Փˏ���4
	void Collision(CCharacter* m, CCharacter* o);
	//CZkas(X���W,Y���W,��,����,�摜�E,�摜��,�摜��,�摜��,�e�N�X�`���̃|�C���^)
	CZkas(float x, float y, float w, float h, CTexture* pt);
	void Update();
}; 
