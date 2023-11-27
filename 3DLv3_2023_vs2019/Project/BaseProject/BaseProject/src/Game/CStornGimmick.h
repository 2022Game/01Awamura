#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CStorn.h"

class CStornGimmick : public CTask
{
private:
	std::vector<CStorn*> mStorn;	// �N���A�y��̃��X�g
	CModel* mpStornModel;			// �N���A�y��̃��f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateStorn(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpStorn;


public:
	CStornGimmick();
	~CStornGimmick();

	// �X�V����
	void Update();
};