#include "CCube.h"
#include "Maths.h"
#include "CCollider.h"

CCube::CCube(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eObject, mpModel, true);
	Position(pos);
	Scale(scale);
	mpColliderMesh->SetCollisionLayers({ ELayer::ePlayer });
}

CCube::~CCube()
{
	SAFE_DELETE(mpColliderMesh);
}

void CCube::Update()
{
}

void CCube::Render()
{
	mpModel->SetColor(mColor);
	mpModel->Render(Matrix());
}