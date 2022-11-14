#include "CBlock4.h"

#define TEXCOORD 60.0f, 85.0f, 240.0f, 200.0f //�e�N�X�`�����W

CBlock4::CBlock4(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, TEXCOORD);
	mTag = ETag::EBLOCK4;
}