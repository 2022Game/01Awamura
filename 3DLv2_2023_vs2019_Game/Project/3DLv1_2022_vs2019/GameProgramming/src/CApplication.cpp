#include "CApplication.h"
#include "CRectangle.h"
//OpenGL
#include "glut.h"
#include "CVector.h"
#include "CTriangle.h"
#include "CTransform.h"
#include "CCollisionManager.h"
#include "CCharacter.h"
#include "GamePause.h"
#include "CSceneManager.h"

//�N���X��static�ϐ�
CTexture CApplication::mTexture;
CCharacterManager CApplication::mCharacterManager;

//#define SOUND_BGM "res\\mario.wav" //BGM�����t�@�C��
//#define SOUND_OVER "res\\mdai.wav" //�Q�[���I�[�o�[�����t�@�C��
////�w�i���f���f�[�^�̎w��
//#define MODEL_BACKGROUND "res\\sky.obj","res\\sky.mtl"
////�G�A���@���f��
//#define MODEL_C5 "res\\f14.obj","res\\f14.mtl"
////�y��Coin
//#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"
////�n���}�[�����S
//#define MODEL_FHAMAH "res\\apple2.obj","res\\apple2.mtl"

//CTaskManager CApplication::mTaskManager;
//CTaskManager* CApplication::TaskManager()
//{
//	return &mTaskManager;
//}

CCharacterManager* CApplication::CharacterManager()
{
	return &mCharacterManager;
}

CTexture* CApplication::Texture()
{
	return &mTexture;
}

CMatrix CApplication::mModelViewInverse;

const CMatrix& CApplication::ModelViewInverse()
{
	return mModelViewInverse;
}

int CApplication::SelectStage = 0;

int CApplication::StageSwitch = 0;

int CApplication::StageGuard = 0;

int CApplication::StageCount = 0;

int CApplication::hcount = 0;

void CApplication::Start()
{
	CSceneManager::Instance()->LoadScene(EScene::eTitle);
	spUi = new CUi(); //UI�N���X�̐���
}

void CApplication::Update()
{
	if (CPlayer::CountLine == 1)
	{
		mColliderLine8.Set(nullptr, nullptr
			, CVector(0.0f, 24.0f, 30.0f)
			, CVector(24.0f, 24.0f, 30.0f));
		mColliderLine8.Layer(CCollider::ELayer::ELINEWALL);
		CPlayer::CountLine = 0;
	}

	if (CASoccer::hdhd == 2)
	{
		mpSoccerGimmick = new CASoccerGimmick();
	}
	/*switch (mState)
	{
	case EState::ECLEAR:
	{
		mpUi->Clear();
	}
	break;
	case EState::EOVER:
	{
		mpUi->Over();
	}
	break;
	}*/
	
	if (SelectStage != 0)
	{
		delete mpCoinGimmick;
		mpCoinGimmick = nullptr;
		delete mpHamahGimmick;
		delete mpWoodGimmick;
		delete mpWallGimmick;
		delete mpSoccerGimmick;
		mpSoccerGimmick = nullptr;
		mpWallGimmick = nullptr;
		mpHamahGimmick = nullptr;
		mpWoodGimmick = nullptr;
	}
	if (StageGuard == 1)
	{
		mpWallGimmick = new CAWallGimmick();
		StageGuard = 0;
	}
	if (SelectStage == 1)
	{
		//�����_���łP�Ȃ�n�}�[�X�e�[�W�\��
		mpClearStage = new CAClearStage();
		mpCoinGimmick = new CACoinGimmick();
		mpHamahGimmick = new CAHamahGimmick();
		SelectStage = 0; //�e�X�g�p
	}
	if (SelectStage == 2)
	{
		//�����_����2�Ȃ�E�b�h�X�e�[�W�\��
		mpClearStage = new CAClearStage();
		mpCoinGimmick = new CACoinGimmick();
		mpWoodGimmick = new CAWoodGimmick();
		hcount = 1;
		SelectStage = 0; //�e�X�g�p
	}
	if (SelectStage == 3)
	{
		//�����_���łP�Ȃ�n�}�[�X�e�[�W�\��
		mpClearStage = new CAClearStage();
		mpCoinGimmick = new CACoinGimmick();
		mpWoodGimmick = new CAWoodGimmick();
		hcount = 2;
		SelectStage = 0; //�e�X�g�p
	}
	if (SelectStage == 4)
	{
		//�����_���łP�Ȃ�n�}�[�X�e�[�W�\��
		mpClearStage = new CAClearStage();
		mpCoinGimmick = new CACoinGimmick();
		mpHamahGimmick = new CAHamahGimmick();
		SelectStage = 0; //�e�X�g�p
	}
	if (SelectStage == 5)
	{
		//�����_����5�Ȃ�X�e�[�W�\��
		mpClearStage = new CAClearStage();
		mpCoinGimmick = new CACoinGimmick();
		mpSoccerGimmick = new CASoccerGimmick();
		SelectStage = 0; //�e�X�g�p
	}

	//�^�X�N�}�l�[�W���̍X�V
	CTaskManager::Instance()->Update();
	CTaskManager::Instance()->Collision();

	//�V�[���}�l�[�W���[�̍X�V
	CSceneManager::Instance()->Update();
	//���f���r���[�̍s��̎擾
	glGetFloatv(GL_MODELVIEW_MATRIX, mModelViewInverse.M());
	//�t�s��̎擾
	mModelViewInverse = mModelViewInverse.Transpose();
	mModelViewInverse.M(0, 3, 0);
	mModelViewInverse.M(1, 3, 0);
	mModelViewInverse.M(2, 3, 0);
	//�^�X�N���X�g�̍폜
	CTaskManager::Instance()->Delete();
	//�^�X�N�}�l�[�W���̕`��
	CTaskManager::Instance()->Render();

	//�R���W�����}�l�W���[�`��
	CCollisionManager::Instance()->Render();
	spUi->Render(); //UI�̕`��
}

CUi* CApplication::spUi = nullptr;

CUi* CApplication::Ui()
{
	return spUi; //�C���X�^���X�̃|�C���^��Ԃ�
}

CApplication::~CApplication()
{
	delete spUi; //�C���X�^���XUi�̍폜
}