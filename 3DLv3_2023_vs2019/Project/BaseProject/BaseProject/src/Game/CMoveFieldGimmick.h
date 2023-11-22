#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CMoveField.h"

class CMoveFieldGimmick : public CTask
{
private:
	std::vector<CMoveField*> mMoveField;	// �N���A�y��̃��X�g
	CModel* mpMoveTenModel;			// �\���̃��f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateMoveField(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpMoveField;


public:
	CMoveFieldGimmick();
	~CMoveFieldGimmick();

	// �X�V����
	void Update();
};