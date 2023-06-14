#include "CCollider.h"
#include "CCollisionManager.h"
#include "CColliderLine.h"
#include <cmath>

//優先度の変更
void CCollider::ChangePriority()
{
	//自分の座標×親の変換行列を掛けてワールド座標を求める
	CVector pos = Position() * *mpMatrix;
	//ベクトルの長さが優先度
	ChangePriority(pos.Length());
	//mPriority = pos.Length();
	//CCollisionManager::Instance()->Remove(this); //一旦削除
	//CCollisionManager::Instance()->Add(this); //追加
}

void CCollider::ChangePriority(int priority)
{
	mPriority = priority;
	CCollisionManager::Instance()->Remove(this); //一旦削除
	CCollisionManager::Instance()->Add(this); //追加
}

CCollider::CCollider()
	: mpParent(nullptr)
	, mpMatrix(&Matrix())
	, mType(ESPHERE)
	, mRadius(0)
{
	//コリジョンマネージャに追加
	CCollisionManager::Instance()->Add(this);
}

CCollider::~CCollider() {
	//コリジョンリストから削除
	CCollisionManager::Instance()->Remove(this);
}

CCollider::CCollider(CCharacter3* parent, const CMatrix* matrix,
	const CVector& position, float radius)
	: CCollider()
{
	//親設定
	mpParent = parent;
	//親行列設定
	mpMatrix = matrix;
	//CTransform設定
	Position(position); //位置
	//半径設定
	mRadius = radius;
	//コリジョンマネージャyに追加
	//CCollisionManager::Instance()->Add(this);
}

CCharacter3* CCollider::Parent()
{
	return mpParent;
}

