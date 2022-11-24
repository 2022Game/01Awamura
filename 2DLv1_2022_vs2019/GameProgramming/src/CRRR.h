#pragma once
#include "CCharacter.h"

class CRRR : public CCharacter
{
public:
	//CShita(X座標,Y座標,幅,高さ,テクスチャのポインタ)
	CRRR(float x, float y, float w, float h, CTexture* pt);
	CRRR();
	void Update();
};