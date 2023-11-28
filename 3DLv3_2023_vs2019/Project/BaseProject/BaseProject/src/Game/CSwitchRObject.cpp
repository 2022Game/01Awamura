#include "CSwitchRObject.h"
#include "Maths.h"
#include "CCollider.h"

CSwitchRObject::CSwitchRObject(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eMoveRSwitch, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
}

CSwitchRObject::~CSwitchRObject()
{
	SAFE_DELETE(mpColliderMesh);
}

void CSwitchRObject::Update()
{
}

void CSwitchRObject::Render()
{
	mpModel->Render(Matrix());
}