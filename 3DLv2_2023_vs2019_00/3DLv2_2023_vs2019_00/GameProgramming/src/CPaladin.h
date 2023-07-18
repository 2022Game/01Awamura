#ifndef CPALADIN_H
#define CPALADIN_H

#include "CXCharacter.h"
#include "CInput.h"

class CPaladin : public CXCharacter
{
public:
	CPaladin();
	//void Update();
private:
	static CModelX sModel;
	CInput mInput;
};

#endif