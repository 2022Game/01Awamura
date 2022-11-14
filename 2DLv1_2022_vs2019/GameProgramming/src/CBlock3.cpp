#include "CBlock3.h"

#define TEXCOORD 60.0f, 85.0f, 240.0f, 200.0f //テクスチャ座標

CBlock3::CBlock3(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, TEXCOORD);
	mTag = ETag::EBLOCK3;
}