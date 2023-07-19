#ifndef CCHARACTER3_H
#define CCHARACTER3_H
//�ϊ��s��N���X�̃C���N���[�h
#include "CTransform.h"
//���f���N���X�̃C���N���[�h
#include "CModel.h"
#include "CTask.h"
/*
�L�����N�^�[�N���X
�Q�[���L�����N�^�̊�{�I�ȋ@�\���`����
*/
//�R���C�_�N���X�̐錾
class CCollider;
class CCharacter3 : public CTransform, public CTask {
public:
	enum class ETag
	{
		EZERO, //�����l
		EPLAYER, //�v���C���[
		EENEMY, //�G
		EBULLETPLAYER, //�v���C���[�e
		EBULLETENEMY, //�G�e
		ECOIN,
		ECOINEND,

		EOBSTACLE,//��Q��
		ESTAGEGUARD,//�X�e�[�W�Ǘ�
		ESTAGECLEAR,//�X�e�[�W�Ǘ��Q
	};
	//enum class EState	//���
	//{
	//	ENULL,
	//	EOVER,
	//	ECLERE,
	//	EMOVE,	//�ړ�
	//	ESTOP,	//��~
	//	EJUMP,	//�W�����v
	//	ECRY,	//����
	//	EJO,    //�W�����vOK
	//};
	//�^�O�̎擾
	ETag Tag();
	//�Փˏ���
	virtual void Collision(CCollider* m, CCollider* o) {}
	//�f�X�g���N�^
	~CCharacter3();
	//�R���X�g���N�^
	CCharacter3();
	//�R���X�g���N�^
	CCharacter3(int priority);
	//���f���̐ݒ�
	//Model�i���f���N���X�̃|�C���^�j
	void Model(CModel* m);
	//�`�揈��
	void Render();
	//�L�����N�^�[�폜
	void Kill();
	//�L�����N�^�[������ł邩�ǂ���
	bool IsDeath() const;
	//�L�����N�^�[���N���A�������ǂ���
	bool IsClear() const;
protected:
	int mHp;
	CModel* mpModel; //���f���̃|�C���^
	ETag mTag; //�^�O
};

#endif