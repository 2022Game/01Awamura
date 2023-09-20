#ifndef CAWALLGIMMICK_H
#define CAWALLGIMMICK_H
#include "CTask.h"
//#include "CACoin.h"
#include "CAWall.h"

class CAWallGimmick : public CTask
{
private:
	std::vector<CAWall*> mWalls;	// �R�C���̃��X�g
	CModel* mpWallModel;			// �R�C���̃��f���f�[�^

	// ����������
	void Init();
	// �n�}�[�𐶐����ă��X�g�ɒǉ�
	void CreateWall(CVector& pos, CVector& rot, CVector& scale);

public:
	CAWallGimmick();
	~CAWallGimmick();

	// �X�V����
	void Update();
};

#endif