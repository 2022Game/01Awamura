#ifndef CAHAMAHGIMMICK_H
#define CAHAMAHGIMMICK_H
#include "CTask.h"
#include "CAHamah.h"

#define MODEL_FHAMAH "res\\apple2.obj","res\\apple2.mtl"

class CAHamahGimmick : public CTask
{
private:
	std::vector<CAHamah*> mHamahs;	// �n�}�[�̃��X�g
	CModel* mpHamahModel;			// �n�}�[�̃��f���f�[�^
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
	void CreateHamah(CVector& pos, CVector& rot, CVector& scale);

public:
	CAHamahGimmick();
	~CAHamahGimmick();

	// �X�V����
	void Update();
};

#endif