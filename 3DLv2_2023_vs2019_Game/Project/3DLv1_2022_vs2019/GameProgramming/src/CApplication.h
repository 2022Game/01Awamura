#pragma once
#include "CTexture.h"
#include "CCharacter.h"
#include "CPlayer.h"
#include "CAClearStage.h"
#include "CACoinClearStage.h"
#include "CACoin.h"
#include "CACoinGimmick.h"
#include "CAHamah.h"
#include "CAHamahGimmick.h"
#include "CAWood.h"
#include "CAWoodGimmick.h"
#include "CAWall.h"
#include "CAWallGimmick.h"
#include "CCharacterManager.h"
#include "CASoccerGimmick.h"

#include "CSound.h"
#include "CVector.h"
#include "CModel.h"
#include "CMatrix.h"
#include "CTaskManager.h"
#include "CColliderTriangle.h"
#include "CColliderMesh.h"
#include "CUi.h"
#include "CColliderLine.h"
#include "CGameScene.h"

class CApplication
{
private:
	CGameScene* mpGameScene;
	CColliderLine mColliderLine8;
	static CUi* spUi; //UIクラスのポインタ
	//モデルビューの逆行列
	static CMatrix mModelViewInverse;
	//static CTaskManager mTaskManager;
	CSound mSoundBgm;	//BGM
	CSound mSoundOver;	//ゲームオーバー
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
	//	CBullet* mpBullet;
	CInput mInput;
	CFont mFont;
	/*CVector mEye;*/
	CMatrix mMatrix;
	CACoin* mpCoin;
	//CAHamah* mpHamah;
	//モデルインスタクラスの作成
	CModel mModel;
	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//CCharacterのポインタの可変長配列
//	std::vector<CCharacter*> mCharacters;
	CModel mBackGround; //背景モデル
	////C5モデル
	//CModel mModelC5;
	//Coinモデル
	CModel mModelCoin;
	//Hamahモデル
	CModel mModelHamah;
	//Wallモデル
	CModel mModelWall;
	//Woodモデル
	CModel mModelWood;
	//モデルからコライダを生成
	CColliderMesh mColliderMesh;

	CAClearStage* mpClearStage;
	CAClearStage* mpClearStage2;
	CAClearStage* mpClearStage3;
	CAClearStage* mpClearStage4;
	CACoinGimmick* mpCoinGimmick;
	CAHamahGimmick* mpHamahGimmick;
	CAWallGimmick* mpWallGimmick;
	CAWoodGimmick* mpWoodGimmick;
	CASoccerGimmick* mpSoccerGimmick;
//	CACClearStage* mpCoinClearStage;
	CUi* mpUi;
public:
	int mTime;
	int mRestart;
	CApplication();
	~CApplication();
	int Init();
	static int StageTime;
	static int SelectStage;
	static int StartCount;
	static int StageSwitch;
	static int StageGuard;
	static int StageCount;
	static int StageReset;
	static int StageCountGuard;
	static int StageCheck;
	static int StageClearDelete;
	static int hcount;
	static int Rcount;
	static CUi* Ui();
	//モデルビュー行列の取得
	static const CMatrix& ModelViewInverse();
	//static CTaskManager* TaskManager();
	static CCharacterManager* CharacterManager();
	static CTexture* Texture();
	//最初に一度だけ実行するプログラム
	void Start();
	//繰り返し実行するプログラム
	void Update();
};