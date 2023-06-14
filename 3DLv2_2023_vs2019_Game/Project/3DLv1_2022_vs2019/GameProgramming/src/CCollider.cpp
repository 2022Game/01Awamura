#include "CCollider.h"
#include "CCollisionManager.h"
#include "CColliderLine.h"
#include <cmath>

//�D��x�̕ύX
void CCollider::ChangePriority()
{
	//�����̍��W�~�e�̕ϊ��s����|���ă��[���h���W�����߂�
	CVector pos = Position() * *mpMatrix;
	//�x�N�g���̒������D��x
	ChangePriority(pos.Length());
	//mPriority = pos.Length();
	//CCollisionManager::Instance()->Remove(this); //��U�폜
	//CCollisionManager::Instance()->Add(this); //�ǉ�
}

void CCollider::ChangePriority(int priority)
{
	mPriority = priority;
	CCollisionManager::Instance()->Remove(this); //��U�폜
	CCollisionManager::Instance()->Add(this); //�ǉ�
}

CCollider::CCollider()
	: mpParent(nullptr)
	, mpMatrix(&Matrix())
	, mType(ESPHERE)
	, mRadius(0)
{
	//�R���W�����}�l�[�W���ɒǉ�
	CCollisionManager::Instance()->Add(this);
}

CCollider::~CCollider() {
	//�R���W�������X�g����폜
	CCollisionManager::Instance()->Remove(this);
}

CCollider::CCollider(CCharacter3* parent, const CMatrix* matrix,
	const CVector& position, float radius)
	: CCollider()
{
	//�e�ݒ�
	mpParent = parent;
	//�e�s��ݒ�
	mpMatrix = matrix;
	//CTransform�ݒ�
	Position(position); //�ʒu
	//���a�ݒ�
	mRadius = radius;
	//�R���W�����}�l�[�W��y�ɒǉ�
	//CCollisionManager::Instance()->Add(this);
}

CCharacter3* CCollider::Parent()
{
	return mpParent;
}

