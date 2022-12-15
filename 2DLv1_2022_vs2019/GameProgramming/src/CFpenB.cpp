#include "CFpenB.h"
#include "CApplication.h"

#define PENGIN 37,60,30,2	//�e�N�X�`���}�b�s���O
#define PENGINL 7,29,62,34
#define PENGINL2 29,7,62,34
#define PENGINN 39,63,62,34
#define PENGINN2 63,39,62,34

#define VELOCITY2 -2.0f

void CFpenB::Collision()
{
	CApplication::CharacterManager()->Collision(this);
}

void CFpenB::Collision(CCharacter* m, CCharacter* o)
{
	//�߂荞�ݒ����ϐ���錾����
	float x, y;
	switch (o->Tag())
	{
	case ETag::EBLOCK2:
		//�܂�Ԃ��ɓ���������
		if (CRectangle::Collision(o, &x, &y))
		{
			//�߂荞�܂Ȃ��ʒu�܂Ŗ߂�
			X(X() + x);
			Y(Y() + y);
			//X�����x�𔽓]������
			mVx = -mVx;
		}
		break;
	case ETag::EKABEX:
		if (CRectangle::Collision(o, &x, &y))
		{
			//�߂荞�܂Ȃ��ʒu�܂Ŗ߂�
			X(X() + x);
			Y(Y() + y);
			//X�����x�𔽓]������
			mVx = -mVx;
		}
		break;
	case ETag::EBLOCK3:
		if (CRectangle::Collision(o, &x, &y))
		{
			//�߂荞�܂Ȃ��ʒu�܂Ŗ߂�
			X(X() + x);
			Y(Y() + y);
			//X�����x�𔽓]������
			mVx = -mVx;
		}
		break;
	case ETag::EBLOCK:
		if (CRectangle::Collision(o, &x, &y))
		{
			mEnabled = false;
		}
		break;
	case ETag::EBLOCK1:
		if (CRectangle::Collision(o, &x, &y))
		{
			mEnabled = false;
		}
		break;
	case ETag::EBLOCKK:
		if (CRectangle::Collision(o, &x, &y))
		{
			mEnabled = false;
		}
		break;
	case ETag::EBLOCKKK:
		if (CRectangle::Collision(o, &x, &y))
		{
			mEnabled = false;
		}
		break;
	case ETag::EKABEY:
		if (CRectangle::Collision(o, &x, &y))
		{
			//�߂荞�܂Ȃ��ʒu�܂Ŗ߂�
			X(X() + x);
			Y(Y() + y);
			//X�����x�𔽓]������
			mVx = -mVx;
		}
		break;
	case ETag::EPLAYER:
		if (CRectangle::Collision(o))
		{
		}
		break;
	}
}

CFpenB::CFpenB(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, PENGIN);
	mTag = ETag::EENEMY;
	//X�����x�̏����l���ړ����x�ɂ���
	mVx = VELOCITY2;
}

void CFpenB::Update()
{
	switch (mState)
	{
	case EState::EMOVE:
		//X�����x���AX���W���X�V����
		X(X() - mVx);
		const int PITCH = 32;//�摜��؂�ւ���Ԋu
		if ((int)X() % PITCH < PITCH / 2)
		{
			if (mVx < 0.0f) //���ֈړ�
			{
				Texture(Texture(), PENGINN2);
			}
			else
			{
				//�ʏ�̉摜��ݒ�
				Texture(Texture(), PENGINN);
			}
		}
		else
		{
			if (mVx < 0.0f) //���ֈړ�
			{
				Texture(Texture(), PENGINL2);
			}
			else
			{
				//2�Ԗڂ̉摜��ݒ�
				Texture(Texture(), PENGINL);
			}
		}
		break;
	}
}