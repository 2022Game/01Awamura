#include "CTransparentField.h"
#include "Maths.h"
#include "CCollider.h"

CTransparentField::CTransparentField(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eDead, mpModel, true);
	Position(pos);
	Scale(scale);

	SetColor(CColor(1.0f, 0.0f, 1.0f, 0.0f));
}

CTransparentField::~CTransparentField()
{
	SAFE_DELETE(mpColliderMesh);
}

void CTransparentField::Update()
{

}

void CTransparentField::Render()
{
	mpModel->SetColor(mColor);
	mpModel->Render(Matrix());
}