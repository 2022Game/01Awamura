#include "CNeedle.h"
#include "Maths.h"
#include "CCollider.h"
#include "CPlayer.h"

CNeedle::CNeedle(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
{
	/*mpColliderSphere = new CColliderSphere(this, ELayer::eMove, 1.0f, false, 100.0f);
	mpColliderSphere->Position(0.0f, -0.5f, 0.0f);*/
	mpColliderMesh = new CColliderMesh(this, ELayer::eDead, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);

	mpColliderMesh->SetCollisionLayers({ ELayer::ePlayer});
}

CNeedle::~CNeedle()
{
	SAFE_DELETE(mpColliderMesh);
}

void CNeedle::Update()
{

}

void CNeedle::Collision(CCollider* self, CCollider* other, const CHitInfo& hit)
{

}

void CNeedle::Render()
{
	mpModel->Render(Matrix());
}