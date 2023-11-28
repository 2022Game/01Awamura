#include "CJMoveField.h"
#include "Maths.h"
#include "CCollider.h"
#include "CPlayer.h"

CJMoveField::CJMoveField(CModel* model, const CVector& pos, const CVector& scale, float rotateSpeedY)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
	, mRotateSpeedY(rotateSpeedY)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
}

CJMoveField::~CJMoveField()
{
	SAFE_DELETE(mpColliderMesh);
}

void CJMoveField::Update()
{
	////ˆÚ“®
	//mMoveSpeed = CVector(0.0f, 0.0f, 0.0f);

	//Position(Position() + mMoveSpeed);

	if (CPlayer::mSwitchRObject == true)
	{
		Rotate(0.0f, mRotateSpeedY, 0.0f);
	}
	if (CPlayer::mSwitchLObject == true)
	{
		Rotate(0.0f, -mRotateSpeedY, 0.0f);
	}
	else
	{
		Rotate(0.0f, 0.0f, 0.0f);
	}
}

void CJMoveField::Render()
{
	mpModel->Render(Matrix());
}