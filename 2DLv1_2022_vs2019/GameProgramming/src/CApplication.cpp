#include "CApplication.h"
#include "CRectangle.h"
#include "CCharacterManager.h"

//�N���X��static�ϐ�
CTexture CApplication::mTexture;
CTexture CApplication::mTexture2;
CTexture CApplication::mTexture3;
CTexture CApplication::mTexture4;
CTexture CApplication::mTexture5;
CTexture CApplication::mTexture6;
CTexture CApplication::mTexture7;
CTexture CApplication::mTexture8;
CCharacterManager CApplication::mCharacterManager;

#define SOUND_BGM "res\\mario.wav" //BGM�����t�@�C��
#define SOUND_OVER "res\\mdai.wav" //�Q�[���I�[�o�[�����t�@�C��

CCharacterManager* CApplication::CharacterManager()
{
	return &mCharacterManager;
}

CTexture* CApplication::Texture()
{
	return &mTexture;
}

CTexture* CApplication::Texture2()
{
	return &mTexture2;
}

CTexture* CApplication::Texture3()
{
	return &mTexture3;
}

CTexture* CApplication::Texture4()
{
	return &mTexture4;
}

CTexture* CApplication::Texture5()
{
	return &mTexture5;
}

CTexture* CApplication::Texture6()
{
	return &mTexture6;
}

CTexture* CApplication::Texture7()
{
	return &mTexture7;
}

CTexture* CApplication::Texture8()
{
	return &mTexture8;
}

void CApplication::Start()
{

	//Sound
	mSoundBgm.Load(SOUND_BGM);
	mSoundOver.Load(SOUND_OVER);
	mFont.Load("FontWhite.png", 1, 64);
	mState = EState::ESTART;
	mpGame = new CGame();
	mpYZ = new CYZ();
	//
	//mpZkau = new CZkau(97.0f, 2300.0f, 33.8f, 300.0f,0,45,68,100,&mTexture);
	//mCharacterManager.Add(mpZkau);
	//mpZkau = new CZkau(705.0f, 2300.0f, 33.8f, 300.0f, 0, 45, 68, 100, &mTexture);
	//mCharacterManager.Add(mpZkau);
	//mpZkau1 = new CZkau1(81.0f, 1900.0f, 16.9f, 300.0f,0,45,68,100,&mTexture);
	//mCharacterManager.Add(mpZkau1);
	//mpZkau1 = new CZkau1(401.0f, 1900.0f, 16.9f, 300.0f, 0, 45, 68, 100, &mTexture);
	//mCharacterManager.Add(mpZkau1);
	//mpZkau1 = new CZkau1(721.0f, 1900.0f, 16.9f, 300.0f, 0, 45, 68, 100, &mTexture);
	//mCharacterManager.Add(mpZkau1);
	//���E�召�̍���16.0f,
	//mpZkas = new CZkas(97.0f, -1700.0f, 33.8f, 300.0f,0,45,68,100,&mTexture);
	//mCharacterManager.Add(mpZkas);
	//mpZkas = new CZkas(705.0f, -1700.0f, 33.8f, 300.0f, 0, 45, 68, 100, &mTexture);
	//mCharacterManager.Add(mpZkas);
	//mpZkas1 = new CZkas1(81.0f, -1300.0f, 16.9f, 300.0f,0,45,68,100,&mTexture);
	//mCharacterManager.Add(mpZkas1);
	//mpZkas1 = new CZkas1(401.0f, -1300.0f, 16.9f, 300.0f, 0, 45, 68, 100, &mTexture);
	//mCharacterManager.Add(mpZkas1);
	//mpZkas1 = new CZkas1(721.0f, -1300.0f, 16.9f, 300.0f, 0, 45, 68, 100, &mTexture);
	//mCharacterManager.Add(mpZkas1);
	//
	//mpZkam = new CZkam(2500.0f, 96.0f, 600.0f, 32.0f,0,45,68,100,&mTexture);
	//mCharacterManager.Add(mpZkam);
	//mpZkam = new CZkam(2500.0f, 512.0f,600.0f, 32.0f, 0, 45, 68, 100, &mTexture);
	//mCharacterManager.Add(mpZkam);
	//mpZkam1 = new CZkam1(2100.0f, 80.0f, 600.0f, 16.0f,0,45,68,100,&mTexture);
	//mCharacterManager.Add(mpZkam1);
	//mpZkam1 = new CZkam1(2100.0f, 304.0f, 600.0f, 16.0f, 0, 45, 68, 100, &mTexture);
	//mCharacterManager.Add(mpZkam1);
	//mpZkam1 = new CZkam1(2100.0f, 528.0f, 600.0f, 16.0f, 0, 45, 68, 100, &mTexture);
	//mCharacterManager.Add(mpZkam1);
	//�㉺�召�̍���16.0��
	//mpZkah = new CZkah(-1700.0f, 96.0f, 600.0f, 32.0f,0,45,68,100,&mTexture);
	//mCharacterManager.Add(mpZkah);
	//mpZkah = new CZkah(-1700.0f, 512.0f, 600.0f, 32.0f, 0, 45, 68, 100, &mTexture);
	//mCharacterManager.Add(mpZkah);
	//mpZkah1 = new CZkah1(-1300.0f, 80.0f, 600.0f, 16.0f,0,45,68,100,&mTexture);
	//mCharacterManager.Add(mpZkah1);
	//mpZkah1 = new CZkah1(-1300.0f, 304.0f, 600.0f, 16.0f, 0, 45, 68, 100, &mTexture);
	//mCharacterManager.Add(mpZkah1);
	//mpZkah1 = new CZkah1(-1300.0f, 528.0f, 600.0f, 16.0f, 0, 45, 68, 100, &mTexture);
	//mCharacterManager.Add(mpZkah1);

	mpZkabe = new CZkabe(200.0f, 16.0f, 600.0f, 16.0f, 0, 0, 0, 0, &mTexture);
	mCharacterManager.Add(mpZkabe);
}

