#include "CXCharacter.h"
#include "CCollider.h"

#define MODEL_FILE2 "res\\knight\\knight_low.X" //“G

class CXEnemy :public CXCharacter {
public:
	CXEnemy();
	void Init(CModelX* model);
	//Õ“Ëˆ—
	void Collision(CCollider* m, CCollider* o);
private:
	//ƒRƒ‰ƒCƒ_‚ÌéŒ¾
	CCollider mColSphereBody; //‘Ì
	CCollider mColSphereHead; //“ª
	CCollider mColSphereSword0; //Œ•
	CCollider mColSphereSword1; //Œ•
	CCollider mColSphereSword2; //Œ•
};