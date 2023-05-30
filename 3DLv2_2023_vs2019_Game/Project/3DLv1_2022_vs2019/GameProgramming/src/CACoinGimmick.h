#ifndef CACOINGIMMICK_H
#define CACOINGIMMICK_H
#include "CTask.h"
#include "CACoin.h"
#include "CAHamah.h"

class CACoinGimmick : public CTask
{
private:
	std::vector<CACoin*> mCoins;	// �R�C���̃��X�g
	CModel* mpCoinModel;			// �R�C���̃��f���f�[�^

	// ����������
	void Init();
	// �R�C���𐶐����ă��X�g�ɒǉ�
	void CreateCoin(CVector& pos, CVector& rot, CVector& scale);
	void CreateCoinEnd(CVector& pos, CVector& rot, CVector& scale);

public:
	CACoinGimmick();
	~CACoinGimmick();

	// �X�V����
	void Update();
};

#endif