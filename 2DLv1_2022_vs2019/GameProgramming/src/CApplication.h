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
	CSound mSoundOver;	//�Q�[���I�[�o�[
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
		ESTART,	//�Q�[���J�n
		EPLAY,	//�Q�[����
		ECLEAR,	//�Q�[���N���A
		EOVER,	//�Q�[���I�[�o�[
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
	//CCharacter�̃|�C���^�̉ϒ��z��
//	std::vector<CCharacter*> mCharacters;
	int mNow;
public:
	static CCharacterManager* CharacterManager();
	static CTexture* Texture();
	static CTexture* Texture2();
	static CTexture* Texture3();
	static CTexture* Texture4();
	static CTexture* Texture5();
	//�ŏ��Ɉ�x�������s����v���O����
	void Start();
	//�J��Ԃ����s����v���O����
	void Update();
};