void CCollider::Render() {
	glPushMatrix();
	//コライダの中心座標を計算
	//自分の座標×親の変換行列を掛ける
	CVector pos = Position() * *mpMatrix;
	//中心座標へ移動
	glMultMatrixf(CMatrix().Translate(pos.X(), pos.Y(), pos.Z()).M());
	//DIFFUSE赤色設定
	float c[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	//球描画
	glutWireSphere(mRadius, 16, 16);
	glPopMatrix();
}

CCollider::EType CCollider::Type()
{
	return mType;
}

CCharacter3::ETag CCollider::Tag() const
{
	if (mpParent == nullptr) return CCharacter3::ETag::EZERO;
	return mpParent->Tag();
}

bool CCollider::CollisionTriangleLine(CCollider* t, CCollider* l, CVector* a)
{
	CVector v[3], sv, ev;
	//各コライダの頂点をワールド座標へ変換
	v[0] = t->mV[0] * *t->mpMatrix;
	v[1] = t->mV[1] * *t->mpMatrix;
	v[2] = t->mV[2] * *t->mpMatrix;
	sv = l->mV[0] * *l->mpMatrix;
	ev = l->mV[1] * *l->mpMatrix;
	//面の法線を、外積を正規化して求める
	CVector normal = (v[1] - v[0]).Cross(v[2] - v[0]).Normalize();
	//三角の頂点から線分始点へのベクトルを求める
	CVector v0sv = sv - v[0];
	//三角の頂点から線分終点へのベクトルを求める
	CVector v0ev = ev - v[0];
	//線分が面と交差しているか内積で確認する
	float dots = v0sv.Dot(normal);
	float dote = v0ev.Dot(normal);
	//プラスは交差してない
	if (dots * dote >= 0.0f) {
		//衝突してない（調整不要）
		*a = CVector(0.0f, 0.0f, 0.0f);
		return false;
	}

	//線分は面と交差している
	//面と線分の交点を求める
	//交点の計算
	CVector cross = sv + (ev - sv) * (abs(dots) / (abs(dots) + abs(dote)));

	//交点が三角形内なら衝突している
	//頂点1頂点2ベクトルと頂点1交点ベクトルとの外積を求め、
	//法線との内積がマイナスなら、三角形の外
	if ((v[1] - v[0]).Cross(cross - v[0]).Dot(normal) < 0.0f) {
		//衝突してない
		*a = CVector(0.0f, 0.0f, 0.0f);
		return false;
	}
	//頂点2頂点3ベクトルと頂点2交点ベクトルとの外積を求め、
	//法線との内積がマイナスなら、三角形の外
	if ((v[2] - v[1]).Cross(cross - v[1]).Dot(normal) < 0.0f) {
		//衝突してない
		*a = CVector(0.0f, 0.0f, 0.0f);
		return false;
	}
	//課題３２
	//頂点3頂点1ベクトルと頂点3交点ベクトルとの外積を求め、
	//法線との内積がマイナスなら、三角形の外
	if ((v[0] - v[2]).Cross(cross - v[2]).Dot(normal) < 0.0f) {
		//衝突してない
		*a = CVector(0.0f, 0.0f, 0.0f);
		return false;
	}

	//調整値計算（衝突しない位置まで戻す）
	if (dots < 0.0f) {
		//始点が裏面
		*a = normal * -dots;
	}
	else {
		//終点が裏面
		*a = normal * -dote;
	}
	return true;
}

bool CCollider::CollisionTriangleSphere(CCollider* t, CCollider* s, CVector* a)
{
	CVector v[3], sv, ev;
	//各コライダの頂点をワールド座標へ変換
	v[0] = t->mV[0] * *t->mpMatrix;
	v[1] = t->mV[1] * *t->mpMatrix;
	v[2] = t->mV[2] * *t->mpMatrix;
	//面の法線を、外積を正規化して求める
	CVector normal = (v[1] - v[0]).Cross(v[2] - v[0]).Normalize();
	//線コライダをワールド座標で作成
	sv = s->Position() * *s->mpMatrix + normal * s->mRadius;
	ev = s->Position() * *s->mpMatrix - normal * s->mRadius;
	CColliderLine line(nullptr, nullptr, sv, ev);
	//三角コライダと線コライダの衝突処理
	return CollisionTriangleLine(t, &line, a);
}

bool CCollider::CollisionSphere(CCollider* sphere1, CCollider* sphere2, CVector* adjust)
{
	//各コライダの中心座標を求める
	//原点×コライダの変換行列×親の変換行列
	CVector pos1 = sphere1->Position() * *sphere1->mpMatrix;
	CVector pos2 = sphere2->Position() * *sphere2->mpMatrix;
	//中心から中心へのベクトルを求める
	CVector vec = pos1 - pos2;
	float length = vec.Length();
	//中心の距離が半径の合計より小さいと衝突
	float sum = sphere1->mRadius + sphere2->mRadius;
	if (sum > length) {
		*adjust = pos2 + vec.Normalize() * sum;
		//衝突している
		return  true;
	}

	*adjust = CVector(0.0f, 0.0f, 0.0f);
	//衝突していない
	return false;
}

bool CCollider::CollisionSphereLine(CCollider* sphere, CCollider* line, CVector* adjust)
{
	CVector spherePos = sphere->Position() * *sphere->mpMatrix;
	CVector lineStartPos = line->mV[0] * *line->mpMatrix;
	CVector lineEndPos = line->mV[1] * *line->mpMatrix;

	CVector nearest;
	float length = CalcDistancePointToLine(spherePos, lineStartPos, lineEndPos, &nearest);
	if (length < sphere->mRadius)
	{
		/**adjust = nearest + (spherePos - nearest).Normalize() * sphere->mRadius;*/
		*adjust = (spherePos + (nearest - spherePos).Normalize() * sphere->mRadius) - nearest;
		return true;
	}

	*adjust = CVector(0.0f, 0.0f, 0.0f);
	return false;
}

bool CCollider::CollisionLine(CCollider* line1, CCollider* line2, CVector* adjust)
{
	//TODO:調整値の対応
	*adjust = CVector(0.0f, 0.0f, 0.0f);

	CVector S1 = line1->mV[0] * *line1->mpMatrix;
	CVector E1 = line1->mV[1] * *line1->mpMatrix;
	CVector S2 = line2->mV[0] * *line2->mpMatrix;
	CVector E2 = line2->mV[1] * *line2->mpMatrix;

	CVector S1E1 = E1 - S1;
	CVector S2E2 = E2 - S2;
	CVector CD = (E1 - S1).Cross(E2 - S2).Normalize();

	CVector S1S2 = S2 - S1;
	CVector S1E2 = E2 - S1;
	CVector S2S1 = S1 - S2;
	CVector S2E1 = E1 - S2;

	float length = 0.0f;
	float d1 = S1E1.Cross(S1S2).Dot(S1E1.Cross(S1E2));
	float d2 = S2E2.Cross(S2S1).Dot(S2E2.Cross(S2E1));
	if (d1 < 0 && d2 < 0)
	{
		length = abs(S1S2.Dot(CD));
	}
	else
	{
		float length1 = CalcDistancePointToLine(S1, S2, E2);
		float length2 = CalcDistancePointToLine(E1, S2, E2);
		float length3 = CalcDistancePointToLine(S2, S1, E1);
		float length4 = CalcDistancePointToLine(E2, S1, E1);
		length = fminf(fminf(length1, length2), fminf(length3, length4));
	}

	if (length < line1->mRadius + line2->mRadius)
	{
		return true;
	}

	return false;
}

float CCollider::CalcDistancePointToLine(const CVector& point, const CVector& lineS, const CVector& lineE, CVector* nearest)
{
	CVector SE = lineE - lineS;
	float t = (point - lineS).Dot(SE.Normalize());

	CVector C;
	if (t < 0) C = lineS;
	else if (t > SE.Length()) C = lineE;
	else
	{
		C = lineS + SE.Normalize() * t;
	}

	if (nearest != nullptr) *nearest = C;

	return (C - point).Length();
}

//衝突判定
//Collision(コライダ1, コライダ2)
//retrun:true（衝突している）false(衝突していない)
bool CCollider::Collision(CCollider* m, CCollider* o)
{
	CVector adjust;
	return Collision(m, o, &adjust);
}

bool CCollider::Collision(CCollider* m, CCollider* o, CVector* adjust)
{
	bool ret = false;

	//コライダの種類で衝突判定の関数を切り替える

	//球コライダ
	if (m->Type() == ESPHERE)
	{
		//球コライダと球コライダ
		if (o->Type() == ESPHERE)			ret = CollisionSphere(m, o, adjust);
		//球コライダと三角コライダ
		else if (o->Type() == ETRIANGLE)	ret = CollisionTriangleSphere(o, m, adjust);
		//球コライダと線分コライダ
		else if (o->Type() == ELINE)		ret = CollisionSphereLine(m, o, adjust);
	}
	//三角コライダ
	else if (m->Type() == ETRIANGLE)
	{
		//三角コライダと球コライダ
		if (o->Type() == ESPHERE)			ret = CollisionTriangleSphere(m, o, adjust);
		//TODO:三角コライダと三角コライダの衝突判定の実装
		else if (o->Type() == ETRIANGLE);
		//三角コライダと線分コライダ
		else if (o->Type() == ELINE)		ret = CollisionTriangleLine(m, o, adjust);
	}
	//線分コライダ
	else if (m->Type() == ELINE)
	{
		//線分コライダと球コライダ
		if (o->Type() == ESPHERE)			ret = CollisionSphereLine(o, m, adjust);
		//線分コライダと三角コライダ
		else if (o->Type() == ETRIANGLE)	ret = CollisionTriangleLine(o, m, adjust);
		//線分コライダと線分コライダ
		else if (o->Type() == ELINE)		ret = CollisionLine(m, o, adjust);
	}

	return ret;
}