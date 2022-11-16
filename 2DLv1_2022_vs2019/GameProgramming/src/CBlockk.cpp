#include "CBlockk.h"

#define TEXCOORD 0.0f, 48.0f, 128.0f, 80.0f //�e�N�X�`�����W

CBlockk::CBlockk(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, TEXCOORD);
	mTag = ETag::EBLOCKK;
}