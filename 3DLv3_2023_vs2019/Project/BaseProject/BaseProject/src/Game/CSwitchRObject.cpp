#include "CSwitchRObject.h"
#include "Maths.h"
#include "CCollider.h"

CSwitchRObject::CSwitchRObject(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
{
	/*this, ELayer::eMoveRSwitch, mpModel, true*/
	mpColliderSphere = new CColliderSphere(/*this, ELayer::eMoveRSwitch, mpModel, true*/this, ELayer::eMoveRSwitch, 1.0f, true, 100.0f);
	Position(mDefaultPos);
	Scale(scale);
}

CSwitchRObject::~CSwitchRObject()
{
	SAFE_DELETE(mpColliderSphere);
}

void CSwitchRObject::Update()
{
}

void CSwitchRObject::Render()
{
	mpModel->Render(Matrix());
}