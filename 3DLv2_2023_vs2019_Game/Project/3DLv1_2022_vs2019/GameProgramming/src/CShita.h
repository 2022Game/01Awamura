#pragma once
#include "CCharacter.h"

class CShita : public CCharacter
{
public:
	//CShita(X座標,Y座標,幅,高さ,テクスチャのポインタ)
	CShita(float x, float y, float w, float h, CTexture* pt);
	void Update() {};
};

