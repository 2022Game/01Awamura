#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CWarp.h"

class CWarpGimmick : public CTask
{
private:
	std::vector<CWarp*> mWarp;	// �N���A�y��̃��X�g
	CModel* mpWarpModel;			// �N���A�y��̃��f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateWarp(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpWarp;


public:
	CWarpGimmick();
	~CWarpGimmick();

	// �X�V����
	void Update();
};