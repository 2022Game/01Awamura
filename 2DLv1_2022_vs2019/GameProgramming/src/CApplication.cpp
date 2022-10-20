#include "CApplication.h"
#include "CRectangle.h"
#include "CCharacterManager.h"

//�N���X��static�ϐ�
CTexture CApplication::mTexture;
CTexture CApplication::mTexture2;
CTexture CApplication::mTexture3;
CTexture CApplication::mTexture4;
CTexture CApplication::mTexture5;
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

void CApplication::Start()
{

	//Sound
	mSoundBgm.Load(SOUND_BGM);
	mSoundOver.Load(SOUND_OVER);
	mFont.Load("FontWhite.png", 1, 64);
	mState = EState::ESTART;
	mpGame = new CGame();
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(81.0f,1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(114.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(148.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(182.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(216.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(250.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(284.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(318.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(352.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(386.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(420.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(454.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(488.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(522.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(556.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(590.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(624.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(658.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(692.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkau = new CZkau();
	mpZkau->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkau->Set(719.0f, 1900.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkau);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(81.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(114.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(148.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(182.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(216.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(250.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(284.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(318.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(352.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(386.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(420.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(454.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(488.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(522.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(556.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(590.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(624.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(658.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(692.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkas = new CZkas();
	mpZkas->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkas->Set(719.0f, -1300.0f, 16.9f, 300.0f);
	mCharacterManager.Add(mpZkas);
	mpZkam = new CZkam();
	mpZkam->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkam->Set(2100.0f, 80.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkam);
	mpZkam = new CZkam();
	mpZkam->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkam->Set(2100.0f, 112.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkam);
	mpZkam = new CZkam();
	mpZkam->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkam->Set(2100.0f, 144.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkam);
	mpZkam = new CZkam();
	mpZkam->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkam->Set(2100.0f, 176.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkam);
	mpZkam = new CZkam();
	mpZkam->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkam->Set(2100.0f, 208.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkam);
	mpZkam = new CZkam();
	mpZkam->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkam->Set(2100.0f, 240.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkam);
	mpZkam = new CZkam();
	mpZkam->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkam->Set(2100.0f, 272.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkam);
	mpZkam = new CZkam();
	mpZkam->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkam->Set(2100.0f, 304.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkam);
	mpZkam = new CZkam();
	mpZkam->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkam->Set(2100.0f, 336.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkam);
	mpZkam = new CZkam();
	mpZkam->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkam->Set(2100.0f, 368.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkam);
	mpZkam = new CZkam();
	mpZkam->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkam->Set(2100.0f, 400.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkam);
	mpZkam = new CZkam();
	mpZkam->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkam->Set(2100.0f, 432.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkam);
	mpZkam = new CZkam();
	mpZkam->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkam->Set(2100.0f, 464.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkam);
	mpZkam = new CZkam();
	mpZkam->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkam->Set(2100.0f, 496.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkam);
	mpZkam = new CZkam();
	mpZkam->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkam->Set(2100.0f, 528.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkam);
	mpZkah = new CZkah();
	mpZkah->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkah->Set(-1300.0f, 80.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkah);
	mpZkah = new CZkah();
	mpZkah->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkah->Set(-1300.0f, 112.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkah);
	mpZkah = new CZkah();
	mpZkah->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkah->Set(-1300.0f, 144.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkah);
	mpZkah = new CZkah();
	mpZkah->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkah->Set(-1300.0f, 176.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkah);
	mpZkah = new CZkah();
	mpZkah->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkah->Set(-1300.0f, 208.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkah);
	mpZkah = new CZkah();
	mpZkah->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkah->Set(-1300.0f, 240.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkah);
	mpZkah = new CZkah();
	mpZkah->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkah->Set(-1300.0f, 272.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkah);
	mpZkah = new CZkah();
	mpZkah->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkah->Set(-1300.0f, 304.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkah);
	mpZkah = new CZkah();
	mpZkah->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkah->Set(-1300.0f, 336.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkah);
	mpZkah = new CZkah();
	mpZkah->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkah->Set(-1300.0f, 368.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkah);
	mpZkah = new CZkah();
	mpZkah->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkah->Set(-1300.0f, 400.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkah);
	mpZkah = new CZkah();
	mpZkah->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkah->Set(-1300.0f, 432.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkah);
	mpZkah = new CZkah();
	mpZkah->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkah->Set(-1300.0f, 464.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkah);
	mpZkah = new CZkah();
	mpZkah->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkah->Set(-1300.0f, 496.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkah);
	mpZkah = new CZkah();
	mpZkah->Texture(&mTexture, 0.0f, 45.0f, 68.0f, 100.0f);
	mpZkah->Set(-1300.0f, 528.0f, 300.0f, 16.0f);
	mCharacterManager.Add(mpZkah);
}

void CApplication::Update()
{
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
			//�Q�[���̃C���X�^���X����
			mpGame = new CGame();
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
			mpGame = new CGame();
			mState = EState::ESTART;
		}
		break;
	}
}
