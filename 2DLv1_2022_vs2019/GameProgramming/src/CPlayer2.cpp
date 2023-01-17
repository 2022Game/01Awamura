#include "CPlayer2.h"
#include "CApplication.h"

#define MARU 0,525,1000,465 //��
#define MARU1 470,1000,530,0 //��
#define pengin 37,60,30,2
#define TEXCOORD 168, 188, 158, 128	//�e�N�X�`���}�b�s���O
#define TEXCRY 196, 216, 158, 128	//�e�N�X�`���}�b�s���O
//#define GRAVITY (TIPSIZE / 20.0f)	//�d�͉����x
//#define JUMPV0 (TIPSIZE / 1.4f)		//�W�����v�̏���

#define TEXCOORD2 136,156,158,128	//�E����2
#define TEXLEFT1 188,168,158,128	//������1
#define TEXLEFT2 156,136,158,128	//������2
#define VELOCITY 4.0f	//�ړ����x

#define HP 3 //HP�̏����l��3

#define SE_JUMP "res\\jump.wav" //�W�����v�̉����t�@�C��

int CPlayer2::sHp = 0;	//HP

int CPlayer2::Hp()
{
	return sHp;
}

void CPlayer2::Collision()
{
	CApplication::CharacterManager()->Collision(this);
}

void CPlayer2::Collision(CCharacter* m, CCharacter* o)
{
	float x, y;
	switch (o->Tag())
	{
	case ETag::EENEMY:
		if (CRectangle::Collision(o, &x, &y))
		{
			//�G�̏Փ˔�������s
			o->Collision(o, m);
			X(X() + x);
			Y(Y() + y);
			//���n������
			//if (y != 0.0f)
			//{
			//	//Y�����x��0�ɂ���
			//	mVy = 0.0f;
			//	if (y > 0.0f)
			//	{
			//		mState = EState::EMOVE;
			//	}
				
				//{	//�W�����v�łȂ���΋���
				//	mState = EState::ECRY;
				//	if (mInvincible == 0)
				//	{
				//		mInvincible = 80;
				//		sHp--;
				//	}
				//}
			//}
		//	else
			//{	//�W�����v�łȂ���΋���
			//	mState = EState::ECRY;
				if (mInvincible == 0)
				{
					mInvincible = 80;
					sHp--;
				}
			}
		//}
		break;
	case ETag::EPLAYER:
		break;
	case ETag::EHIDARI:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
		}
		break;
	case ETag::EMIGI:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
		}
		break;
	case ETag::EUE:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
		}
		break;
	case ETag::ESHITA:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
		}
		break;
	case ETag::EBLOCK2:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
		}
		break;
	case ETag::EBLOCK:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
			sHp = 0;
		}
		break;
	case ETag::EBLOCK1:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
			sHp = 0;
		}
		break;
	case ETag::EBLOCKK:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
			sHp = 0;
		}
		break;
	case ETag::EBLOCKKK:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
			sHp = 0;
		}
		break;
	case ETag::EBLOCKS:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
		}
		break;
	case ETag::EBLOCK3:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
		}
		break;
	case ETag::EBLOCK4:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
		}
		break;
	case ETag::EKABE:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
			if (mInvincible == 0)
			{
				mInvincible = 80;
				sHp--;
				if (mInvincible < 80)
				{
					mState = EState::EMOVE;
				}
			}
		}
		break;
	case ETag::EKABEX:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
			if (mInvincible == 0)
			{
				mInvincible = 80;
				sHp--;
				if (mInvincible < 80)
				{
					mState = EState::EMOVE;
				}
			}
		}
		break;
	case ETag::EKABEY:
			if (CRectangle::Collision(o, &x, &y))
			{
				X(X() + x);
				Y(Y() + y);
					if (mInvincible == 0)
					{
						mInvincible = 80;
						sHp--;
						if (mInvincible < 80)
						{
							mState = EState::EMOVE;
						}
					}
			}
		break;
	}
}

CPlayer2::CPlayer2(float x, float y, float w, float h, CTexture* pt)
	: mInvincible(0)
{
	Set(x, y, w, h);
	Texture(pt, MARU);
	//Texture3(pt, MARU1);
	mTag = ETag::EPLAYER;
	sHp = HP;
	//�W�����v�����[�h
	mSoundJump.Load(SE_JUMP);
}

