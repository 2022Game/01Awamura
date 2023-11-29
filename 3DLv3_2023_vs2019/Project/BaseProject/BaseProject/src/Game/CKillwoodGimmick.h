#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CKillwood.h"

class CKillwoodGimmick : public CTask
{
private:
	std::vector<CKillwood*> mKillwood;	// �N���A�y��̃��X�g
	CModel* mpKillwoodModel;			// �N���A�y��̃��f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateKillwood(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpKillwood;

	int randpos;


public:
	CKillwoodGimmick();
	~CKillwoodGimmick();

	// �X�V����
	void Update();
};