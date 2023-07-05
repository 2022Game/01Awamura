#ifndef CASOCCERGIMMICK_H
#define CASOCCERGIMMICK_H
#include "CTask.h"
#include "CASoccer.h"

class CASoccerGimmick : public CTask
{
private:
	std::vector<CASoccer*> mSoccers;	// �n�}�[�̃��X�g
	CModel* mpSoccerModel;			// �n�}�[�̃��f���f�[�^
	int randnow;
	int randnow2;
	int randnow3;
	int randnow4;
	int randnow5;
	int randnow6;
	int randnow7;
	int randnow8;
	int randnow9;
	int randnow10;

	// ����������
	void Init();
	// �n�}�[�𐶐����ă��X�g�ɒǉ�
	void CreateSoccer(CVector& pos, CVector& rot, CVector& scale);

public:
	CASoccerGimmick();
	~CASoccerGimmick();

	// �X�V����
	void Update();
};

#endif