#pragma once
#include "CTask.h"
#include "CAxe.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CAxeGimmick : public CTask
{
private:
	std::vector<CAxe*> mAxe;	// �N���A�y��̃��X�g
	CModel* mpAxe;			// �N���A�y��̃��f���f�[�^

	// ����������
	void Init();
	// ���𐶐����ă��X�g�ɒǉ�
	void CreateAxe(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpAxeModel;
	CColliderMesh* mpColliderMesh;

public:
	CAxeGimmick();
	~CAxeGimmick();

	// �X�V����
	void Update();
};