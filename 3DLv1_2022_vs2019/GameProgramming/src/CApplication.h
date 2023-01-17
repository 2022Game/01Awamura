#pragma once
#include "CRectangle.h"
#include "CTexture.h"
#include "CCharacter.h"
#include "CBullet.h"
#include "CEnemy.h"
#include "CEnemy3.h"
#include "CPlayer.h"
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
	//モデルインスタクラスの作成
	CModel mModel;
	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//CCharacterのポインタの可変長配列
//	std::vector<CCharacter*> mCharacters;
	CModel mBackGround; //背景モデル
	//C5モデル
	CModel mModelC5;
	//三角コライダの作成
	//CColliderTriangle mColliderTriangle;
	////三角コライダ２
	//CColliderTriangle mColliderTriangle2;
	//モデルからコライダを生成
	CColliderMesh mColliderMesh;
public:
	~CApplication();
	int Init();
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