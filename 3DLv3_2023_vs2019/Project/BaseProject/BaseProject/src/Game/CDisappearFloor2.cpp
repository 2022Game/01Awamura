#include "CDisappearFloor2.h"
#include "Maths.h"

//������̂ɂ����鎞��
#define FADE_TIME 5.0f
//��������̑ҋ@����
#define WAIT_TIME 2.0f

//�R���X�g���N�^
CDisappearFloor2::CDisappearFloor2(const CVector& pos, const CVector& scale,
	ETag reactionTag, ELayer reactionLayer)
	:CRideableObject(ETaskPriority::eTransparent)
	, mState(EState::Idle)
	, mStateStep(0)
	, mReactionTag(reactionTag)
	, mReactionLayer(reactionLayer)
	, mFadeTime(0.0f)
	, mWaitTime(0.0f)
{
	//���̃��f�����擾
	mpModel = CResourceManager::Get<CModel>("FieldCube");

	//�����鏰�̃R���C�_�[�쐬
	mpColliderMesh = new CColliderMesh(this, ELayer::eObject, mpModel, true);
	//�v���C���[�͏�ɏ��̂ŕK�{�œ����蔻���L���ɂ���
	mpColliderMesh->SetCollisionLayers({ ELayer::ePlayer });
	mpColliderMesh->SetCollisionTags({ ETag::ePlayer });
	//�������ɐݒ肳�ꂽ�G�ꂽ�Ƃ��ɔ�������I�u�W�F�N�g�^�O��
	//�R���C�_�[�̃��C���[���ʂɐݒ�
	mpColliderMesh->SetCollisionLayer(mReactionLayer, true);
	mpColliderMesh->SetCollisionTag(mReactionTag, true);

	Position(pos);
	Scale(scale);

	SetColor(CColor(1.0f, 0.0f, 1.0f, 1.0f));
}

//�f�X�g���N�^
CDisappearFloor2::~CDisappearFloor2()
{
	SAFE_DELETE(mpColliderMesh);
}

//�Փˏ���
void CDisappearFloor2::Collision(CCollider* self, CCollider* other, const CHitInfo& hit)
{
	CObjectBase* owner = other->Owner();
	if (owner == nullptr)return;

	//�Փ˂��Ă���̂��A��������I�u�W�F�N�g�ł����
	if (owner->Tag() == mReactionTag && other->Layer() == mReactionLayer)
	{
		//���݂��ҋ@��Ԃł���΁A�t�F�[�h��Ԃ֐؂�ւ���
		if (mState == EState::Idle)
		{
			ChangeState(EState::Fade);
		}
	}
}

//��Ԃ�؂�ւ���
void CDisappearFloor2::ChangeState(EState state)
{
	mState = state;
	mStateStep = 0;
}

//�ҋ@��Ԃ̍X�V����
void CDisappearFloor2::UpdateIdle()
{

}

//�t�F�[�h���̍X�V����
void CDisappearFloor2::UpdateFade()
{
	//�t�F�[�h���Ԃ��o���Ă��Ȃ�
	if (mFadeTime < FADE_TIME)
	{
		//�o�ߎ��Ԃ����Z
		mFadeTime += Time::DeltaTime();
	}
	//�t�F�[�h���Ԃ��o�߂���
	else
	{
		//�t�F�[�h��̑ҋ@���Ԃ֕��A
		ChangeState(EState::Wait);
		mFadeTime = FADE_TIME;
		mWaitTime = WAIT_TIME;

		//���S�ɏ������^�C�~���O��
		//�R���C�_�[���I�t�ɂ��āA���Ȃ��悤�ɂ���
		mpColliderMesh->SetEnable(false);
	}
}

//�t�F�[�h��̑ҋ@����
void CDisappearFloor2::UpdateWait()
{
	//�X�e�b�v���Ƃɏ�����؂�ւ�
	switch (mStateStep)
	{
		//�X�e�b�v�O �t�F�[�h�̌�̑ҋ@����
	case 0:
		//�҂����Ԃ��o�߂��Ă��Ȃ���΁A�o�ߎ��ԕ����炷
		if (mWaitTime > 0.0f)
		{
			mWaitTime -= Time::DeltaTime();
		}
		else
		{
			mStateStep++;
		}
		break;
		//�X�e�b�v�P�ŏ������������ɖ߂�
	case 1:
		if (mFadeTime > 0.0f)
		{
			mFadeTime -= 10 * Time::DeltaTime();
		}
		else
		{
			//�ҋ@��Ԃ֖߂�
			ChangeState(EState::Idle);
			mFadeTime = 0.0f;
			mWaitTime = 0.0f;

			//���̏�Ԃɖ߂����^�C�~���O��
			//�R���C�_�[���I���ɂ��ď���悤�ɂ���
			mpColliderMesh->SetEnable(true);
		}
		break;
	}
}

//�X�V
void CDisappearFloor2::Update()
{
	//���݂̏�Ԃɍ��킹�ď�����؂�ւ�
	switch (mState)
	{
		//�ҋ@���
	case EState::Idle:
		UpdateIdle();
		break;
		//�t�F�[�h��
	case EState::Fade:
		UpdateFade();
		break;
		//�t�F�[�h��̑ҋ@
	case EState::Wait:
		UpdateWait();
		break;
	}
	//�t�F�[�h���Ԃɍ��킹�ď��̃A���t�@�l�����߂ăA���t�@�l��ݒ�
	float alpha = 1.0f - Math::Clamp01(mFadeTime / FADE_TIME);
	SetAlpha(alpha);
}

//�`��
void CDisappearFloor2::Render()
{
	mpModel->SetColor(mColor);
	mpModel->Render(Matrix());
}