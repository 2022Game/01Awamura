#pragma once
#include "CCharacter.h"
/*
* CBlock
* �u���b�N�N���X
* �}�b�v�̃u���b�N�Ɏg�p����
*/
class CBlockk : public CCharacter
{
public:
	//CBlock(X���W,Y���W,��,����,�e�N�X�`���̃|�C���^)
	CBlockk(float x, float y, float w, float h, CTexture* pt);
	//Update�ł͉������Ȃ�
	void Update() {}
};