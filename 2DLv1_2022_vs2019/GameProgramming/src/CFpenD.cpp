#include "CFpenC.h"
#include "CApplication.h"

#define PENGIN 37,60,30,2	//�e�N�X�`���}�b�s���O
#define PENGINL 5,29,30,2
#define PENGINL2 29,5,30,2
#define PENGINN 3,25,126,100
#define PENGINN2 25,3,126,100

#define VELOCITY3 -2.0f

void CFpenD::Collision()
{
	CApplication::CharacterManager()->Collision(this);
}

void CFpenD::Collision(CCharacter* m, CCharacter* o)
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
			mVy = -mVy;
		}
		break;
	case ETag::EKABEX:
		if (CRectangle::Collision(o, &x, &y))
		{
			//�߂荞�܂Ȃ��ʒu�܂Ŗ߂�
			X(X() + x);
			Y(Y() + y);
			//X�����x�𔽓]������
			mVy = -mVy;
		}
		break;
	case ETag::EBLOCK3:
		break;
	case ETag::EBLOCK4:
		if (CRectangle::Collision(o, &x, &y))
		{
			//�߂荞�܂Ȃ��ʒu�܂Ŗ߂�
			X(X() + x);
			Y(Y() + y);
			//X�����x�𔽓]������
			mVy = -mVy;
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
			mVy = -mVy;
		}
		break;
	case ETag::EPLAYER:
		if (CRectangle::Collision(o))
		{
		}
		break;
	}
}

CFpenD::CFpenD(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, PENGIN);
	mTag = ETag::EENEMY;
	//X�����x�̏����l���ړ����x�ɂ���
	mVy = VELOCITY3;
}

void CFpenD::Update()
{
	switch (mState)
	{
	case EState::EMOVE:
		//X�����x���AX���W���X�V����
		Y(Y() - mVy);
		const int PITCH = 32;//�摜��؂�ւ���Ԋu
		if ((int)Y() % PITCH < PITCH / 2)
		{
			if (mVy < 0.0f) //���ֈړ�
			{
				Texture(Texture(), PENGINN);
			}
			else
			{
				//�ʏ�̉摜��ݒ�
				Texture(Texture(), PENGINL);
			}
		}
		else
		{
			if (mVy < 0.0f) //���ֈړ�
			{
				Texture(Texture(), PENGINN2);
			}
			else
			{
				//2�Ԗڂ̉摜��ݒ�
				Texture(Texture(), PENGINL2);
			}
		}
		break;
	}
}