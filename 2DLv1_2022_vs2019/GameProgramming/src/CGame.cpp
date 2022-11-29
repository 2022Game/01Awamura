#include "CGame.h"
#include "CApplication.h"
#include "CBlock.h"
#include "CBlockk.h"
#include "CBlockkk.h"
#include "CPlayer2.h"
#include "CEnemy2.h"
#include "CPoint.h"
#include "CCamera.h"
#include "main.h"
#include "CYue.h"
#include "CYshita.h"
#include "CYmigi.h"
#include "CYhidari.h"
#include "CZkau.h"
#include "CZkas.h"
#include "CBlock1.h"
#include "CBlock2.h"
#include "CBlock3.h"
#include "CBlock4.h"
#include "CYZ.h"

void CGame::Start()
{
	//CameraSet();
	//�Q�[���̕`��
	CApplication::CharacterManager()->Render();
	//CCamera::End();
	//UI����
	mpUi->Hp(CPlayer2::Hp());
	mpUi->Now1(CYZ::Now1());
	//	mpUi->Enemy(CEnemy2::Num());
	mpUi->Render();
	mpUi->Start();

}

bool CGame::IsOver()
{	//HP��0�ȉ������茋�ʂ�߂�
	return CPlayer2::Hp() <= 0;
}

void CGame::Over()
{
	CameraSet();
	//�Q�[���̕`��
	CApplication::CharacterManager()->Render();
	CCamera::End();
	//UI����
	mpUi->Hp(CPlayer2::Hp());
	mpUi->Now1(CYZ::Now1());
	//	mpUi->Enemy(CEnemy2::Num());
	mpUi->Render();
	mpUi->Over();
}

CGame::~CGame()
{
	//�S�ẴC���X�^���X�폜
	CApplication::CharacterManager()->AllDelete();
	//UI�𐶐����Ă��鎞
	if (mpUi != nullptr)
	{	//UI���폜���A������
		delete mpUi;
		mpUi = nullptr;
	}
}

bool CGame::IsClear()
{
	return CZkabe::Now() >= 100;
}

void CGame::Clear()
{
	CameraSet();
	//�Q�[���̕`��
	CApplication::CharacterManager()->Render();
	CCamera::End();
	//UI����
	mpUi->Hp(CPlayer2::Hp());
	mpUi->Now1(CYZ::Now1());
	//	mpUi->Enemy(CEnemy2::Num());
	mpUi->Render();
	mpUi->Clear();
}

CGame::CGame()
	: mpUi(nullptr)
	, mNow(0)
	, mNow1(0)
	, mNow2(0)
	, mNow3(0)
	, mCdx(0)
	, mCdy(0)
{
	CZkabe::Now(0);
	CYZ::Now1(0);
	CYZ::Now2(0);
	CYZ::Now3(0);
	CEnemy2::Num(0);
	mpUi = new CUi();
	//�e�N�X�`���̓���
	CApplication::Texture()->Load(TEXTURE);
		CApplication::Texture2()->Load(UE);
		CApplication::Texture3()->Load(SHITA);
		CApplication::Texture4()->Load(MIGI);
		CApplication::Texture5()->Load(HIDARI);
		CApplication::Texture7()->Load(MARU);
		CApplication::Texture8()->Load(MARU1);
	//�萔�̒�`
	const int ROWS = 26; //�s��
	const int COLS = 26; //��
	//2�����z��̃}�b�v
	int map[ROWS][COLS] =
	{
		{10,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,10},
		{9,10,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,10,1},
		{9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
		{9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
		{9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
		{9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
		{9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
		{9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
		{9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
		{9,11,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,11,1},
		{9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
		{9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
		{9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
		{9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
		{9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
		{9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
		{9,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,1},
		{9,10,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,10,1},
		{10,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,10},
	};

	//�}�b�v�̍쐬
	//�s�����J��Ԃ�
	for (int row = 0; row < ROWS; row++)
	{
		//�񐔕��J��Ԃ�
		for (int col = 0; col < COLS; col++)
		{
			//1�̎��A�u���b�N����
			if (map[row][col] == 1)
			{
				//�u���b�N�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CBlock(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CApplication::Texture()));
			}
			//2�̎��A�v���C���[����
			if (map[row][col] == 2)
			{
				//�J�����p����
				mCdx = WINDOW_WIDTH / 2 - (TIPSIZE + TIPSIZE * 2 * col);
				mCdy = WINDOW_HEIGHT / 2 - (TIPSIZE + TIPSIZE * 2 * row);
				//�v���C���[�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					mpPlayer = new CPlayer2(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CApplication::Texture7()));
			}
			//3�̎��A�G����
			if (map[row][col] == 3)
			{
				//�G�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CEnemy2(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CApplication::Texture()));
			}
			//4�̎��A�܂�Ԃ��|�C���g�쐬
			if (map[row][col] == 4)
			{
				//�܂�Ԃ��|�C���g�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CPoint(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CCharacter::ETag::ETURN));
			}
			//5�̎��A�����ǉ�
			if (map[row][col] == 5)
			{
				//�u���b�N�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CYue(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CApplication::Texture2()));
			}
			if (map[row][col] == 6)
			{
				//�u���b�N�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CYshita(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CApplication::Texture3()));
			}
			if (map[row][col] == 7)
			{
				//�u���b�N�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CYmigi(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CApplication::Texture4()));
			}
			if (map[row][col] == 8)
			{
				//�u���b�N�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CYhidari(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CApplication::Texture5()));
			}
			if (map[row][col] == 9)
			{
				//�u���b�N�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CBlock1(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CApplication::Texture()));
			}
			if (map[row][col] == 10)
			{
				//�u���b�N�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CBlock2(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CApplication::Texture()));
			}
			if (map[row][col] == 11)
			{
				//�u���b�N�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CBlock3(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CApplication::Texture()));
			}
			if (map[row][col] == 12)
			{
				//�u���b�N�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CBlock4(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CApplication::Texture()));
			}
			if (map[row][col] == 13)
			{
				//�u���b�N�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CBlockk(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CApplication::Texture()));
			}
			if (map[row][col] == 14)
			{
				//�u���b�N�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CBlockkk(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CApplication::Texture()));
			}
		}
	}
}


void CGame::CameraSet()
{
	float x = mpPlayer->X() + mCdx;
	float y = mpPlayer->Y() + mCdy;
}

void CGame::Update()
{
	//�X�V�A�ՓˁA�폜�A�`��
	CApplication::CharacterManager()->Update();
	CApplication::CharacterManager()->Collision();
	CApplication::CharacterManager()->Delete();
	//CameraSet();
	CApplication::CharacterManager()->Render();
	//CCamera::End();
	//UI
	mpUi->Now1(CYZ::Now1());
	mpUi->Now2(CYZ::Now2());
	mpUi->Now3(CYZ::Now3());
	//mpUi->Now(CYZ::Now());
	mpUi->Now(CZkabe::Now());
	mpUi->Hp(CPlayer2::Hp());
	//	mpUi->Enemy(CEnemy2::Num());
	mpUi->Render();

}
