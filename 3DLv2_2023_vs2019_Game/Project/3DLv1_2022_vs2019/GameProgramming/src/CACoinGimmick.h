#ifndef CACOINGIMMICK_H
#define CACOINGIMMICK_H
#include "CTask.h"
#include "CACoin.h"
#include "CCharacter.h"

class CACoinGimmick : public CTask ,public CCharacter
{
private:
	std::vector<CACoin*> mCoins;	// �R�C���̃��X�g
	CModel* mpCoinModel;			// �R�C���̃��f���f�[�^
	int randnow;
	int randnow2;
	int randnow3;
	int randnow4;
	int randnow5;
	int randnow6;

	// ����������
	void Init();
	// �R�C���𐶐����ă��X�g�ɒǉ�
	void CreateCoin(CVector& pos, CVector& rot, CVector& scale);

public:
	CACoinGimmick();
	~CACoinGimmick();

	// �X�V����
	void Update();
};

#endif