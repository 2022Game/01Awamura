#include "CVector.h"

//Set(X���W,Y���W,Z���W�j
void CVector::Set(float x, float y, float z)
{
	mX = x;
	mY = y;
	mZ = z;
}

float CVector::X()const
{
	return mX;
}

float CVector::Y()const
{
	return mY;
}

float CVector::Z()const
{
	return mZ;
}

CVector::CVector()
:mX(0.0f)
,mY(0.0f)
,mZ(0.0f)
{}

CVector::CVector(float v0, float v1, float v2)
	: mX(v0)
	, mY(v1)
	, mZ(v2)
{}