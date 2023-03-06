#include "Cmy.h"
#include <stdio.h>
#include "glut.h"


Cmy::Cmy()
{
}

void Cmy::Render()
{
	Render(mX, mY, mW, mH);
}

Cmy::~Cmy()
{
}

void Cmy::Render(float x, float y, float w, float h)
{
	glBegin(GL_QUADS);
	glVertex2f(x - w, y - h);
	glVertex2f(x + w, y - h);
	glVertex2f(x + w, y + h);
	glVertex2f(x - w, y + h);
	glEnd();
}

void Cmy::Set(float x, float y, float w, float h)
{
	mX = x;
	mY = y;
	mW = w;
	mH = h;
}

float Cmy::X()
{
	return mX;
}

float Cmy::Y()
{
	return mY;
}

float Cmy::W()
{
	return mW;
}

float Cmy::H()
{
	return mH;
}

void Cmy::Y(float y)
{
	mY = y;
}

void Cmy::X(float x)
{
	mX = x;
}

bool Cmy::Collision(Cmy* r)
{
	float distX = mX - r->mX;
	if (distX < 0.0f)
		distX = -distX;
	if (distX >= mW + r->mW)
		return false;
	float distY = mY - r->mY;
	if (distY < 0.0f)
		distY = -distY;
	if (distY >= mH + r->mH)
		return false;
	return true;
}

bool Cmy::Collision(Cmy* r, float* ax, float* ay)
{
	if (mX < r->mX)
		*ax = r->mX - mX - mW - r->mW;
	else
		*ax = mX - r->mX - mW - r->mW;
	//0ˆÈã‚ÍÕ“Ë‚µ‚È‚¢
	if (*ax >= 0.0f)
		return false;

	if (mY < r->mY)
		*ay = r->mY - mY - mH - r->mH;
	else
		*ay = mY - r->mY - mH - r->mH;
	//0ˆÈã‚ÍÕ“Ë‚µ‚È‚¢
	if (*ay >= 0.0f)
		return false;

	//Y‚ª’Z‚¢‚©”»’è
	if (*ax < *ay)
	{//YC³AX‚Í0
		*ax = 0.0f;
		//ã‚ÌŽž
		if (mY > r->mY)
			*ay = -*ay;
	}
	else
	{//XC³AY‚Í0
		*ay = 0.0f;
		//‰E‚ÌŽž
		if (mX > r->mX)
			*ax = -*ax;
	}
	return true;
}