#pragma once
#include "CCharacter.h"

class CYue : public CCharacter
{
public:
	//CYazirusi(X座標,Y座標,幅,高さ,テクスチャのポインタ)
	CYue(float x, float y, float w, float h, CTexture* pt);
	CYue();
	void Update();
};