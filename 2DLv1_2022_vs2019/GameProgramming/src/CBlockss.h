#pragma once
#include "CCharacter.h"

class CBlockss : public CCharacter
{
public:
	//衝突処理2
	void Collision();
	//衝突処理4
	void Collision(CCharacter* m, CCharacter* o);
	//CBlocks(X座標,Y座標,幅,高さ,テクスチャのポインタ)
	CBlockss(float x, float y, float w, float h, CTexture* pt);
	//Updateでは何もしない
	void Update();
};