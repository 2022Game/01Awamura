#pragma once
#include "CFont.h"
/*
* CUi
* ���[�U�[�C���^�t�F�[�X�N���X
*/
class CUi
{
public:
	//�Q�[���N���A�\��
	void Clear();
	//�Q�[���I�[�o�[�\��
	void Over();
	//�X�^�[�g�\��
	void Start();
	//Enemy(�G�̐�)
	void Enemy(int enemy);
	CUi();
	void Hp(int hp);
	//Time(����)
	void Now(int now);
	void Now1(int now1);
	void Now2(int now2);
	void Now3(int now3);
	void Render();
private:
	int mEnemy;	//�G�̐�
	int mHp;
	int mNow;	//�o�ߎ���
	int mNow1;
	int mNow2;
	int mNow3;
	CFont mFont;
};
