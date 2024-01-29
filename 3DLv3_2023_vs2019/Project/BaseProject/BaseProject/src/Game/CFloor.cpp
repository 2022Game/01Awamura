#include "CFloor.h"
#include "Maths.h"
#include "CCollider.h"

CFloor::CFloor(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel, true);
	Position(pos);
	Scale(scale);
}

CFloor::~CFloor()
{
	SAFE_DELETE(mpColliderMesh);
}

void CFloor::Update()
{
}

void CFloor::Render()
{
	mpModel->SetColor(mColor);
	mpModel->Render(Matrix());
}