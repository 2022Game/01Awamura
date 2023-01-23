#pragma once
#include "CCharacter.h"
#include "CSound.h"

#define KABE "111.png"//壁

class CZkah : public CCharacter
{
private:
public:
	CSound mSound;
	//衝突処理２
	void Collision();
	//衝突処理４
	void Collision(CCharacter* m, CCharacter* o);
	//CZkah(X座標,Y座標,幅,高さ,画像右,画像左,画像下,画像上,テクスチャのポインタ)
	CZkah(float x, float y, float w, float h,CTexture* pt);
	void Update();
};