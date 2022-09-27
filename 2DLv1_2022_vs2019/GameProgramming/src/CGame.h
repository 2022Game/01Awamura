#pragma once
#include "CUi.h"
#include "CPlayer2.h"

//定数の定義
#define TEXTURE "image.png" //テクスチャのファイル名
#define YAZIRUSI "0193_2.pig" //矢印透明
#define YYAZURUSI "0193_6.png"
#define TIPSIZE 20.0f //マップ要素のサイズ
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
	CPlayer2 *mpPlayer; //プレイヤーのポインタ
	int mTime; //経過時間
	CUi *mpUi; //UIクラスのポインタ
};
