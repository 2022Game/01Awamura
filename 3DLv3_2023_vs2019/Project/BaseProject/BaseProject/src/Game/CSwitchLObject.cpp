#include "CSwitchLObject.h"
#include "Maths.h"
#include "CCollider.h"

CSwitchLObject::CSwitchLObject(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
{
	mpColliderSphere = new CColliderSphere(/*this, ELayer::eMoveRSwitch, mpModel, true*/this, ELayer::eMoveLSwitch, 1.0f, true, 100.0f);
	Position(mDefaultPos);
	Scale(scale);
}

CSwitchLObject::~CSwitchLObject()
{
	SAFE_DELETE(mpColliderSphere);
}

void CSwitchLObject::Update()
{
}

void CSwitchLObject::Render()
{
	mpModel->Render(Matrix());
}