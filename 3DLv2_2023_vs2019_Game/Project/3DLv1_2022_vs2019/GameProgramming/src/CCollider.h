#ifndef CCOLLIDER_H
#define CCOLLIDER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"
class CCollisionManager;
/*
�R���C�_�N���X
�Փ˔���f�[�^
*/
class CCollider : public CTransform,public CTask {
	friend CCollisionManager;
public:
	//�D��x�̕ύX
	virtual void ChangePriority();
	//�D��x�̕ύX
	void ChangePriority(int priority);
	//�R���C�_�^�C�v
	enum class EType {
		ESPHERE,//���R���C�_
		ETRIANGLE,//�O�p�R���C�_
		ELINE, //�����R���C�_
	};

	//�R���C�_�̃��C���[
	enum class ELayer
	{
		EDEFAULT,
		EWOOD, //�؂̃I�u�W�F�N�g�̃R���C�_
		ESOCCER, //Soccer�̃I�u�W�F�N�g�̃R���C�_
		EWALL,
		EDEATH, //���S
		ECOIN, //�R�C���̃R���C�_
		ELINEWALL, //�����̕ǃR���C�_
	};

	EType Type() const;
	//�R���C�_�̃��C���[���擾
	ELayer Layer() const;
	//�R���C�_�̃��C���[��ݒ�
	void Layer(ELayer layer);

	CCharacter3::ETag Tag() const;

	//CollisionTriangleLine(�O�p�R���C�_, �����R���C�_, �����l)
	//retrun:true�i�Փ˂��Ă���jfalse(�Փ˂��Ă��Ȃ�)
	//�����l:�Փ˂��Ȃ��ʒu�܂Ŗ߂��l
	static bool CollisionTriangleLine(CCollider* triangle, CCollider* line, CVector* adjust);
	//CollisionTriangleSphere(�O�p�R���C�_, ���R���C�_, �����l)
	//retrun:true�i�Փ˂��Ă���jfalse(�Փ˂��Ă��Ȃ�)
	//�����l:�Փ˂��Ȃ��ʒu�܂Ŗ߂��l
	static bool CollisionTriangleSphere(CCollider* triangle, CCollider* sphere, CVector* adjust);
	//CollisionSphere(���R���C�_, ���R���C�_, �����l)
	//retrun:true�i�Փ˂��Ă���jfalse(�Փ˂��Ă��Ȃ�)
	//�����l:�Փ˂��Ȃ��ʒu�܂Ŗ߂��l
	static bool CollisionSphere(CCollider* sphere1, CCollider* sphere2, CVector* adjust);
	//CollisionSphereLine(���R���C�_, �����R���C�_, �����l)
	//retrun:true�i�Փ˂��Ă���jfalse(�Փ˂��Ă��Ȃ�)
	//�����l:�Փ˂��Ȃ��ʒu�܂Ŗ߂��l
	static bool CollisionSphereLine(CCollider* sphere, CCollider* line, CVector* adjust);
	//CollisionLine(�����R���C�_, �����R���C�_, �����l)
	//�i�����I�ɂ̓J�v�Z���ƃJ�v�Z���̏Փ˔�����s���Ă���)
	//retrun:true�i�Փ˂��Ă���jfalse(�Փ˂��Ă��Ȃ�)
	//�����l:�Փ˂��Ȃ��ʒu�܂Ŗ߂��l
	static bool CollisionLine(CCollider* line1, CCollider* line2, CVector* adjust);

	static float CalcDistancePointToLine(const CVector& point, const CVector& lineS, const CVector& lineE, CVector* nearest = nullptr);

	//�Փ˔���
	//�i�R���C�_�̎�ނɂ���Ď����ŏՓ˔����؂�ւ���j
	//Collision(�R���C�_1, �R���C�_2)
	//retrun:true�i�Փ˂��Ă���jfalse(�Փ˂��Ă��Ȃ�)
	static bool Collision(CCollider* m, CCollider* o);
	//�Փ˔��� �����l�L���
	//�i�R���C�_�̎�ނɂ���Ď����ŏՓ˔����؂�ւ���j
	//Collision(�R���C�_1, �R���C�_2, �����l)
	//retrun:true�i�Փ˂��Ă���jfalse(�Փ˂��Ă��Ȃ�)
	static bool Collision(CCollider* m, CCollider* o, CVector* adjust);

	//�f�t�H���g�R���X�g���N�^
	CCollider();

	~CCollider();
	//�R���X�g���N�^
	//CCollider(�e, �e�s��, �ʒu, ���a)
	CCollider(CCharacter3* parent, const CMatrix* matrix,
		const CVector& position, float radius);
	//�e�|�C���^�̎擾
	CCharacter3* Parent();
	//�`��
	void Render();
protected:
	EType mType;//�R���C�_�^�C�v
	ELayer mLayer; //�R���C�_�̃��C���[
	//���_
	CVector mV[3];

	CCharacter3* mpParent;//�e
	const CMatrix* mpMatrix;//�e�s��
	float mRadius;	//���a
};
#endif
