#include "CIceField.h"
#include "Maths.h"
#include "CCollider.h"

CIceField::CIceField(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eIceField, mpModel, true);
	Position(pos);
	Scale(scale);
}

CIceField::~CIceField()
{
	SAFE_DELETE(mpColliderMesh);
}

void CIceField::Update()
{
}

void CIceField::Render()
{
	mpModel->SetColor(mColor);
	mpModel->Render(Matrix());
}