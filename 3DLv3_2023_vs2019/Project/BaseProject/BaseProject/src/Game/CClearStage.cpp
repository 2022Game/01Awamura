#include "CClearStage.h"
#include "Maths.h"
#include "CCollider.h"

CClearStage::CClearStage(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpModel,true);

	Position(pos);
	Scale(scale);
}

CClearStage::~CClearStage()
{
	if (mpColliderMesh != nullptr)
	{
		delete mpColliderMesh;
		mpColliderMesh = nullptr;
	}
}

void CClearStage::Update()
{
}

void CClearStage::Render()
{
	mpModel->Render(Matrix());
}