void CApplication::Update()
{
	//mCharacterManager.Collision();
	//mCharacterManager.Delete();
	switch (mState)
	{
	case EState::ESTART:	//��Ԃ��X�^�[�g
		mpGame->Start();	//�X�^�[�g��ʕ\��
		//Enter�L�[�������ꂽ��
		if (mInput.Key(VK_RETURN))
		{	//��Ԃ��v���C���ɂ���
			mState = EState::EPLAY;
			//BGM���s�[�g�Đ�
			mSoundBgm.Repeat();
		}
		break;
	case EState::EPLAY:
		mpGame->Update();
		mpYZ->Update();
		//�Q�[���I�[�o�[������
		if (mpGame->IsOver())
		{	//��Ԃ��Q�[���I�[�o�[�ɂ���
			mState = EState::EOVER;
			//BGM�X�g�b�v
			mSoundBgm.Stop();
			//�Q�[���I�[�o�[
			mSoundOver.Play();
		}
		//�Q�[���N���A������
		if (mpGame->IsClear())
		{	//��Ԃ��Q�[���N���A�ɂ���
			mState = EState::ECLEAR;
		}
		break;
	case EState::EOVER:
		//�Q�[���I�[�o�[����
		mpGame->Over();
		//�G���^�[�L�[���͎�
		if (mInput.Key(VK_RETURN))
		{	//�Q�[���̃C���X�^���X�폜
			delete mpGame;
			delete mpYZ;
			//�Q�[���̃C���X�^���X����
			mpGame = new CGame();
			mpYZ = new CYZ();
			mpZkabe = new CZkabe(200.0f, 16.0f, 600.0f, 16.0f, 0, 0, 0, 0, &mTexture);
			mCharacterManager.Add(mpZkabe);
			//��Ԃ��X�^�[�g�ɂ���
			mState = EState::ESTART;
		}
		break;
	case EState::ECLEAR:
		//�Q�[���N���A����
		mpGame->Clear();
		if (mInput.Key(VK_RETURN))
		{
			delete mpGame;
			delete mpYZ;
			mpYZ = new CYZ();
			mpGame = new CGame();
			mpZkabe = new CZkabe(200.0f, 16.0f, 600.0f, 16.0f, 0, 0, 0, 0, &mTexture);
			mCharacterManager.Add(mpZkabe);
			mState = EState::ESTART;
		}
		break;
	}
}