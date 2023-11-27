#include "CSwitchObject.h"
#include "Maths.h"
#include "CCollider.h"

#define ROTATE_Y 0.1f

CSwitchObject::CSwitchObject(CModel* model, const CVector& pos, const CVector& scale, float rotateSpeedY)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
	, mRotateSpeedY(rotateSpeedY)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eMoveSwitch, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
}

CSwitchObject::~CSwitchObject()
{
	SAFE_DELETE(mpColliderMesh);
}

void CSwitchObject::Update()
{
	/*float per = mElapsedTime / mMoveTime;
	Position(mDefaultPos + mMoveVec * sinf(M_PI * 2.0f * per));

	mElapsedTime += 1.0f / 60.0f;
	if (mElapsedTime >= mMoveTime)
	{
		mElapsedTime -= mMoveTime;
	}*/

	//ˆÚ“®
	/*mMoveSpeed = CVector(0.0f, 0.01f, 0.0f);

	Position(Position() + mMoveSpeed);

	Rotate(0.0f, mRotateSpeedY, 0.0f);*/

	////U‚èqA‰ñ“]‚ÌˆÚ“®
	//float per = mElapsedTime / mRotateTime;
	//float angle = mRotateAngle * sinf(M_PI * 2.0f * per);
	//Rotation(CQuaternion(0.0f, 10.0f, 0));

	//mElapsedTime += Time::DeltaTime();
	//if (mElapsedTime >= mRotateTime)
	//{
	//	mElapsedTime -= mRotateTime;
	//}
}

void CSwitchObject::Render()
{
	mpModel->Render(Matrix());
}