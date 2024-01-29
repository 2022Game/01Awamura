#include "CBollField.h"
#include "Maths.h"
#include "CCollider.h"

CBollField::CBollField(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel, true);
	Position(pos);
	Scale(scale);
}

CBollField::~CBollField()
{
	SAFE_DELETE(mpColliderMesh);
}

void CBollField::Update()
{

}

void CBollField::Render()
{
	mpModel->Render(Matrix());
}