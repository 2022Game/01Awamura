#pragma once
#include "CRectangle.h"
#include "CTexture.h"
#include "CCharacter.h"
#include "CBullet.h"
#include "CEnemy.h"
#include "CPlayer.h"
#include "CInput.h"
#include "CFont.h"
#include "CMiss.h"
#include <vector>
#include "CCharacterManager.h"
#include "CTexture.h"
#include "CGame.h"
#include "CSound.h"
#include "CYue.h"
#include "CYhidari.h"
#include "CYmigi.h"
#include "CYshita.h"
#include "CZkabe.h"
#include "CZkau.h"
#include "CZkas.h"
#include "CZkam.h"
#include "CZkah.h"
#include "CZkau1.h"
#include "CZkas1.h"
#include "CZkam1.h"
#include "CZkah1.h"
#include "CUi.h"
#include "CYZ.h"

class CApplication
{
private:
	CSound mSoundBgm;	//BGM
	CSound mSoundOver;	//ゲームオーバー
	CGame* mpGame;
	CYue* mpUe;
	CYshita* mpYshita;
	CYhidari* mpYhidari;
	CYmigi* mpYmigi;
	CZkabe* mpZkabe;
	CZkau* mpZkau;
	CZkas* mpZkas;
	CZkam* mpZkam;
	CZkah* mpZkah;
	CZkau1* mpZkau1;
	CZkas1* mpZkas1;
	CZkam1* mpZkam1;
	CZkah1* mpZkah1;
	CYZ* mpYZ;
	static CCharacterManager mCharacterManager;
	enum class EState
	{
		ESTART,	//ゲーム開始
		EPLAY,	//ゲーム中
		ECLEAR,	//ゲームクリア
		EOVER,	//ゲームオーバー
	};
	EState mState;
	//	CCharacter mRectangle;
	CPlayer* mpPlayer;
	static CTexture mTexture;
	static CTexture mTexture2;
	static CTexture mTexture3;
	static CTexture mTexture4;
	static CTexture mTexture5;
	CEnemy* mpEnemy;
	//	CBullet* mpBullet;
	CInput mInput;
	CFont mFont;
	CMiss* mpMiss;
	//CCharacterのポインタの可変長配列
//	std::vector<CCharacter*> mCharacters;
	int mNow;
public:
	static CCharacterManager* CharacterManager();
	static CTexture* Texture();
	static CTexture* Texture2();
	static CTexture* Texture3();
	static CTexture* Texture4();
	static CTexture* Texture5();
	//最初に一度だけ実行するプログラム
	void Start();
	//繰り返し実行するプログラム
	void Update();
};