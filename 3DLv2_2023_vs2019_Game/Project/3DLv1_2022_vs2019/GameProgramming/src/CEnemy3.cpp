#include "CEnemy3.h"
#include "CEffect.h"
#include "CCollisionManager.h"
#include "CPlayer.h"

#define OBJ "res\\Beard_man.obj" //���f���̃t�@�C��
#define MTL "res\\Beard_man.mtl" //���f���̃}�e���A���t�@�C��
#define HP 3 //�ϋv�l
#define VELOCITY 0.11f //���x

CModel CEnemy3::sModel; //���f���f�[�^�쐬

//�f�t�H���g�R���X�g���N�^
CEnemy3::CEnemy3()
	:CCharacter3(1)
	,mCollider(this,&Matrix(),CVector(0.0f,0.0f,0.0f),0.4f)
	, mHp(HP)
{
	//���f�����Ȃ��Ƃ��͓ǂ݂���
	if (sModel.Triangles().size() == 0)
	{
		sModel.Load(OBJ, MTL);
	}
	//���f���̃|�C���^�ݒ�
	mpModel = &sModel;
}

//�R���X�g���N�^
//CEnemy(�ʒu�A��]�A�g�k�j
CEnemy3::CEnemy3(const CVector& position, const CVector& rotation,
	const CVector& scale)
	:CEnemy3() //�f�t�H���g�R���X�g���N�^�����s����
{
	//�ʒu�A��]�A�g�U��ݒ肷��
	Position(position); //�ʒu�̐ݒ�
	Rotation(rotation); //��]�̐ݒ�
	Scale(scale); //�g�k�̐ݒ�
	CTransform::Update(); //�s��̍X�V
	//�ڕW�n�_�̐ݒ�
	mPoint = Position() + CVector(0.0f, 0.0f, 100.0f) * MatrixRotate();
	////�ڕW�n�_�̐ݒ�
	//mPoint = mPosition + CVector(0.0f, 0.0f, 100.0f) * mMatrixRotate;
}

//�X�V����
void CEnemy3::Update()
{
	CTransform::Update();
	//�v���C���[�̃|�C���^���O�ȊO�̎�
	CPlayer* player = CPlayer::Instance();
	//HP���O�ȉ��̎��@���j
	if (mHp <= 0)
	{
		mHp--;
		//�P�T�t���[�����ɃG�t�F�N�g
		if (mHp % 15 == 0)
		{
			//�G�t�F�N�g����
			new CEffect(Position(), 1.0f, 1.0f, "exp.tga", 4, 4, 2);
		}
		//���~������.
		Position(Position() - CVector(0.0f, 0.03f, 0.0f));
		CTransform::Update();
		return;
	}
	if (player != nullptr)
	{
		//�v���C���[�܂ł̃x�N�g�������߂�
		CVector vp = player->Position() - Position();
		//���x�N�g���Ƃ̓��ς����߂�
		float dx = vp.Dot(MatrixRotate().VectorX());
		//��x�N�g���Ƃ̓��ς����߂�
		float dy = vp.Dot(MatrixRotate().VectorY());
		float dz = vp.Dot(MatrixRotate().VectorZ());

		//X���̃Y����2.0�ȉ�
		if (-2.0f < dx && dx < 2.0f)
		{
			if (-2.0f < dy && dy < 2.0f)
			{
				if (30.0f > dz && dz >= 0.0f)
				{
					//�e�𔭎˂��܂�
					/*CBullet* bullet = new CBullet();
					bullet->Set(0.1f, 1.5f);
					bullet->Position(
						CVector(0.0f, 0.0f, 10.0f) * mMatrix);
					bullet->Rotation(mRotation);
					bullet->Update();*/
				}
			}
		}
	}
	//�ڕW�n�_�܂ł̃x�N�g�������߂�
	CVector vp = mPoint - Position();
	//�ۑ�
	//���x�N�g���Ƃ̓��ς����߂�
	float dx = vp.Dot(MatrixRotate().VectorX());
	//��x�N�g���Ƃ̓��ς����߂�
	float dy = vp.Dot(MatrixRotate().VectorY());
	const float margin = 0.1f;
	//���E�����։�]
	if (dx > margin)
	{
		Rotation(Rotation() + CVector(0.0f, 1.0f, 0.0f));//���։�]
	}
	else if (dx < -margin)
	{
		//�ۑ�
		Rotation(Rotation() - CVector(0.0f, 1.0f, 0.0f));//�E�։�]
	}
	//�㉺�����։�]
	if (dy > margin)
	{
		Rotation(Rotation() + CVector(-1.0f, 0.0f, 0.0f));//��։�]
	}
	else if (dy < -margin)
	{
		//�ۑ�
		Rotation(Rotation() - CVector(-1.0f, 0.0f, 0.0f));//���։�]
	}
	//�@�̑O���ֈړ�����
	Position(Position() + MatrixRotate().VectorZ() * VELOCITY);
	CTransform::Update(); //�s��X�V
	///���悻3�b��ɖڕW�n�_���X�V
	int r = rand() % 180; //rand()�͐����̗�����Ԃ�
	//%180�͂P�W�O�Ŋ������]������߂�
	if (r == 0)
	{
		if (player != nullptr)
		{
			mPoint = player->Position();
		}
		else
		{
			mPoint = mPoint * CMatrix().RotateY(45);
		}
	}
}

//�X�V����
//Collision(�R���C�_1�A�R���C�_�Q�j
void CEnemy3::Collision(CCollider* m, CCollider* o)
{
	switch (o->Type())
	{
	case CCollider::EType::ESPHERE://���R���C�_�̎�
		//�R���C�_��m��y���Փ˂��Ă��邩����
		if (CCollider::Collision(m, o)) {
			//�G�t�F�N�g����
			new CEffect(o->Parent()->Position(), 1.0f, 1.0f, "exp.tga", 4, 4, 2);
			//�Փ˂��Ă��鎞�͖����ɂ���
			//mEnabled = false;
			mHp--;
		}
		break;
	case CCollider::EType::ETRIANGLE:
		CVector adjust;
		if (CCollider::CollisionTriangleSphere(o, m, &adjust) && mHp <= 0)
		{
			mEnabled = false;
		}
		break;
	}
}

void CEnemy3::Collision()
{
	mCollider.ChangePriority();
	//�Փˏ��������s
	CCollisionManager::Instance()->Collision(&mCollider, COLLISIONRANGE);
}
