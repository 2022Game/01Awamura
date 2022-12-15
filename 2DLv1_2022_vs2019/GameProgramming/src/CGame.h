#pragma once
#include "CUi.h"
#include "CPlayer2.h"
#include "CCharacter.h"

//�萔�̒�`
#define TEXTURE "image.png" //�e�N�X�`���̃t�@�C����
#define YYAZIRUSI "0193_2.pig" //��󓧖�
#define UE "0193_6.png" //��
#define SHITA "0193_7.png" //��
#define MIGI "0193_9.png" //�E
#define HIDARI "0193_8.png" //��
#define MARU1 "maru1.png"
#define MARU2 "maru2.png"
#define MARU "maru.png"
#define TIPSIZE 16.0f //�}�b�v�v�f�̃T�C�Y
#define KABE "111.png"//��
#define SSUP "UP.png"
#define pengin  "1.phoeniikun_ichika.png"
#define pengin1 "2.phoeniikun_saki.png"
#define pengin2 "4.phoeniikun_honami.png"
#define pengin3 "3.phoeniikun_shiho.png"
/*
* CGame�N���X
* �Q�[���N���X
* �Q�[���̃}�b�v���쐬���A
* �L�����N�^��z�u����
*/
class CGame 
{
public:
	//�f�X�g���N�^
	~CGame();
	//�Q�[���N���A����
	bool IsClear();
	//�Q�[���N���A����
	void Clear();
	//�Q�[���I�[�o�[����
	bool IsOver();
	//�Q�[���I�[�o�[����
	void Over();
	//�X�^�[�g����
	void Start();
	CGame(); //�f�t�H���g�R���X�g���N�^�i���������j
	void Update(); //�X�V����
private:
	int mCdx, mCdy; //�J�����ƃv���C���[�̍��W�̍���
	void CameraSet(); //�J�����ݒ�
	CPlayer2* mpPlayer; //�v���C���[�̃|�C���^
	int mNow; //�o�ߎ���
	int mNow1;
	int mNow2;
	int mNow3;
	int mSpeed;
	CUi* mpUi; //UI�N���X�̃|�C���^
};
