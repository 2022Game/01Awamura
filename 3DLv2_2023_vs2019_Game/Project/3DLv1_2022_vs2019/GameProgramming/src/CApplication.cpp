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
	//SelectStage = 0;
	/*new CEnemy3(CVector(-5.0f, 1.0f, -10.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));
	new CEnemy3(CVector(5.0f, 1.0f, -10.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));*/
	spUi = new CUi(); //UI�N���X�̐���
	//C5���f���̓ǂݍ���
	//mModelC5.Load(MODEL_C5);
	//�G�@�̃C���X�^���X�쐬
	/*new CEnemy(&mModelC5, CVector(0.0f, 10.0f, -100.0f),
		CVector(), CVector(0.1f, 0.1f, 0.1f));
	new CEnemy(&mModelC5, CVector(30.0f, 10.0f, -130.0f),
		CVector(), CVector(0.1f, 0.1f, 0.1f));*/
	//mEye = CVector(1.0f, 2.0f, 3.0f);
	//���f���t�@�C���̓���
	//mModel.Load(MODEL_OBJ);
	//mBackGround.Load(MODEL_BACKGROUND);
	////mModelCoin.Load(MODEL_FCOIN);
	//mModelHamah.Load(MODEL_FHAMAH);
	///*CMatrix matrix;
	//matrix.Print();*/

	////// �R�C���M�~�b�N��CACoinGimmick���ɂ܂Ƃ߂�
	////mpCoinGimmick = new CACoinGimmick();

	//////�����_����A�Ȃ�n�}�[���o���i�\��j
	////mpHamahGimmick = new CAHamahGimmick();

	////�����_����B�Ȃ�ړ������o���B
	//
	////	mCharacter.Model(&mModel);
	//	//mCharacter.Scale(CVector(0.1f, 0.1f, 0.1f));
	////�r���{�[�h�̐���
	///*new CBillBoard(CVector(-6.0f, 3.0f, -10.0f), 1.0f, 1.0f);*/
	//////�O�p�R���C�_�̊m�F
	//mColliderLine.Set(nullptr, nullptr
	//	, CVector(24.0f, 24.0f, -50.0f)
	//	, CVector(24.0f, 24.0f, 300.0f));
	//mColliderLine.Layer(CCollider::ELayer::ELINEWALL);

	//mColliderLine2.Set(nullptr, nullptr
	//	, CVector(0.0f, 24.0f, -50.0f)
	//	, CVector(0.0f, 24.0f, 300.0f));
	//mColliderLine2.Layer(CCollider::ELayer::ELINEWALL);

	//mColliderLine3.Set(nullptr, nullptr
	//	, CVector(24.0f, 22.5f, -50.0f)
	//	, CVector(24.0f, 22.5f, 300.0f));
	//mColliderLine3.Layer(CCollider::ELayer::ELINEWALL);

	//mColliderLine4.Set(nullptr, nullptr
	//	, CVector(0.0f, 22.5f, -50.0f)
	//	, CVector(0.0f, 22.5f, 300.0f));
	//mColliderLine4.Layer(CCollider::ELayer::ELINEWALL);

	//mColliderLine5.Set(nullptr, nullptr
	//	, CVector(24.0f, 25.5f, -50.0f)
	//	, CVector(24.0f, 25.5f, 300.0f));
	//mColliderLine5.Layer(CCollider::ELayer::ELINEWALL);

	//mColliderLine6.Set(nullptr, nullptr
	//	, CVector(0.0f, 25.5f, -50.0f)
	//	, CVector(0.0f, 25.5f, 300.0f));
	//mColliderLine6.Layer(CCollider::ELayer::ELINEWALL);

	//mColliderLine7.Set(nullptr, nullptr
	//	, CVector(0.0f, 24.0f, -10.0f)
	//	, CVector(24.0f, 24.0f,-10.0f));
	//mColliderLine7.Layer(CCollider::ELayer::ELINEWALL);

	///*mColliderLine8.Set(nullptr, nullptr
	//	, CVector(0.0f, 28.5f, -10.0f)
	//	, CVector(0.0f, 28.5f, 10.0f));
	//mColliderLine8.Layer(CCollider::ELayer::ELINEWALL);*/
	////mColliderLine9.Set(nullptr, nullptr
	////	, CVector(24.0f, 23.5f, -50.0f)
	////	, CVector(24.0f, 23.5f, 300.0f));
	////mColliderLine9.Layer(CCollider::ELayer::ELINEWALL);

	////mColliderLine10.Set(nullptr, nullptr
	////	, CVector(0.0f, 23.5f, -50.0f)
	////	, CVector(0.0f, 23.5f, 300.0f));
	////mColliderLine10.Layer(CCollider::ELayer::ELINEWALL);*/

	//mColliderTriangle2.Set(nullptr, nullptr
	//	, CVector(-300.0f, 0.0f, -300.0f)
	//	, CVector(-300.0f, 0.0f, 300.0f)
	//	, CVector(300.0f, 0.0f, -300.0f));
	//mColliderTriangle2.Layer(CCollider::ELayer::EDEATH); 

	//mColliderTriangle3.Set(nullptr, nullptr
	//	, CVector(300.0f, 0.0f, 300.0f)
	//	, CVector(300.0f, 0.0f, -300.0f)
	//	, CVector(-300.0f, 0.0f, 300.0f));
	//mColliderTriangle3.Layer(CCollider::ELayer::EDEATH);
	////�w�i���f������O�p�R���C�_�𐶐�
	////�e�C���X�^���X�Ɛe�s��͂Ȃ�
	//mColliderMesh.Set(nullptr, nullptr, &mBackGround);
	////mColliderMesh.Set(nullptr, nullptr, &mModelCoin);
	////mpCoinGimmick = new CACoinGimmick();
	//mpClearStage = new CAClearStage();
	////mpHamahGimmick = new CAHamahGimmick();
	////mpClearStage = new CAClearStage();
	//mpPlayer = new CPlayer();
	//mpPlayer->Model(&mModel);
	//mpPlayer->Position(CVector(10.0f, 1.0f, 0.0f));
	//mpPlayer->Scale(CVector(0.5f, 0.5f, 0.5f));
	//mpPlayer->Rotation(CVector(0.0f, 0.0f, 0.0f));
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
	//if (SelectStage != 3 && SelectStage != 0)
	//{
	//	delete mpCoinGimmick;
	//	mpCoinGimmick = nullptr;
	//	/*delete mpHamahGimmick;
	//	mpHamahGimmick = nullptr;*/
	//}
	//�^�X�N�}�l�[�W���̍X�V
	CTaskManager::Instance()->Update();
	CTaskManager::Instance()->Collision();
	////���_�P,���_2,���_3,�@���̃f�[�^�̍쐬
	//CVector v0, v1, v2, n;
	////�@����������Őݒ肷��
	//n.Set(0.0f, 1.0f, 0.0f);
	////���_1�̍��W��ݒ肷��
	//v0.Set(0.0f, 0.0f, 0.5f);
	////���_�Q�̍��W��ݒ肷��
	//v1.Set(1.0f, 0.0f, 0.0f);
	////���_�R�̍��W��ݒ肷��
	//v2.Set(0.0f, 0.0f, -0.5f);

	/*if (mInput.Key('J'))
	{
		mEye = mEye - CVector(0.1f, 0.0f, 0.0f);
	}
	if (mInput.Key('L'))
	{
		mEye = mEye + CVector(0.1f, 0.0f, 0.0f);
	}
	if (mInput.Key('I'))
	{
		mEye = mEye - CVector(0.0f, 0.0f, 0.1f);
	}
	if (mInput.Key('K'))
	{
		mEye = mEye + CVector(0.0f, 0.0f, 0.1f);
	}
	if (mInput.Key('O'))
	{
		mEye = mEye + CVector(0.0f, 1.0f, 0.0f);
	}
	if (mInput.Key('M'))
	{
		mEye = mEye - CVector(0.0f, 1.0f, 0.0f);
	}*/

	//���_�̐ݒ�
	//gluLookAt(���_�w,���_�x,���_�y,���SX,���SY,���SZ,���X,���Y,���Z�j
	//gluLookAt(mEye.X(),mEye.Y(),mEye.Z(), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	//mCharacter.Update();
	//mCharacter.Render();
	//mPlayer.Update();
	////�J�����̃p�����[�^���쐬����
	//CVector e, c, u;//���_�A�����_�A�����
	////���_�����߂�
	//e = mpPlayer->Position() + (CVector(-0.2f, 1.0f, -3.0f)) * mpPlayer->MatrixRotate();
	////�����_�����߂�
	//c = mpPlayer->Position();
	////����������߂�
	//u = (CVector(0.0f, 1.0f, 0.0f)) * mpPlayer->MatrixRotate();
	////�J�����̐ݒ�
	//gluLookAt(e.X(), e.Y(), e.Z(), c.X(), c.Y(), c.Z(), u.X(), u.Y(), u.Z());
	//�V�[���}�l�[�W���[�̍X�V
	CSceneManager::Instance()->Update();
	//���f���r���[�̍s��̎擾
	glGetFloatv(GL_MODELVIEW_MATRIX, mModelViewInverse.M());
	//�t�s��̎擾
	mModelViewInverse = mModelViewInverse.Transpose();
	mModelViewInverse.M(0, 3, 0);
	mModelViewInverse.M(1, 3, 0);
	mModelViewInverse.M(2, 3, 0);
	//mPlayer.Render(); 
	//CTransform trans; //�ϊ��s��C���X�^���X�̍쐬
	//trans.Position(CVector(0.5f, 1.8f, 0.5f)); //�ʒu�̍쐬
	//trans.Rotation(CVector(-10.0f, -20.0f, -30.0f)); //��]�̐ݒ�
	//trans.Scale(CVector(0.1f, 0.1f, 0.1f)); //�g��k���̐ݒ�
	//trans.Update(); //�s��̍X�V
	//mModel.Render(trans.Matrix());//���f���̕`��
	//mBackGround.Render();
	//�^�X�N���X�g�̍폜
	CTaskManager::Instance()->Delete();
	//�^�X�N�}�l�[�W���̕`��
	CTaskManager::Instance()->Render();
	//�q���W�����}�l�[�W���̏Փˏ���
	// �폜�@CCollisionManager::Instance()->Collision();

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