#pragma once
#include "CCharacter.h"
/*
* CBlock1
* ブロッククラス
* マップのブロックに使用する
*/
class CBlock1 : public CCharacter
{
public:
	//CBlock1(X座標,Y座標,幅,高さ,テクスチャのポインタ)
	CBlock1(float x, float y, float w, float h, CTexture* pt);
	//Updateでは何もしない
	void Update() {}
};