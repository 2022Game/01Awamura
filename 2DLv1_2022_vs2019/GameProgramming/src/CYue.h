#pragma once
#include "CCharacter.h"

class CYue : public CCharacter
{
public:
	//CYazirusi(X���W,Y���W,��,����,�e�N�X�`���̃|�C���^)
	CYue(float x, float y, float w, float h, CTexture* pt);
	CYue();
	void Update();
};