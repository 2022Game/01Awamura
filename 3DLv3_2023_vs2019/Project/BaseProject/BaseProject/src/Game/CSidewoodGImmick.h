#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CSidewood.h"

class CSidewoodGimmick : public CTask
{
private:
	std::vector<CSidewood*> mSidewood;	// �N���A�y��̃��X�g
	CModel* mpSidewoodModel;			// �N���A�y��̃��f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateSidewood(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpSidewood;

	int randpos;


public:
	CSidewoodGimmick();
	~CSidewoodGimmick();

	// �X�V����
	void Update();
};