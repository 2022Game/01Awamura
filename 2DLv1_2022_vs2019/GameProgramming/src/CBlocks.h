#pragma once
#include "CCharacter.h"

class CBlocks : public CCharacter
{
public:
	//�Փˏ���2
	void Collision();
	//�Փˏ���4
	void Collision(CCharacter* m, CCharacter* o);
	//CBlocks(X���W,Y���W,��,����,�e�N�X�`���̃|�C���^)
	CBlocks(float x, float y, float w, float h, CTexture* pt);
	//Update�ł͉������Ȃ�
	void Update();
};