#pragma once
#include "CCharacter.h"

class CFpenC : public CCharacter
{
public:
	//�Փˏ���2
	void Collision();
	//�Փˏ���4
	void Collision(CCharacter* m, CCharacter* o);
	//CFpenA(X���W,Y���W,��,����,�e�N�X�`���̃|�C���^)
	CFpenC(float x, float y, float w, float h, CTexture* pt);
	//�X�V����
	void Update();
private:
};