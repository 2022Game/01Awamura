#pragma once
#include "CCharacter.h"

class CRRR : public CCharacter
{
public:
	//CShita(X���W,Y���W,��,����,�e�N�X�`���̃|�C���^)
	CRRR(float x, float y, float w, float h, CTexture* pt);
	CRRR();
	void Update();
};