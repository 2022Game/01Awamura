//#ifndef CAACLEATESTAGE_H
//#define CAACLEATESTAGE_H
//
//#include "CTask.h"
//#include "CACoinClearStage.h"
//#include "CCollider.h"
//#include "CColliderMesh.h"
//#include "CColliderTriangle.h"
//#include "CColliderLine.h"
//#include "CACoin.h"
//#include "CAHamah.h"
//#include "CASoccer.h"
//#include "CAWood.h"
//#include "CAWall.h"
//
//class CAAcleateStage : public CTask
//{
//private:
//	CColliderLine mColliderLine7;
//	CColliderLine mColliderLine8;
//	CColliderLine mColliderLine9;
//	std::vector<CASoccer*> mSoccers;	// Soccer�̃��X�g
//	CModel* mpSoccerModel;			// Soccer�̃��f���f�[�^
//	std::vector<CAHamah*> mHamahs;	// �n�}�[�̃��X�g
//	CModel* mpHamahModel;			// �n�}�[�̃��f���f�[�^
//	std::vector<CACoin*> mCoins;	// �R�C���̃��X�g
//	CModel* mpCoinModel;			// �R�C���̃��f���f�[�^
//	std::vector<CAWall*> mWalls;	// �ǂ̃��X�g
//	CModel* mpWallModel;			//�@�ǂ̃��f���f�[�^
//	std::vector<CAWood*> mWoods;	// �؂̃��X�g
//	CModel* mpWoodModel;			// �؂̃��f���f�[�^
//	std::vector<CACoinClearStage*> mClearStages;	// �R�C���̃��X�g
//	CModel* mpClearStageModel;			// �R�C���̃��f���f�[�^
//	int randnow;
//	int randnow2;
//	int randnow3;
//	int randnow4;
//	int randnow5;
//	int randnow6;
//	int randnow7;
//	int randnow8;
//	int randnow9;
//	int randnow10;
//
//	// ����������
//	void Init();
//	// Soccer�𐶐����ă��X�g�ɒǉ�
//	void CreateSoccer(CVector& pos, CVector& rot, CVector& scale);
//	// �R�C���𐶐����ă��X�g�ɒǉ�
//	void CreateCoin(CVector& pos, CVector& rot, CVector& scale);
//	// �n�}�[�𐶐����ă��X�g�ɒǉ�
//	void CreateHamah(CVector& pos, CVector& rot, CVector& scale);
//	// �n�}�[�𐶐����ă��X�g�ɒǉ�
//	void CreateWall(CVector& pos, CVector& rot, CVector& scale);
//	// �R�C���𐶐����ă��X�g�ɒǉ�
//	void ClearStage(CVector& pos, CVector& rot, CVector& scale);
//	// �n�}�[�𐶐����ă��X�g�ɒǉ�
//	void CreateWood(CVector& pos, CVector& rot, CVector& scale);
//
//public:
//	CAAcleateStage();
//	~CAAcleateStage();
//
//	// �X�V����
//	void Update();
//};
//
//#endif