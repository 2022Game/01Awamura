#include "CTMoveField.h"
#include "CCollider.h"
#include "CPlayer.h"
#include "Maths.h"

CTMoveField::CTMoveField(CModel* model, const CVector& pos, const CVector& scale ,float rotateSpeedY)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
	, mRotateSpeedY(rotateSpeedY)
	,randmodelspeedY(0.0f)
	, randmodelspeedY2(0.0f)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
	randmodelspeedY = Math::Rand(0.5f, 3.0f);

	randmodelspeedY2 = Math::Rand(0.5f, 3.0f);
}

CTMoveField::~CTMoveField()
{
	SAFE_DELETE(mpColliderMesh);
}

void CTMoveField::Update()
{
	if (CPlayer::mSwitchRObject == true)
	{
		//Rotate(0.0f, mRotateSpeedY, 0.0f);
		Rotate(0.0f, randmodelspeedY, 0.0f);
	}
	if (CPlayer::mSwitchLObject == true)
	{
		//Rotate(0.0f, -mRotateSpeedY, 0.0f);
		Rotate(0.0f, -randmodelspeedY2, 0.0f);
	}
	else
	{
		Rotate(0.0f, 0.0f, 0.0f);
	}
}

void CTMoveField::Render()
{
	mpModel->Render(Matrix());
}