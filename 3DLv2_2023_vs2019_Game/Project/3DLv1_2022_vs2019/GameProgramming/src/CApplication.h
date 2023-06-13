#pragma once
#include "CRectangle.h"
#include "CTexture.h"
#include "CCharacter.h"
#include "CBullet.h"
#include "CEnemy.h"
#include "CEnemy3.h"
#include "CPlayer.h"
#include "CAClearStage.h"
#include "CACoinClearStage.h"
#include "CACoin.h"
#include "CACoinGimmick.h"
#include "CAHamah.h"
#include "CAHamahGimmick.h"
#include "CAWall.h"
#include "CAWallGimmick.h"
#include "CInput.h"
#include "CFont.h"
#include "CMiss.h"
#include <vector>
#include "CCharacterManager.h"

#include "CGame.h"
#include "CSound.h"
#include "CVector.h"
#include "CModel.h"
#include "CMatrix.h"
#include "CCharacter3.h"
#include "CTaskManager.h"
#include "CBillBoard.h"
#include "CColliderTriangle.h"
#include "CColliderMesh.h"

class CApplication
{
private:
	static CUi* spUi; //UI�N���X�̃|�C���^
	//���f���r���[�̋t�s��
	static CMatrix mModelViewInverse;
	//static CTaskManager mTaskManager;
	CSound mSoundBgm;	//BGM
	CSound mSoundOver;	//�Q�[���I�[�o�[
	CGame* mpGame;
	static CCharacterManager mCharacterManager;
	enum class EState
	{
		ESTART,	//�Q�[���J�n
		EPLAY,	//�Q�[����
		ECLEAR,	//�Q�[���N���A
		EOVER,	//�Q�[���I�[�o�[
	};
	EState mState;
	//	CCharacter mRectangle;
	CPlayer* mpPlayer;
	static CTexture mTexture;
	CEnemy* mpEnemy;
	CBillBoard* mpBillBoard;
	//	CBullet* mpBullet;
	CInput mInput;
	CFont mFont;
	CMiss* mpMiss;
	CVector mEye;
	CMatrix mMatrix;
	//CCharacter3 mCharacter;
	CPlayer mPlayer;
	CACoin* mpCoin;
	//CAHamah* mpHamah;
	//���f���C���X�^�N���X�̍쐬
	CModel mModel;
	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;//���_�A�����_�A�����
	//CCharacter�̃|�C���^�̉ϒ��z��
//	std::vector<CCharacter*> mCharacters;
	CModel mBackGround; //�w�i���f��
	//C5���f��
	CModel mModelC5;
	//Coin���f��
	CModel mModelCoin;
	//Hamah���f��
	CModel mModelHamah;
	CModel mModelWall;
	//���f������R���C�_�𐶐�
	CColliderMesh mColliderMesh;

	CAClearStage* mpClearStage;
	CACoinGimmick* mpCoinGimmick;
	CAHamahGimmick* mpHamahGimmick;
	CAWallGimmick* mpWallGimmick;
//	CACClearStage* mpCoinClearStage;
public:
	~CApplication();
	int Init();
	static int SelectStage;
	static int StageSwitch;
	static int StageGuard;
	static int StageCount;
	static CUi* Ui();
	//���f���r���[�s��̎擾
	static const CMatrix& ModelViewInverse();
	//static CTaskManager* TaskManager();
	static CCharacterManager* CharacterManager();
	static CTexture* Texture();
	//�ŏ��Ɉ�x�������s����v���O����
	void Start();
	//�J��Ԃ����s����v���O����
	void Update();
};