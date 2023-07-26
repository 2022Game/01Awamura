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
#include "CAAcleateStage.h"

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

	CInput mInput;

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
	static int StageDelete;
	static int hcount;
	static int Rcount;
	static int reset;
	//static int Cleate;
	//static int Stage;
	static CUi* Ui();
	//モデルビュー行列の取得
	static const CMatrix& ModelViewInverse();
	//最初に一度だけ実行するプログラム
	void Start();
	//繰り返し実行するプログラム
	void Update();
};