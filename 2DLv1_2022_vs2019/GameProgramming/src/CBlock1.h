#pragma once
#include "CCharacter.h"
/*
* CBlock1
* �u���b�N�N���X
* �}�b�v�̃u���b�N�Ɏg�p����
*/
class CBlock1 : public CCharacter
{
public:
	//CBlock1(X���W,Y���W,��,����,�e�N�X�`���̃|�C���^)
	CBlock1(float x, float y, float w, float h, CTexture* pt);
	//Update�ł͉������Ȃ�
	void Update() {}
};