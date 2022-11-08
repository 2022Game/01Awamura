#pragma once
#include "CCharacter.h"

class CYhidari : public CCharacter
{
public:
	//CShita(X座標,Y座標,幅,高さ,テクスチャのポインタ)
	CYhidari(float x, float y, float w, float h, CTexture* pt);
	CYhidari();
	void Update() ;
private:
	int alpha;
};
