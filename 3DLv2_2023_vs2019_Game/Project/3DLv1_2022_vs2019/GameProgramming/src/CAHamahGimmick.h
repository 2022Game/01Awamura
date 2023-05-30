#ifndef CAHAMAHGIMMICK_H
#define CAHAMAHGIMMICK_H
#include "CTask.h"
#include "CACoin.h"
#include "CAHamah.h"

class CAHamahGimmick : public CTask
{
private:
	std::vector<CAHamah*> mHamahs;	// �R�C���̃��X�g
	CModel* mpHamahModel;			// �R�C���̃��f���f�[�^

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