void CCollider::Render() {
	glPushMatrix();
	//�R���C�_�̒��S���W���v�Z
	//�����̍��W�~�e�̕ϊ��s����|����
	CVector pos = Position() * *mpMatrix;
	//���S���W�ֈړ�
	glMultMatrixf(CMatrix().Translate(pos.X(), pos.Y(), pos.Z()).M());
	//DIFFUSE�ԐF�ݒ�
	float c[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	//���`��
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
	//�e�R���C�_�̒��_�����[���h���W�֕ϊ�
	v[0] = t->mV[0] * *t->mpMatrix;
	v[1] = t->mV[1] * *t->mpMatrix;
	v[2] = t->mV[2] * *t->mpMatrix;
	sv = l->mV[0] * *l->mpMatrix;
	ev = l->mV[1] * *l->mpMatrix;
	//�ʂ̖@�����A�O�ς𐳋K�����ċ��߂�
	CVector normal = (v[1] - v[0]).Cross(v[2] - v[0]).Normalize();
	//�O�p�̒��_��������n�_�ւ̃x�N�g�������߂�
	CVector v0sv = sv - v[0];
	//�O�p�̒��_��������I�_�ւ̃x�N�g�������߂�
	CVector v0ev = ev - v[0];
	//�������ʂƌ������Ă��邩���ςŊm�F����
	float dots = v0sv.Dot(normal);
	float dote = v0ev.Dot(normal);
	//�v���X�͌������ĂȂ�
	if (dots * dote >= 0.0f) {
		//�Փ˂��ĂȂ��i�����s�v�j
		*a = CVector(0.0f, 0.0f, 0.0f);
		return false;
	}

	//�����͖ʂƌ������Ă���
	//�ʂƐ����̌�_�����߂�
	//��_�̌v�Z
	CVector cross = sv + (ev - sv) * (abs(dots) / (abs(dots) + abs(dote)));

	//��_���O�p�`���Ȃ�Փ˂��Ă���
	//���_1���_2�x�N�g���ƒ��_1��_�x�N�g���Ƃ̊O�ς����߁A
	//�@���Ƃ̓��ς��}�C�i�X�Ȃ�A�O�p�`�̊O
	if ((v[1] - v[0]).Cross(cross - v[0]).Dot(normal) < 0.0f) {
		//�Փ˂��ĂȂ�
		*a = CVector(0.0f, 0.0f, 0.0f);
		return false;
	}
	//���_2���_3�x�N�g���ƒ��_2��_�x�N�g���Ƃ̊O�ς����߁A
	//�@���Ƃ̓��ς��}�C�i�X�Ȃ�A�O�p�`�̊O
	if ((v[2] - v[1]).Cross(cross - v[1]).Dot(normal) < 0.0f) {
		//�Փ˂��ĂȂ�
		*a = CVector(0.0f, 0.0f, 0.0f);
		return false;
	}
	//�ۑ�R�Q
	//���_3���_1�x�N�g���ƒ��_3��_�x�N�g���Ƃ̊O�ς����߁A
	//�@���Ƃ̓��ς��}�C�i�X�Ȃ�A�O�p�`�̊O
	if ((v[0] - v[2]).Cross(cross - v[2]).Dot(normal) < 0.0f) {
		//�Փ˂��ĂȂ�
		*a = CVector(0.0f, 0.0f, 0.0f);
		return false;
	}

	//�����l�v�Z�i�Փ˂��Ȃ��ʒu�܂Ŗ߂��j
	if (dots < 0.0f) {
		//�n�_������
		*a = normal * -dots;
	}
	else {
		//�I�_������
		*a = normal * -dote;
	}
	return true;
}

bool CCollider::CollisionTriangleSphere(CCollider* t, CCollider* s, CVector* a)
{
	CVector v[3], sv, ev;
	//�e�R���C�_�̒��_�����[���h���W�֕ϊ�
	v[0] = t->mV[0] * *t->mpMatrix;
	v[1] = t->mV[1] * *t->mpMatrix;
	v[2] = t->mV[2] * *t->mpMatrix;
	//�ʂ̖@�����A�O�ς𐳋K�����ċ��߂�
	CVector normal = (v[1] - v[0]).Cross(v[2] - v[0]).Normalize();
	//���R���C�_�����[���h���W�ō쐬
	sv = s->Position() * *s->mpMatrix + normal * s->mRadius;
	ev = s->Position() * *s->mpMatrix - normal * s->mRadius;
	CColliderLine line(nullptr, nullptr, sv, ev);
	//�O�p�R���C�_�Ɛ��R���C�_�̏Փˏ���
	return CollisionTriangleLine(t, &line, a);
}

bool CCollider::CollisionSphere(CCollider* sphere1, CCollider* sphere2, CVector* adjust)
{
	//�e�R���C�_�̒��S���W�����߂�
	//���_�~�R���C�_�̕ϊ��s��~�e�̕ϊ��s��
	CVector pos1 = sphere1->Position() * *sphere1->mpMatrix;
	CVector pos2 = sphere2->Position() * *sphere2->mpMatrix;
	//���S���璆�S�ւ̃x�N�g�������߂�
	CVector vec = pos1 - pos2;
	float length = vec.Length();
	//���S�̋��������a�̍��v��菬�����ƏՓ�
	float sum = sphere1->mRadius + sphere2->mRadius;
	if (sum > length) {
		*adjust = pos2 + vec.Normalize() * sum;
		//�Փ˂��Ă���
		return  true;
	}

	*adjust = CVector(0.0f, 0.0f, 0.0f);
	//�Փ˂��Ă��Ȃ�
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
	//TODO:�����l�̑Ή�
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

//�Փ˔���
//Collision(�R���C�_1, �R���C�_2)
//retrun:true�i�Փ˂��Ă���jfalse(�Փ˂��Ă��Ȃ�)
bool CCollider::Collision(CCollider* m, CCollider* o)
{
	CVector adjust;
	return Collision(m, o, &adjust);
}

bool CCollider::Collision(CCollider* m, CCollider* o, CVector* adjust)
{
	bool ret = false;

	//�R���C�_�̎�ނŏՓ˔���̊֐���؂�ւ���

	//���R���C�_
	if (m->Type() == ESPHERE)
	{
		//���R���C�_�Ƌ��R���C�_
		if (o->Type() == ESPHERE)			ret = CollisionSphere(m, o, adjust);
		//���R���C�_�ƎO�p�R���C�_
		else if (o->Type() == ETRIANGLE)	ret = CollisionTriangleSphere(o, m, adjust);
		//���R���C�_�Ɛ����R���C�_
		else if (o->Type() == ELINE)		ret = CollisionSphereLine(m, o, adjust);
	}
	//�O�p�R���C�_
	else if (m->Type() == ETRIANGLE)
	{
		//�O�p�R���C�_�Ƌ��R���C�_
		if (o->Type() == ESPHERE)			ret = CollisionTriangleSphere(m, o, adjust);
		//TODO:�O�p�R���C�_�ƎO�p�R���C�_�̏Փ˔���̎���
		else if (o->Type() == ETRIANGLE);
		//�O�p�R���C�_�Ɛ����R���C�_
		else if (o->Type() == ELINE)		ret = CollisionTriangleLine(m, o, adjust);
	}
	//�����R���C�_
	else if (m->Type() == ELINE)
	{
		//�����R���C�_�Ƌ��R���C�_
		if (o->Type() == ESPHERE)			ret = CollisionSphereLine(o, m, adjust);
		//�����R���C�_�ƎO�p�R���C�_
		else if (o->Type() == ETRIANGLE)	ret = CollisionTriangleLine(o, m, adjust);
		//�����R���C�_�Ɛ����R���C�_
		else if (o->Type() == ELINE)		ret = CollisionLine(m, o, adjust);
	}

	return ret;
}