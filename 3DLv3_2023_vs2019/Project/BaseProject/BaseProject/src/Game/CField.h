#pragma once
#include "CObjectBase.h"
#include "CModel.h"

class CField : public CObjectBase 
{
public:
	CField();
	~CField();

	void Update();
	void Render();

private:
	CModel* mpModel;
};