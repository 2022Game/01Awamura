#include "CWarp.h"
#include "Maths.h"
#include "CCollider.h"

CWarp::CWarp(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eWarpObject, mpModel, true);
	Position(pos);
	Scale(scale);
}

CWarp::~CWarp()
{
	SAFE_DELETE(mpColliderMesh);
}

void CWarp::Update()
{
}

void CWarp::Render()
{
	mpModel->Render(Matrix());
}