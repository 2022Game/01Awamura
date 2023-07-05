#ifndef CCOLLIDER_H
#define CCOLLIDER_H
//キャラクタクラスのインクルード
#include "CCharacter3.h"
class CCollisionManager;
/*
コライダクラス
衝突判定データ
*/
class CCollider : public CTransform,public CTask {
	friend CCollisionManager;
public:
	//優先度の変更
	virtual void ChangePriority();
	//優先度の変更
	void ChangePriority(int priority);
	//コライダタイプ
	enum class EType {
		ESPHERE,//球コライダ
		ETRIANGLE,//三角コライダ
		ELINE, //線分コライダ
	};

	//コライダのレイヤー
	enum class ELayer
	{
		EDEFAULT,
		EWOOD, //木のオブジェクトのコライダ
		ESOCCER, //Soccerのオブジェクトのコライダ
		EWALL,
		EDEATH, //死亡
		ECOIN, //コインのコライダ
		ELINEWALL, //線分の壁コライダ
	};

	EType Type() const;
	//コライダのレイヤーを取得
	ELayer Layer() const;
	//コライダのレイヤーを設定
	void Layer(ELayer layer);

	CCharacter3::ETag Tag() const;

	//CollisionTriangleLine(三角コライダ, 線分コライダ, 調整値)
	//retrun:true（衝突している）false(衝突していない)
	//調整値:衝突しない位置まで戻す値
	static bool CollisionTriangleLine(CCollider* triangle, CCollider* line, CVector* adjust);
	//CollisionTriangleSphere(三角コライダ, 球コライダ, 調整値)
	//retrun:true（衝突している）false(衝突していない)
	//調整値:衝突しない位置まで戻す値
	static bool CollisionTriangleSphere(CCollider* triangle, CCollider* sphere, CVector* adjust);
	//CollisionSphere(球コライダ, 球コライダ, 調整値)
	//retrun:true（衝突している）false(衝突していない)
	//調整値:衝突しない位置まで戻す値
	static bool CollisionSphere(CCollider* sphere1, CCollider* sphere2, CVector* adjust);
	//CollisionSphereLine(球コライダ, 線分コライダ, 調整値)
	//retrun:true（衝突している）false(衝突していない)
	//調整値:衝突しない位置まで戻す値
	static bool CollisionSphereLine(CCollider* sphere, CCollider* line, CVector* adjust);
	//CollisionLine(線分コライダ, 線分コライダ, 調整値)
	//（内部的にはカプセルとカプセルの衝突判定を行っている)
	//retrun:true（衝突している）false(衝突していない)
	//調整値:衝突しない位置まで戻す値
	static bool CollisionLine(CCollider* line1, CCollider* line2, CVector* adjust);

	static float CalcDistancePointToLine(const CVector& point, const CVector& lineS, const CVector& lineE, CVector* nearest = nullptr);

	//衝突判定
	//（コライダの種類によって自動で衝突判定を切り替える）
	//Collision(コライダ1, コライダ2)
	//retrun:true（衝突している）false(衝突していない)
	static bool Collision(CCollider* m, CCollider* o);
	//衝突判定 調整値有り版
	//（コライダの種類によって自動で衝突判定を切り替える）
	//Collision(コライダ1, コライダ2, 調整値)
	//retrun:true（衝突している）false(衝突していない)
	static bool Collision(CCollider* m, CCollider* o, CVector* adjust);

	//デフォルトコンストラクタ
	CCollider();

	~CCollider();
	//コンストラクタ
	//CCollider(親, 親行列, 位置, 半径)
	CCollider(CCharacter3* parent, const CMatrix* matrix,
		const CVector& position, float radius);
	//親ポインタの取得
	CCharacter3* Parent();
	//描画
	void Render();
protected:
	EType mType;//コライダタイプ
	ELayer mLayer; //コライダのレイヤー
	//頂点
	CVector mV[3];

	CCharacter3* mpParent;//親
	const CMatrix* mpMatrix;//親行列
	float mRadius;	//半径
};
#endif
