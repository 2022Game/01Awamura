#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CFloor.h"

class CFloorGimmick : public CTask
{
private:
	std::vector<CFloor*> mFloor;	// �N���A�y��̃��X�g
	CModel* mpFloorModel;			// �N���A�y��̃��f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateFloor(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpFloor;


public:
	CFloorGimmick();
	~CFloorGimmick();

	// �X�V����
	void Update();
};