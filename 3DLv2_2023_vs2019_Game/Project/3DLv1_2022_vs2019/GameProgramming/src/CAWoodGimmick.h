#ifndef CAWOODGIMMICK_H
#define CAWOODGIMMICK_H
#include "CTask.h"
#include "CACoin.h"
#include "CAWood.h"

class CAWoodGimmick : public CTask
{
private:
	std::vector<CAWood*> mWoods;	// �؂̃��X�g
	CModel* mpWoodModel;			// �؂̃��f���f�[�^

	// ����������
	void Init();
	// �n�}�[�𐶐����ă��X�g�ɒǉ�
	void CreateWood(CVector& pos, CVector& rot, CVector& scale);

public:
	CAWoodGimmick();
	~CAWoodGimmick();

	// �X�V����
	void Update();
};

#endif