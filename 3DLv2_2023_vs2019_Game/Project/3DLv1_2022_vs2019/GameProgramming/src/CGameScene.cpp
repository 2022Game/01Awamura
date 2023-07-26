#include "CGameScene.h"
#include "CField.h"
#include "CPlayer.h"
#include "CSceneManager.h"
#include "CApplication.h"

////�w�i���f���f�[�^�̎w��
//#define MODEL_BACKGROUND "res\\sky.obj","res\\sky.mtl"
//
////�y��Coin
//#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"
//
////�n���}�[�����S
//#define MODEL_FHAMAH "res\\apple2.obj","res\\apple2.mtl"
//
////�`���̃{�[��
//#define MODEL_FSOCCER "res\\soccer1.obj","res\\soccer1.mtl"
//
////�_���Ȃ��
//#define MODEL_FWALL "res\\Wall2.obj","res\\Wall2.mtl"
//
////�`���̖�
//#define MODEL_FWOOD "res\\WWWW.obj","res\\WWWW.mtl"

//�R���X�g���N�^
CGameScene::CGameScene()
	:CSceneBase(EScene::eTitle)
	,mpWallGimmick(nullptr)
	,mpSoccerGimmick(nullptr)
	,mpCoinGimmick(nullptr)
	,mpClearStage(nullptr)
	,mpWoodGimmick(nullptr)
	,player(nullptr)
{

}

//�f�X�g���N�^
CGameScene::~CGameScene()
{
}

//�V�[���ǂݍ���
void CGameScene::Load()
{
	//�����Ń^�C�g����ʂɕK�v��
	//���\�[�X�̓ǂݍ��݂�N���X�̐������s��

	//�w�i����
	AddTask(new CField());
	/*if (CApplication::reset == 1)
	{
		if (player == nullptr)
		{
			delete player;
		}
	}*/
	////�v���C���[����
	//CApplication::Coin()->Load(MODEL_FCOIN);
	//CApplication::CleaCoin()->Load(MODEL_FCOIN);
	//CApplication::Wood()->Load(MODEL_FWOOD);
	//CApplication::Wall()->Load(MODEL_FWALL);
	//CApplication::Hamah()->Load(MODEL_FHAMAH);
	//CApplication::Soccer()->Load(MODEL_FSOCCER);
	player = new CPlayer();
	player->Position(CVector(10.0f, 1.0f, 0.0f));
	player->Scale(CVector(0.5f, 0.5f, 0.5f));
	player->Rotation(CVector(0.0f, 0.0f, 0.0f));
	AddTask(player);
	//// �R�C���M�~�b�N��CACoinGimmick���ɂ܂Ƃ߂�
	//mpCoinGimmick = new CACoinGimmick();

	////�����_����A�Ȃ�n�}�[���o���i�\��j
	//mpHamahGimmick = new CAHamahGimmick();

	////�O�p�R���C�_�̊m�F
	mColliderLine.Set(nullptr, nullptr
		, CVector(24.0f, 24.0f, -50.0f)
		, CVector(24.0f, 24.0f, 300.0f));
	mColliderLine.Layer(CCollider::ELayer::ELINEWALL);

	mColliderLine2.Set(nullptr, nullptr
		, CVector(0.0f, 24.0f, -50.0f)
		, CVector(0.0f, 24.0f, 300.0f));
	mColliderLine2.Layer(CCollider::ELayer::ELINEWALL);

	mColliderLine3.Set(nullptr, nullptr
		, CVector(24.0f, 22.5f, -50.0f)
		, CVector(24.0f, 22.5f, 300.0f));
	mColliderLine3.Layer(CCollider::ELayer::ELINEWALL);

	mColliderLine4.Set(nullptr, nullptr
		, CVector(0.0f, 22.5f, -50.0f)
		, CVector(0.0f, 22.5f, 300.0f));
	mColliderLine4.Layer(CCollider::ELayer::ELINEWALL);

	mColliderLine5.Set(nullptr, nullptr
		, CVector(24.0f, 25.5f, -50.0f)
		, CVector(24.0f, 25.5f, 300.0f));
	mColliderLine5.Layer(CCollider::ELayer::ELINEWALL);

	mColliderLine6.Set(nullptr, nullptr
		, CVector(0.0f, 25.5f, -50.0f)
		, CVector(0.0f, 25.5f, 300.0f));
	mColliderLine6.Layer(CCollider::ELayer::ELINEWALL);

	mColliderTriangle2.Set(nullptr, nullptr
		, CVector(-300.0f, 0.0f, -300.0f)
		, CVector(-300.0f, 0.0f, 300.0f)
		, CVector(300.0f, 0.0f, -300.0f));
	mColliderTriangle2.Layer(CCollider::ELayer::EDEATH);

	mColliderTriangle3.Set(nullptr, nullptr
		, CVector(300.0f, 0.0f, 300.0f)
		, CVector(300.0f, 0.0f, -300.0f)
		, CVector(-300.0f, 0.0f, 300.0f));
	mColliderTriangle3.Layer(CCollider::ELayer::EDEATH);
	mpClearStage = new CAClearStage();
	AddTask(mpClearStage);
}

//�V�[���̍X�V����
void CGameScene::Update()
{
	if (CApplication::StageReset == 1)
	{
		if (CApplication::StageCount == 0)
		{
			if (mpClearStage == nullptr)
			{
				mpClearStage = new CAClearStage();
				CApplication::StageDelete = 1;
			}
		}
	}
	if (CApplication::StageGuard == 1)
	{
		if (CApplication::StageDelete == 2)
		{
			if (mpClearStage != nullptr)
			{
				delete mpClearStage;
				mpClearStage = nullptr;
			}
		}
		CApplication::StageGuard = 0;
	}
	if (CApplication::StageClearDelete == 2)
	{
		if (mpClearStage != nullptr)
		{
			delete mpClearStage;
		}
		mpClearStage = nullptr;
	}
	//�v���C���[�����݂��Ȃ���΁A�������Ȃ�
	CPlayer* player = CPlayer::Instance();
	if (player == nullptr)return;

	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;//���_�A�����_�A�����
	//���_�����߂�
	e = player->Position() + (CVector(0.0f, 3.0f, -5.0f)) * player->MatrixRotate();
	//�����_�����߂�
	c = player->Position();
	//����������߂�
	u = (CVector(0.0f, 1.0f, 0.0f)) * player->MatrixRotate();
	//�J�����̐ݒ�
	gluLookAt(e.X(), e.Y(), e.Z(), c.X(), c.Y(), c.Z(), u.X(), u.Y(), u.Z());

	////�Q�[���I�[�o�[�V�[��
	//if (player->IsDeath())
	//{
	//	CSceneManager::Instance()->LoadScene(EScene::eTitle);
	//}

	//mColliderLine9 = nullptr;

	if (player->IsClear())
	{
		CSceneManager::Instance()->LoadScene(EScene::eClear);
	}
}