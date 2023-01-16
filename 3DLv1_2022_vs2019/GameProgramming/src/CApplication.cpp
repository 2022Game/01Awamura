#include "CApplication.h"
#include "CRectangle.h"
//OpenGL
#include "glut.h"
#include "CVector.h"
#include "CTriangle.h"
#include "CTransform.h"
#include "CCollisionManager.h"

//�N���X��static�ϐ�
CTexture CApplication::mTexture;
CCharacterManager CApplication::mCharacterManager;

#define SOUND_BGM "res\\mario.wav" //BGM�����t�@�C��
#define SOUND_OVER "res\\mdai.wav" //�Q�[���I�[�o�[�����t�@�C��
//���f���f�[�^�̎w��
#define MODEL_OBJ "res\\f14.obj","res\\f14.mtl"
//�w�i���f���f�[�^�̎w��
#define MODEL_BACKGROUND "res\\sky.obj","res\\sky.mtl"
//�G�A���@���f��
#define MODEL_C5 "res\\c5.obj","res\\c5.mtl"

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

void CApplication::Start()
{
	spUi = new CUi(); //UI�N���X�̐���
	//C5���f���̓ǂݍ���
	mModelC5.Load(MODEL_C5);
	//�G�@�̃C���X�^���X�쐬
	new CEnemy(&mModelC5, CVector(0.0f, 10.0f, -100.0f),
		CVector(), CVector(0.1f, 0.1f, 0.1f));
	new CEnemy(&mModelC5, CVector(30.0f, 10.0f, -130.0f),
		CVector(), CVector(0.1f, 0.1f, 0.1f));
	mEye = CVector(1.0f, 2.0f, 3.0f);
	//���f���t�@�C���̓���
	mModel.Load(MODEL_OBJ);
	mBackGround.Load(MODEL_BACKGROUND);
	CMatrix matrix;
	matrix.Print();
//	mCharacter.Model(&mModel);
	//mCharacter.Scale(CVector(0.1f, 0.1f, 0.1f));
	mPlayer.Model(&mModel);
	mPlayer.Position(CVector(0.0f, 0.0f, -3.0f));
	mPlayer.Scale(CVector(0.1f, 0.1f, 0.1f));
	mPlayer.Rotation(CVector(-0.0f, -180.0f, -0.0f));
	//�r���{�[�h�̐���
	new CBillBoard(CVector(-6.0f, 3.0f, -10.0f), 1.0f, 1.0f);
	//�O�p�R���C�_�̊m�F
	//mColliderTriangle.Set(nullptr, nullptr
	//	, CVector(-50.0f, 0.0f, -50.0f)
	//	, CVector(-50.0f, 0.0f, 50.0f)
	//	, CVector(50.0f, 0.0f, -50.0f));
	////�O�p�R���C�_�Q
	//mColliderTriangle2.Set(nullptr, nullptr
	//	, CVector(50.0f, 0.0f, 50.0f)
	//	, CVector(50.0f, 0.0f, -50.0f)
	//	, CVector(-50.0f, 0.0f, 50.0f));
	//�w�i���f������O�p�R���C�_�𐶐�
	//�e�C���X�^���X�Ɛe�s��͂Ȃ�
	mColliderMesh.Set(nullptr, nullptr, &mBackGround);
}

void CApplication::Update()
{
	//�^�X�N�}�l�[�W���̍X�V
	CTaskManager::Instance()->Update();
	//���_�P,���_2,���_3,�@���̃f�[�^�̍쐬
	CVector v0, v1, v2, n;
	//�@����������Őݒ肷��
	n.Set(0.0f, 1.0f, 0.0f);
	//���_1�̍��W��ݒ肷��
	v0.Set(0.0f, 0.0f, 0.5f);
	//���_�Q�̍��W��ݒ肷��
	v1.Set(1.0f, 0.0f, 0.0f);
	//���_�R�̍��W��ݒ肷��
	v2.Set(0.0f, 0.0f, -0.5f);

	if (mInput.Key('J'))
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
	}

	//���_�̐ݒ�
	//gluLookAt(���_�w,���_�x,���_�y,���SX,���SY,���SZ,���X,���Y,���Z�j
	//gluLookAt(mEye.X(),mEye.Y(),mEye.Z(), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	//mCharacter.Update();
	//mCharacter.Render();
	//mPlayer.Update();
	//�J�����̃p�����[�^���쐬����
	CVector e,c,u;//���_�A�����_�A�����
	//���_�����߂�
	e = mPlayer.Position() + (CVector(-0.2f, 1.0f, -3.0f)) * mPlayer.MatrixRotate();
	//�����_�����߂�
	c = mPlayer.Position();
	//����������߂�
	u = (CVector(0.0f, 1.0f, 0.0f)) * mPlayer.MatrixRotate();
	//�J�����̐ݒ�
	gluLookAt(e.X(), e.Y(), e.Z(), c.X(), c.Y(), c.Z(), u.X(), u.Y(), u.Z());
	//���f���r���[�̍s��̎擾
	glGetFloatv(GL_MODELVIEW_MATRIX, mModelViewInverse.M());
	//�t�s��̎擾����
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
	mBackGround.Render();
	//�^�X�N���X�g�̍폜
	CTaskManager::Instance()->Delete();
	//�^�X�N�}�l�[�W���̕`��
	CTaskManager::Instance()->Render();
	//�q���W�����}�l�[�W���̏Փˏ���
	// �폜�@CCollisionManager::Instance()->Collision();
	CTaskManager::Instance()->Collision();
	//�R���R���}�l�}�l�`��
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