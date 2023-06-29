#include "CXEnemy.h"
#include "CCollisionManager.h"

CXEnemy::CXEnemy()
	:mColSphereBody(this, nullptr, CVector(), 0.5f, CCollider::ETag::EBODY)
	,mColSphereHead(this, nullptr, CVector(0.0f, 5.0f, -3.0f), 0.5f)
	,mColSphereSword(this, nullptr, CVector(-10.0f, 10.0f, 50.0f), 0.3f,CCollider::ETag::ESWORD)
{
}

void CXEnemy::Init(CModelX* model)
{
	CXCharacter::Init(model);
	//合成行列の設定
	mColSphereBody.Matrix(&mpCombinedMatrix[8]);
	//頭
	mColSphereHead.Matrix(&mpCombinedMatrix[11]);
	//剣
	mColSphereSword.Matrix(&mpCombinedMatrix[21]);
}

void CXEnemy::Collision(CCollider* m, CCollider* o) {
	//自身のコライダタイプの判定
	switch (o->Type()) {
	case CCollider::ESPHERE:
		if (m->Parent()->EPLAYER == ETag::EPLAYER)
		{
			if (m->Type() == CCollider::ESPHERE)
			{
				if (m->Tag() == CCollider::ETag::ESWORD)
				{
					if (CCollider::Collision(m, o))
					{
						ChangeAnimation(11, false, 30);
					}
				}
			}
		}
			break;
	}
}