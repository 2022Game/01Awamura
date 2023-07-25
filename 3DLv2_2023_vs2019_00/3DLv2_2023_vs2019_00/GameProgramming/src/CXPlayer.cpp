#include "CXPlayer.h"
#include "CCharacter3.h"
#include "CActionCamera.h"

#define ROTATION2_YV CVector(0.0f, 2.0f, 0.0f) //��]���x
#define VELOCITY2 CVector(0.0f, 0.0f, 0.1f) //�ړ����x

//�R���C�_�̏�����
CXPlayer::CXPlayer()
	:mColSphereBody(this, nullptr, CVector(), 0.5f, CCollider::ETag::EBODY)
	,mColSphereHead(this,nullptr,CVector(0.0f,5.0f,-3.0f),0.5f)
	,mColSphereSword(this,nullptr,CVector(-10.0f,10.0f,50.0f),0.3f, CCollider::ETag::ESWORD)
	, AttackFrame(0)
	, AnimaScene(0)
{
	//�^�O�Ƀv���C���[��ݒ肵�܂�
	mTag = EPLAYER;
}

void CXPlayer::Init(CModelX* model)
{
	CXCharacter::Init(model);
	//�����s��̐ݒ�
	mColSphereBody.Matrix(&mpCombinedMatrix[9]);
	//��
	mColSphereHead.Matrix(&mpCombinedMatrix[12]);
	//��
	mColSphereSword.Matrix(&mpCombinedMatrix[22]);
}

void CXPlayer::Update()
{
	if (AttackFrame != 0)
	{
		AttackFrame--;
	}
	if (mInput.Key(VK_SPACE))
	{
		if (AnimaScene != 4 && AnimaScene != 3)
		{
			ChangeAnimation(AnimaScene = 3, false, AttackFrame = 30);
		}
	}
	if (AnimaScene == 3 && AttackFrame <= 0)
	{
		ChangeAnimation(AnimaScene = 4, false, AttackFrame = 30);
	}
	if (AnimaScene == 4 && AttackFrame <= 0)
	{
		ChangeAnimation(AnimaScene = 0, true, 60);
	}

	//if (mInput.Key('A'))
	//{
	//	//Y���̉�]�l������
	//	mRotation = mRotation + ROTATION2_YV;
	//}
	//if (mInput.Key('D'))
	//{
	//	//Y���̉�]�l������
	//	mRotation = mRotation - ROTATION2_YV;
	//}
	//�J�����̑O��
	CVector cameraZ = CActionCamera::Instance()->VectorZ();
	//�J�����̍�����
	CVector cameraX = CActionCamera::Instance()->VectorX();
	//�L�����N�^�̑O��
	CVector charZ = mMatrixRotate.VectorZ();
	//XZ���ʂɂ��Đ��K��
	cameraZ.Y(0.0f); cameraZ = cameraZ.Normalize();
	cameraX.Y(0.0f); cameraX = cameraX.Normalize();
	charZ.Y(0.0f); charZ = charZ.Normalize();
	//�ړ������̐ݒ�
	CVector move;
	if (mInput.Key('A')) {
		move = move + cameraX;
	}
	if (mInput.Key('D')) {
		move = move - cameraX;
	}
	if (mInput.Key('W')) {
		move = move + cameraZ;
	}
	if (mInput.Key('S')) {
		move = move - cameraZ;
	}
	//�ړ�����
	if (move.Length() > 0.0f)
	{
		//�V��
		const float MARGIN = 0.06f;
		//���K��
		move = move.Normalize();
		//�����̌����ƌ��������������ŊO��
		float cross = charZ.Cross(move).Y();
		//�����̌����ƌ��������������œ���
		float dot = charZ.Dot(move);
		//�O�ς��v���X�͍���]
		if (cross > MARGIN) {
			mRotation.Y(mRotation.Y() + 5.0f);
		}
		//�O�ς��}�C�i�X�͉E��]
		else if (cross < -MARGIN) {
			mRotation.Y(mRotation.Y() - 5.0f);
		}
		//�O��̌����������Ƃ����ς͂P�D�O
		else if (dot < 1.0f - MARGIN) {
			mRotation.Y(mRotation.Y() - 5.0f);
		}
		//�ړ������ֈړ�
		//mPosition = mPosition + move * 0.1f;
		//ChangeAnimation(1, true, 60);
	}
	if (mInput.Key('W')|| mInput.Key('A')||mInput.Key('S')||mInput.Key('D'))
	{
		if(AnimaScene != 4 && AnimaScene != 3)
		{
			ChangeAnimation(AnimaScene = 1, true, 60);
			mPosition = mPosition + VELOCITY2 * mMatrixRotate;
		}
	}
	else if(AnimaScene == 1)
	{
		ChangeAnimation(0, true, 60);
	}
	CXCharacter::Update();
}

void CXPlayer::Collision(CCollider* m, CCollider* o) {
	
}