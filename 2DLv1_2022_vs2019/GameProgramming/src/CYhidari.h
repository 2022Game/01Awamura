#pragma once
#include "CCharacter.h"

class CYhidari : public CCharacter
{
public:
	//CShita(X���W,Y���W,��,����,�e�N�X�`���̃|�C���^)
	CYhidari(float x, float y, float w, float h, CTexture* pt);
	CYhidari();
	void Update() ;
private:
	int alpha;
};
