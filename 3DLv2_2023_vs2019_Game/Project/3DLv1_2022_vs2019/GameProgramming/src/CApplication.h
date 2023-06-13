#pragma once
#include "CRectangle.h"
#include "CTexture.h"
#include "CCharacter.h"
#include "CBullet.h"
#include "CEnemy.h"
#include "CEnemy3.h"
#include "CPlayer.h"
#include "CAClearStage.h"
#include "CACoinClearStage.h"
#include "CACoin.h"
#include "CACoinGimmick.h"
#include "CAHamah.h"
#include "CAHamahGimmick.h"
#include "CAWall.h"
#include "CAWallGimmick.h"
#include "CInput.h"
#include "CFont.h"
#include "CMiss.h"
#include <vector>
#include "CCharacterManager.h"

#include "CGame.h"
#include "CSound.h"
#include "CVector.h"
#include "CModel.h"
#include "CMatrix.h"
#include "CCharacter3.h"
#include "CTaskManager.h"
#include "CBillBoard.h"
#include "CColliderTriangle.h"
#include "CColliderMesh.h"

class CApplication
{
private:
	static CUi* spUi; //UIクラスのポインタ
	//モデルビューの逆行列
	static CMatrix mModelViewInverse;
	//static CTaskManager mTaskManager;
	CSound mSoundBgm;	//BGM
	CSound mSoundOver;	//ゲームオーバー
	CGame* mpGame;
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
	CEnemy* mpEnemy;
	CBillBoard* mpBillBoard;
	//	CBullet* mpBullet;
	CInput mInput;
	CFont mFont;
	CMiss* mpMiss;
	CVector mEye;
	CMatrix mMatrix;
	//CCharacter3 mCharacter;
	CPlayer mPlayer;
	CACoin* mpCoin;
	//CAHamah* mpHamah;
	//モデルインスタクラスの作成
	CModel mModel;
	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//CCharacterのポインタの可変長配列
//	std::vector<CCharacter*> mCharacters;
	CModel mBackGround; //背景モデル
	//C5モデル
	CModel mModelC5;
	//Coinモデル
	CModel mModelCoin;
	//Hamahモデル
	CModel mModelHamah;
	CModel mModelWall;
	//モデルからコライダを生成
	CColliderMesh mColliderMesh;

	CAClearStage* mpClearStage;
	CACoinGimmick* mpCoinGimmick;
	CAHamahGimmick* mpHamahGimmick;
	CAWallGimmick* mpWallGimmick;
//	CACClearStage* mpCoinClearStage;
public:
	~CApplication();
	int Init();
	static int SelectStage;
	static int StageSwitch;
	static int StageGuard;
	static int StageCount;
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