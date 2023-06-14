#ifndef CAHAMAHGIMMICK_H
#define CAHAMAHGIMMICK_H
#include "CTask.h"
#include "CACoin.h"
#include "CAHamah.h"

class CAHamahGimmick : public CTask
{
private:
	std::vector<CAHamah*> mHamahs;	// �n�}�[�̃��X�g
	CModel* mpHamahModel;			// �n�}�[�̃��f���f�[�^

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