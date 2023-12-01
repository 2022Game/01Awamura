#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CStone.h"

class CStoneGimmick : public CTask
{
private:
	std::vector<CStone*> mStone;	// �N���A�y��̃��X�g
	CModel* mpStoneModel;			// �N���A�y��̃��f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateStone(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpStone;

	int randpos;


public:
	CStoneGimmick();
	~CStoneGimmick();

	// �X�V����
	void Update();
};