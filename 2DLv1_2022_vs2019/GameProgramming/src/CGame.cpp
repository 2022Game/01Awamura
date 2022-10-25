#include "CGame.h"
#include "CApplication.h"
#include "CBlock.h"
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

void CGame::Start()
{
	//CameraSet();
	//�Q�[���̕`��
	CApplication::CharacterManager()->Render();
	//CCamera::End();
	//UI����
	mpUi->Hp(CPlayer2::Hp());
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
	return CEnemy2::Num() >= 3;
}

void CGame::Clear()
{
	CameraSet();
	//�Q�[���̕`��
	CApplication::CharacterManager()->Render();
	CCamera::End();
	//UI����
	mpUi->Hp(CPlayer2::Hp());
	//	mpUi->Enemy(CEnemy2::Num());
	mpUi->Render();
	mpUi->Clear();
}

CGame::CGame()
	: mpUi(nullptr)
	, mTime(0)
	, mCdx(0)
	, mCdy(0)
{
	CEnemy2::Num(0);
	mpUi = new CUi();
	//�e�N�X�`���̓���
	CApplication::Texture()->Load(TEXTURE);
		CApplication::Texture2()->Load(UE);
		CApplication::Texture3()->Load(SHITA);
		CApplication::Texture4()->Load(MIGI);
		CApplication::Texture5()->Load(HIDARI);
	//�萔�̒�`
	const int ROWS = 20; //�s��
	const int COLS = 25; //��
	//2�����z��̃}�b�v
	int map[ROWS][COLS] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{9,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1},
		{9,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1},
		{9,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1},
		{9,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1},
		{9,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1},
		{9,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1},
		{9,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1},
		{9,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1},
		{9,7,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,8,1},
		{9,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1},
		{9,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1},
		{9,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1},
		{9,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1},
		{9,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1},
		{9,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1},
		{9,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1},
		{9,1,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,1,1},
		{1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1},
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
						TIPSIZE, TIPSIZE, CApplication::Texture()));
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
	mpUi->Time(0);
	mpUi->Hp(CPlayer2::Hp());
	//	mpUi->Enemy(CEnemy2::Num());
	mpUi->Render();

}
