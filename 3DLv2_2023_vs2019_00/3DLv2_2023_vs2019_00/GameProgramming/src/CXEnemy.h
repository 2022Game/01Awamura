#include "CXCharacter.h"
#include "CCollider.h"

#define MODEL_FILE2 "res\\knight\\knight_low.X" //�G

class CXEnemy :public CXCharacter {
public:
	CXEnemy();
	void Init(CModelX* model);
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);
private:
	//�R���C�_�̐錾
	CCollider mColSphereBody; //��
	CCollider mColSphereHead; //��
	CCollider mColSphereSword0; //��
	CCollider mColSphereSword1; //��
	CCollider mColSphereSword2; //��
};