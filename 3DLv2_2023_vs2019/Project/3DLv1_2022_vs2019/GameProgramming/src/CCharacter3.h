#ifndef CCHARACTER3_H
#define CCHARACTER3_H
//変換行列クラスのインクルード
#include "CTransform.h"
//モデルクラスのインクルード
#include "CModel.h"
#include "CTask.h"
/*
キャラクタークラス
ゲームキャラクタの基本的な機能を定義する
*/
//コライダクラスの宣言
class CCollider;
class CCharacter3 : public CTransform, public CTask {
public:
	enum class ETag
	{
		EZERO, //初期値
		EPLAYER, //プレイヤー
		EENEMY, //敵
		EBULLETPLAYER, //プレイヤー弾
		EBULLETENEMY, //敵弾
		ECOIN,
		ECOINEND,

		EOBSTACLE,//障害物
		ESTAGEGUARD,//ステージ管理
		ESTAGECLEAR,//ステージ管理２
	};
	//enum class EState	//状態
	//{
	//	ENULL,
	//	EOVER,
	//	ECLERE,
	//	EMOVE,	//移動
	//	ESTOP,	//停止
	//	EJUMP,	//ジャンプ
	//	ECRY,	//泣く
	//	EJO,    //ジャンプOK
	//};
	//タグの取得
	ETag Tag();
	//衝突処理
	virtual void Collision(CCollider* m, CCollider* o) {}
	//デストラクタ
	~CCharacter3();
	//コンストラクタ
	CCharacter3();
	//コンストラクタ
	CCharacter3(int priority);
	//モデルの設定
	//Model（モデルクラスのポインタ）
	void Model(CModel* m);
	//描画処理
	void Render();
	//キャラクター削除
	void Kill();
	//キャラクターが死んでるかどうか
	bool IsDeath() const;
	//キャラクターがクリアしたかどうか
	bool IsClear() const;
protected:
	int mHp;
	CModel* mpModel; //モデルのポインタ
	ETag mTag; //タグ
};

#endif