#include "CApplication.h"
#include "CRectangle.h"
#include "CCharacterManager.h"

//クラスのstatic変数
CTexture CApplication::mTexture;
CTexture CApplication::mTexture2;
CTexture CApplication::mTexture3;
CTexture CApplication::mTexture4;
CTexture CApplication::mTexture5;
CCharacterManager CApplication::mCharacterManager;

#define SOUND_BGM "res\\mario.wav" //BGM音声ファイル
#define SOUND_OVER "res\\mdai.wav" //ゲームオーバー音声ファイル

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
	case EState::ESTART:	//状態がスタート
		mpGame->Start();	//スタート画面表示
		//Enterキーが押されたら
		if (mInput.Key(VK_RETURN))
		{	//状態をプレイ中にする
			mState = EState::EPLAY;
			//BGMリピート再生
			mSoundBgm.Repeat();
		}
		break;
	case EState::EPLAY:
		mpGame->Update();
		//ゲームオーバーか判定
		if (mpGame->IsOver())
		{	//状態をゲームオーバーにする
			mState = EState::EOVER;
			//BGMストップ
			mSoundBgm.Stop();
			//ゲームオーバー
			mSoundOver.Play();
		}
		//ゲームクリアか判定
		if (mpGame->IsClear())
		{	//状態をゲームクリアにする
			mState = EState::ECLEAR;
		}
		break;
	case EState::EOVER:
		//ゲームオーバー処理
		mpGame->Over();
		//エンターキー入力時
		if (mInput.Key(VK_RETURN))
		{	//ゲームのインスタンス削除
			delete mpGame;
			//ゲームのインスタンス生成
			mpGame = new CGame();
			//状態をスタートにする
			mState = EState::ESTART;
		}
		break;
	case EState::ECLEAR:
		//ゲームクリア処理
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
