#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CSlope.h"

class CSlopeGimmick : public CTask
{
private:
	std::vector<CSlope*> mSlope;	// �N���A�y��̃��X�g
	CModel* mpSlopeModel;			// �N���A�y��̃��f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateSlope(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpSlope;


public:
	CSlopeGimmick();
	~CSlopeGimmick();

	// �X�V����
	void Update();
};