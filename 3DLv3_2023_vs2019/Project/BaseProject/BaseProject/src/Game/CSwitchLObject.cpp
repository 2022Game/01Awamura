#include "CSwitchLObject.h"
#include "Maths.h"
#include "CCollider.h"

CSwitchLObject::CSwitchLObject(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eMoveLSwitch, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
}

CSwitchLObject::~CSwitchLObject()
{
	SAFE_DELETE(mpColliderMesh);
}

void CSwitchLObject::Update()
{
}

void CSwitchLObject::Render()
{
	mpModel->Render(Matrix());
}