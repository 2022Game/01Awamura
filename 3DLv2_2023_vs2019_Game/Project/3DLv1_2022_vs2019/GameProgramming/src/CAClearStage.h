#ifndef CACLEARSTAGE_H
#define CACLEARSTAGE_H
#include "CTask.h"
#include "CACoinClearStage.h"
#include "CCollider.h"
#include "CColliderMesh.h"
#include "CColliderTriangle.h"
#include "CColliderLine.h"

class CAClearStage : public CTask
{
private:
	std::vector<CACoinClearStage*> mClearStages;	// �R�C���̃��X�g
	CModel* mpCoinModel;			// �R�C���̃��f���f�[�^

	// ����������
	void Init();
	// �R�C���𐶐����ă��X�g�ɒǉ�
	void ClearStage(CVector& pos, CVector& rot, CVector& scale);
	//�R���C�_
	CCollider mCollider1;
	CCollider mCollider2;
	CCollider mCollider3;
	CColliderMesh mColliderMesh1;
	CColliderMesh mColliderMesh;

public:
	CAClearStage();
	~CAClearStage();
	//�Փˏ���
	//Collision(�R���C�_�P�A�R���C�_�Q�j
	void Collision(CCollider* m, CCollider* o);
	void Collision();

	// �X�V����
	void Update();
};

#endif