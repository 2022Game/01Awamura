//#include "CACoin.h"
//
//#include "CTaskManager.h"
//#include "CApplication.h"
//#include "CCollisionManager.h"
//
//#define ROTATION_YV CVector(0.0f,1.0f,0.0f) //��]���x
//#define VELOCITY CVector(0.0f,0.0f,0.05f) //�ړ����x
//#define VELOCITY1 CVector(0.0f,0.2f,0.0f) //�ړ����x
//#define VELOCITY2 CVector(0.0f,0.05f,0.0f) //�ړ����x
//#define VELOCITY3 CVector(0.0f,0.2f,0.0f) //�ړ���
//#define ROTATION_XV CVector(1.0f,0.0f,0.0f) //��]���x
//
////CPlayer(�ʒu�A��]�A�X�P�[���j
//CACoin::CACoin(const CVector& pos, const CVector& rot, const CVector& scale)
//	: jc(0)
//	, n(0)
//{
//	CTransform::Update(pos, rot, scale);//�s��̍X�V
//}
//
//CACoin::CACoin()
//	/*: mLine(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 2.0f, 0.0f))
//	, mLine2(this, &mMatrix, CVector(-0.5f, 1.2f, 0.0f), CVector(0.5f, 1.2f, 0.0f))
//	, mLine3(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f))*/
//{
//	//�C���X�^���X�̐ݒ�
//	spInstance = this;
//}
//
////�X�V����
//void CACoin::Update() {
//	//�ϊ��s��̍X�V
//	CTransform::Update();
//	//Ui�ݒ�
//	CApplication::Ui()->PosY(mPosition.Y());
//	CApplication::Ui()->RotX(mRotation.X());
//	CApplication::Ui()->RotY(mRotation.Y());
//	mPosition = mPosition + VELOCITY;
//}
//
//void CACoin::Collision(CCollider* m, CCollider* o) {
//	//���g�̃R���C�_�^�C�v�̔���
//	switch (m->Type()) {
//	case CCollider::ETRIANGLE://�����R���C�_
//		//����̃R���C�_���O�p�R���C�_�̎�
//		if (o->Type() == CCollider::ELINE) {
//			CVector adjust;//�����p�x�N�g��
//			//�O�p�`�Ɛ����̏Փ˔���
//			if (CCollider::CollisionTriangleLine(o, m, &adjust))
//			{
//				//�ʒu�̍X�V(mPosition + adjust)
//				mPosition = mPosition + adjust;
//				//�s��̍X�V
//				CTransform::Update();
//			}
//		}
//		break;
//	}
//}
//
////�Փˏ���
//void CACoin::Collision()
//{
//	//�R���C�_�̗D��x�ύX
//	mLine.ChangePriority();
//	mLine2.ChangePriority();
//	mLine3.ChangePriority();
//	//�Փˏ��������s
//	CCollisionManager::Instance()->Collision(&mLine, COLLISIONRANGE);
//	CCollisionManager::Instance()->Collision(&mLine2, COLLISIONRANGE);
//	CCollisionManager::Instance()->Collision(&mLine3, COLLISIONRANGE);
//}
//
//CACoin* CACoin::spInstance = nullptr;
//
//CACoin* CACoin::Instance()
//{
//	return spInstance;
//}

#include "CACoin.h"
#include "CCollisionManager.h"
#include "CEffect.h"

//�ړ����x
#define VELOCITY CVector(0.0f,0.0f,0.0f)

//�R���X�g���N�^
//CEnemy(���f���A�ʒu�A��]�A�g�k�j
CACoin::CACoin(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
{
	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model; //���f���̐ݒ�
	mPosition = position; //�ʒu�̐ݒ�
	mRotation = rotation; //��]�̐ݒ�
	mScale = scale; //�g�k�̐ݒ�
	mColliderMesh.Set(nullptr, nullptr, mpModel,mPosition);
}

//�X�V����
void CACoin::Update() {
	//�s����X�V
	CTransform::Update();
	//�ʒu���ړ�
	mPosition = mPosition + VELOCITY * mMatrixRotate;
}

//�Փˏ���
//CCollision(�R���C�_�P�A�R���C�_�Q�j
void CACoin::Collision(CCollider* m, CCollider* o) {
	//����̃R���C�_�^�C�v�̔���
	switch (o->Type())
	{
	case CCollider::ESPHERE://���R���C�_�̎�
		//�R���C�_��m��y���Փ˂��Ă��邩����
		if (CCollider::Collision(m, o)) {
			//�G�t�F�N�g����
			//new CEffect(o->Parent()->Position(), 1.0f, 1.0f, "exp.tga", 4, 4, 2);
			//�Փ˂��Ă��鎞�͖����ɂ���
			//mEnabled = false;
		}
		break;
	case CCollider::ELINE://�O�p�R���C�_�̎�
		CVector adjust;//�����l
		if (CCollider::CollisionTriangleSphere(o, m, &adjust))
		{
			//�Փ˂��Ȃ��ʒu�܂Ŗ߂�
			mPosition = mPosition + adjust;
		}
		break;
	}
	////�R���C�_��m��o���Փ˂��Ă��邩����
	//if (CCollider::Collision(m, o)) {
	//	//�G�t�F�N�g����
	//	new CEffect(o->Parent()->Position(), 1.0f, 1.0f, "exp.tga", 4, 4, 2);
	//	//�Փ˂��Ă���Ƃ��͖����ɂ���
	////	mEnabled = false;
	//}
}

void CACoin::Collision()
{
	//�R���C�_�̗D��x�ύX
	mCollider1.ChangePriority();
	mCollider2.ChangePriority();
	mCollider3.ChangePriority();
	//�Փˏ��������s
	CCollisionManager::Instance()->Collision(&mCollider1, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mCollider2, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mCollider3, COLLISIONRANGE);
}