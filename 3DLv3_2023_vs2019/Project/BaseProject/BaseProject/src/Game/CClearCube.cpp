#include "CClearCube.h"
#include "Maths.h"
#include "CCollider.h"

CClearCube::CClearCube(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpModel, true);

	Position(pos);
	Scale(scale);
}

CClearCube::~CClearCube()
{
	if (mpColliderMesh != nullptr)
	{
		delete mpColliderMesh;
		mpColliderMesh = nullptr;
	}
}

void CClearCube::Update()
{

}

void CClearCube::Render()
{
	mpModel->Render(Matrix());
}