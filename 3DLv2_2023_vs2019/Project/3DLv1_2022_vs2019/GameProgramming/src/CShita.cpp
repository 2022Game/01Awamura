#include "CShita.h"
#include "CApplication.h"

#define SHITA 0.0f,175.0f, 190.0f, 0.0f //�e�N�X�`�����W

CShita::CShita(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, SHITA);
}