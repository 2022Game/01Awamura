#ifndef CENEMY3_H
#define CENEMY3_H
#include "CXCharacter.h"
#include "Cinput.h"

class CXPlayer :public CXCharacter
{
public:
	void Update();
	CXPlayer();
private:
	int AnimaScene;
	int AttackFrame;
	int AnimaFrame;
	CInput mInput;
};

#endif