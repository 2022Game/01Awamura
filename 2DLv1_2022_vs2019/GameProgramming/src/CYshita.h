#pragma once
#include "CCharacter.h"

class CYshita : public CCharacter
{
public:
	//CShita(X���W,Y���W,��,����,�e�N�X�`���̃|�C���^)
	CYshita(float x, float y, float w, float h, CTexture* pt);
	CYshita();
	void Update() ;
};