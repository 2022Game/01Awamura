#ifndef CENEMY_H
#define CENEMY_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"
//�R���R���̃C���N���[�h
#include "CCollider.h"
/*
�G�l�~�[�N���X
�L�����N�^�N���X���p��
*/
class CEnemy : public CCharacter3 {
private:
	//�R���C�_
	CCollider mCollider1;
	CCollider mCollider2;
	CCollider mCollider3;
public:
	//�Փˏ���
	//Collision(�R���C�_�P�A�R���C�_�Q�j
	void Collision(CCollider* m, CCollider* o);
	void Collision();
	//�R���X�g���N�^
	//CEnemy(���f��,�ʒu,��],�g�k�j
	CEnemy(CModel* model, const CVector& position,
		const CVector& rotation, const CVector& scale);
	//�X�V����
	void Update();
	//�m�F�p �폜�\��
	//void CEnemy::Render() {
		//CCharacter3::Render();
		//mCollider1.Render();
		//mCollider2.Render();
		//mCollider3.Render();
	//}
};
#endif