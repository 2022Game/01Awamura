#include "CMoveField.h"
#include "Maths.h"
#include "CCollider.h"
#include "CPlayer.h"
#include "Maths.h"

#define ROTATE_Y 0.1f

CMoveField::CMoveField(CModel* model, const CVector& pos, const CVector& scale, float rotateSpeedY)
	: mpModel(model)
	, mDefaultPos(pos)
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

CMoveField::~CMoveField()
{
	SAFE_DELETE(mpColliderMesh);
}

void CMoveField::Update()
{
	//ˆÚ“®
	mMoveSpeed = CVector(0.0f, 0.0f, 0.0f);

	Position(Position() + mMoveSpeed);

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

void CMoveField::Render()
{
	mpModel->Render(Matrix());
}