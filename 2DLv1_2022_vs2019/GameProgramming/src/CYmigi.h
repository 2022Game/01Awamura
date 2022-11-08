#pragma once
#include "CCharacter.h"

class CYmigi : public CCharacter
{
public:
	//CShita(X座標,Y座標,幅,高さ,テクスチャのポインタ)
	CYmigi(float x, float y, float w, float h, CTexture* pt);
	CYmigi();
	void Update() ;
};
