#pragma once
#include "CCharacter.h"
#include "CUi.h"

#define MU "111.png"//壁

class CZkabe : public CCharacter
{
private:
	
public:
	static int sNow;
	static int Now();
	//衝突処理2
	void Collision();
	//衝突処理4
	void Collision(CCharacter* m, CCharacter* o);
	//CZkau1(X座標,Y座標,幅,高さ,画像右,画像左,画像下,画像上,テクスチャのポインタ)
	CZkabe(float x, float y, float w, float h, float l, float r, float b, float t, CTexture* pt);
	void Update();
};