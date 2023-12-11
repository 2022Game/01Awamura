#include "CLMoveField.h"
#include "Maths.h"
#include "CCollider.h"
#include "CPlayer.h"

CLMoveField::CLMoveField(CModel* model, const CVector& pos, const CVector& scale, float rotateSpeedY)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
	, mRotateSpeedY(rotateSpeedY)
	, randmodelspeedY(0.0f)
	, randmodelspeedY2(0.0f)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
	randmodelspeedY = Math::Rand(0.5f, 3.0f);

	randmodelspeedY2 = Math::Rand(0.5f, 3.0f);
}

CLMoveField::~CLMoveField()
{
	SAFE_DELETE(mpColliderMesh);
}

void CLMoveField::Update()
{
	////ˆÚ“®
	//mMoveSpeed = CVector(0.0f, 0.0f, 0.0f);

	//Position(Position() + mMoveSpeed);

	if (CPlayer::mSwitchRObject == true)
	{
		Rotate(0.0f, randmodelspeedY, 0.0f);
	}
	if (CPlayer::mSwitchLObject == true)
	{
		Rotate(0.0f, -randmodelspeedY2, 0.0f);
	}
	else
	{
		Rotate(0.0f, 0.0f, 0.0f);
	}
}

void CLMoveField::Render()
{
	mpModel->Render(Matrix());
}