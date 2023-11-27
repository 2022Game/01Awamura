#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CJMoveField.h"

class CJMoveFieldGimmick : public CTask
{
private:
	std::vector<CJMoveField*> mJMoveField;	// �N���A�y��̃��X�g
	CModel* mpMoveJModel; //T�����f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateJMoveField(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpJMoveField;


public:
	CJMoveFieldGimmick();
	~CJMoveFieldGimmick();

	// �X�V����
	void Update();
};