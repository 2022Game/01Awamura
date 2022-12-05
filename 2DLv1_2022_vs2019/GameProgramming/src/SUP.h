#pragma once
#include "CCharacter.h"

class SUP : public CCharacter
{
private:
public:
	//衝突処理２
	void Collision();
	//衝突処理４
	void Collision(CCharacter* m, CCharacter* o);
	//CZkah(X座標,Y座標,幅,高さ,画像右,画像左,画像下,画像上,テクスチャのポインタ)
	SUP(float x, float y, float w, float h, CTexture* pt);
	void Update();
};