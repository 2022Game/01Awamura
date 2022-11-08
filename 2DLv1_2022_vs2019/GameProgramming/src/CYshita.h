#pragma once
#include "CCharacter.h"

class CYshita : public CCharacter
{
public:
	//CShita(X座標,Y座標,幅,高さ,テクスチャのポインタ)
	CYshita(float x, float y, float w, float h, CTexture* pt);
	CYshita();
	void Update() ;
};