void CPlayer2::Update()
{
	//���G���Ԓ��̓J�E���g����������
	if (mInvincible > 0)
	{
		mInvincible--;
	}
	//if (mState != EState::EJUMP)
	//{
		//if (mInput.Key('J'))
		//{
			//�W�����v��
			//mSoundJump.Play(0.1f);
			//mVy = JUMPV0;
			//mState = EState::EJUMP;
		//}
	//}
	if (mInput.Key('A')|| mInput.Key(VK_NUMPAD4))
	{
		if (CYZ::SPEED == 0)
		{
			//mVx = -VELOCITY;
			float x = X() - 4.0f;
			//X(X() + mVx);
			X(x);
		}
		if (CYZ::SPEED == 1)
		{
			float x = X() - 4.5f;
			X(x);
		}
		if (CYZ::SPEED == 2)
		{
			float x = X() - 5.0f;
			X(x);
		}
		if (CYZ::SPEED == 3)
		{
			float x = X() - 5.5f;
			X(x);
		}
		if (CYZ::SPEED == 4)
		{
			float x = X() - 6.0f;
			X(x);
		}
		if (CYZ::SPEED == 5)
		{
			float x = X() - 6.5f;
			X(x);
		}
		if (CYZ::SPEED == 6)
		{
			float x = X() - 7.0f;
			X(x);
		}
	}
	if (mInput.Key('D')|| mInput.Key(VK_NUMPAD6))
	{
		if (CYZ::SPEED == 0)
		{
			//mVx = VELOCITY;
			float x = X() + 4.0f;
			//X(X() + mVx);
			X(x);
		}
		if (CYZ::SPEED == 1)
		{
			float x = X() + 4.5f;
			X(x);
		}
		if (CYZ::SPEED == 2)
		{
			float x = X() + 5.0f;
			X(x);
		}
		if (CYZ::SPEED == 3)
		{
			float x = X() + 5.5f;
			X(x);
		}
		if (CYZ::SPEED == 4)
		{
			float x = X() + 6.0f;
			X(x);
		}
		if (CYZ::SPEED == 5)
		{
			float x = X() + 6.5f;
			X(x);
		}
		if (CYZ::SPEED == 10)
		{
			float x = X() + 7.0f;
			X(x);
		}
	}
	if (mInput.Key('W')|| (mInput.Key(VK_NUMPAD8)))
	{
		if (CYZ::SPEED == 0)
		{
			//mVy = VELOCITY;
			float y = Y() + 4.0f;
			//Y(Y() + mVy);
			Y(y);
		}
		if (CYZ::SPEED == 1)
		{
			float y = Y() + 4.5f;
			Y(y);
		}
		if (CYZ::SPEED == 2)
		{
			float y = Y() + 5.0f;
			Y(y);
		}
		if (CYZ::SPEED == 3)
		{
			float y = Y() + 5.5f;
			Y(y);
		}
		if (CYZ::SPEED == 4)
		{
			float y = Y() + 6.0f;
			Y(y);
		}
		if (CYZ::SPEED == 5)
		{
			float y = Y() + 6.5f;
			Y(y);
		}
		if (CYZ::SPEED == 6)
		{
			float y = Y() + 7.0f;
			Y(y);
		}
	}
	if (mInput.Key('S') || (mInput.Key(VK_NUMPAD5)))
	{
		if (CYZ::SPEED == 0)
		{
			//mVy = -VELOCITY;
			float y = Y() - 4.0f;
			//Y(Y() + mVy);
			Y(y);
		}
		if (CYZ::SPEED == 1)
		{
			float y = Y() - 4.5f;
			Y(y);
		}
		if (CYZ::SPEED == 2)
		{
			float y = Y() - 5.0f;
			Y(y);
		}
		if (CYZ::SPEED == 3)
		{
			float y = Y() - 5.5f;
			Y(y);
		}
		if (CYZ::SPEED == 4)
		{
			float y = Y() - 6.0f;
			Y(y);
		}
		if (CYZ::SPEED == 5)
		{
			float y = Y() - 6.5f;
			Y(y);
		}
		if (CYZ::SPEED == 6)
		{
			float y = Y() - 7.0f;
			Y(y);
		}
	}
	//if (mInput.Key(VK_LEFT))
	//{
	//	mVx = -VELOCITY;
	//	//		float x = X() - 4.0f;
	//	X(X() + mVx);
	//}
	//if (mInput.Key(VK_RIGHT))
	//{
	//	mVx = VELOCITY;
	//	//		float x = X() - 4.0f;
	//	X(X() + mVx);
	//}
	//if (mInput.Key(VK_UP))
	//{
	//	mVy = VELOCITY;
	//	Y(Y() + mVy);
	//}
	//if (mInput.Key(VK_DOWN))
	//{
	//	mVy = -VELOCITY;
	//	Y(Y() + mVy);
	//}
	//Y���W��Y�����x��������
	//Y(Y() + mVy);
	//Y�����x�ɏd�͂����Z����
	//mVy -= GRAVITY;

	if (mInvincible > 0)
	{
		mState = EState::ECRY;
	}
	if (mInvincible == 0)
	{
		mState = EState::EMOVE;
	}
	if (mState == EState::ECRY)
	{
		//�����摜��ݒ�
		Texture3(Texture(), MARU1);
	}
	else
	{
		const int PITCH = 32;//�摜��؂�ւ���Ԋu
		if ((int)X() % PITCH < PITCH / 2)
		{
			if (mVx < 0.0f) //���ֈړ�
			{
				//�������P��ݒ�
				Texture(Texture(), MARU);
			}
			else
			{
				//�ʏ�̉摜��ݒ�
				Texture(Texture(), MARU);
			}
		}
		else
		{
			if (mVx < 0.0f) //���ֈړ�
			{
				//������2��ݒ�
				Texture(Texture(), MARU);
			}
			else
			{
				//2�Ԗڂ̉摜��ݒ�
				Texture(Texture(), MARU);
			}
		}
	}
}
