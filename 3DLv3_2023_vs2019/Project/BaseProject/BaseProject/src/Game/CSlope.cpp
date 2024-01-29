#include "CSlope.h"
#include "Maths.h"
#include "CCollider.h"

CSlope::CSlope(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eSlopeField, mpModel, true);
	Position(pos);
	Scale(scale);
	SetColor(CColor(1.0f, 0.0f, 1.0f, 1.0f));
	SetAlpha(0.1f);
}

CSlope::~CSlope()
{
	SAFE_DELETE(mpColliderMesh);
}

void CSlope::Update()
{
}

void CSlope::Render()
{
	mpModel->Render(Matrix());
}