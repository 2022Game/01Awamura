#pragma once
#include "CUi.h"
#include "CPlayer2.h"
#include "CCharacter.h"

//定数の定義
#define TEXTURE "image.png" //テクスチャのファイル名
#define YYAZIRUSI "0193_2.pig" //矢印透明
#define UE "0193_6.png" //上
#define SHITA "0193_7.png" //下
#define MIGI "0193_9.png" //右
#define HIDARI "0193_8.png" //左
#define MARU1 "maru1.png"
#define MARU2 "maru2.png"
#define MARU "maru.png"
#define TIPSIZE 16.0f //マップ要素のサイズ
#define KABE "111.png"//壁
#define SSUP "UP.png"
#define pengin  "1.phoeniikun_ichika.png"
#define pengin1 "2.phoeniikun_saki.png"
#define pengin2 "4.phoeniikun_honami.png"
#define pengin3 "3.phoeniikun_shiho.png"
/*
* CGameクラス
* ゲームクラス
* ゲームのマップを作成し、
* キャラクタを配置する
*/
class CGame 
{
public:
	//デストラクタ
	~CGame();
	//ゲームクリア判定
	bool IsClear();
	//ゲームクリア処理
	void Clear();
	//ゲームオーバー判定
	bool IsOver();
	//ゲームオーバー処理
	void Over();
	//スタート処理
	void Start();
	CGame(); //デフォルトコンストラクタ（初期処理）
	void Update(); //更新処理
private:
	int mCdx, mCdy; //カメラとプレイヤーの座標の差分
	void CameraSet(); //カメラ設定
	CPlayer2* mpPlayer; //プレイヤーのポインタ
	int mNow; //経過時間
	int mNow1;
	int mNow2;
	int mNow3;
	int mSpeed;
	CUi* mpUi; //UIクラスのポインタ
};
