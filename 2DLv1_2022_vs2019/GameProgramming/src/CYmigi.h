#pragma once
#include "CCharacter.h"

class CYmigi : public CCharacter
{
public:
	//CShita(X���W,Y���W,��,����,�e�N�X�`���̃|�C���^)
	CYmigi(float x, float y, float w, float h, CTexture* pt);
	CYmigi();
	void Update() ;
};
