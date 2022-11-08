#pragma once
#include "CCharacter.h"

#define KABE "111.png"//壁

class CZkau : public CCharacter
{
private:
public:
	//衝突処理2
	void Collision();
	//衝突処理4
	void Collision(CCharacter* m, CCharacter* o);
	//CZkau(X座標,Y座標,幅,高さ,画像右,画像左,画像下,画像上,テクスチャのポインタ)
	CZkau(float x, float y, float w, float h,  CTexture* pt);
	void Update();
};