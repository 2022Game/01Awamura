#include <stdio.h>
#include <string.h>
#include "CModelX.h"
#include "glut.h"
#include <ctype.h>
#include "CMatrix.h"
#include "CVertex.h"
#include "CMaterial.h"
/*
*IsDelimiter(c)
* c��\t\r\n�X�y�[�X�Ȃǂ̋󔒕���
* �܂���,:�Ȃǂ̕����ł����
* ��؂蕶���Ƃ���true��Ԃ�
*/
bool CModelX::IsDelimiter(char c)
{
	//isspace(c)
	//c���󔒕����Ȃ�O�ȊO��Ԃ�
	if (isspace(c) != 0)
		return true;
	/*
	strchr(������A�����j
	������ɕ������܂܂�Ă���΁A
	�������������ւ̃|�C���^��Ԃ�
	������Ȃ�������NULL��Ԃ�
	*/
	if (strchr(",;\"", c) != NULL)
		return true;
	//��؂蕶���ł͂Ȃ�
	return false;
}

/*
GetToken
������f�[�^����A�P����P�擾����
*/
char* CModelX::GetToken() {
	char* p = mpPointer;
	char* q = mToken;
	//�^�u(\t)��()���s(\r)(\n),:"�̋�؂蕶���ȊO�ɂȂ�܂œǂݔ�΂�
	while (*p != '\0' && IsDelimiter(*p))p++;
	if(*p == '{'|| *p == '}'){
		//{�܂���}�Ȃ�mToken�ɑ�������̕�����
		*q++ = *p++;
	}
	else {
		//�^�u(\t)�󔒁i�j���s(\r)(\n),�G"�̋�؂蕶���A
		//�܂��́A�p�̕����ɂȂ�܂ł�Token�ɑ������
		while (*p != '\0' && !IsDelimiter(*p) && *p != '}')
			*q++ = *p++;
	}
	*q = '\0'; //mToken�̍Ō��\0����
	mpPointer = p; //���̓ǂݍ��ރ|�C���g���X�V����

	//����mToken��//�̏ꍇ��,�R�����g�Ȃ̂ŉ��s�܂œǂݔ�΂�
	/*
	strcmp(������P�A������Q�j
	������P�ƕ�����Q���������ꍇ�A�O��Ԃ��܂��B
	������P�ƕ�����Q���������Ȃ��ꍇ�A�O�ȊO��Ԃ��܂��B
	*/
	if (!strcmp("//", mToken)) {
		//���s�܂œǂݔ�΂�
		while (*p != '\0' && !strchr("\r\n", *p))p++;
		//�ǂݍ��݈ʒu�̍X�V
		mpPointer = p;
		//�P����擾����(�ċA�Ăяo���j
		return GetToken();
	}
	return mToken;
}

CModelX::CModelX()
	:mpPointer(nullptr)
{
	//mToken��������
	memset(mToken, 0, sizeof(mToken));
}

CModelX::~CModelX()
{
	if (mFrame.size() > 0)
	{
		delete mFrame[0];
	}
	for (size_t i = 0; i < mAnimationSet.size(); i++)
	{
		delete mAnimationSet[i];
	}
}

CModelXFrame::~CModelXFrame()
{
	//�q�t���[����S�ĉ������
	std::vector<CModelXFrame*>::iterator itr;
	for (itr = mChild.begin(); itr != mChild.end(); itr++) {
		delete* itr;
	}
	//���O�̃G���A���������
	SAFE_DELETE_ARRAY(mpName);
}

void CAnimationSet::Time(float time)
{
	mTime = time;
}
void CAnimationSet::Weight(float weight)
{
	mWeight = weight;
}

void CAnimationSet::AnimateMatrix(CModelX* model)
{
	//�d�݂��O�͔�΂�
	if (mWeight == 0)return;
	//�t���[����(Animation���j���J��Ԃ�
	for (size_t j = 0; j < mAnimation.size(); j++) {
		//�t���[�����擾����
		CAnimation* animation = mAnimation[j];
		//�Y������t���[���̎擾
		if (animation->mpKey == nullptr)continue;
		//�Y������t���[���̎擾
		CModelXFrame* frame = model->mFrame[animation->mFrameIndex];
		//�ŏ��̎��Ԃ�菬�����ꍇ
		if (mTime < animation->mpKey[0].mTime) {
			//�ϊ��s����O�R�}�ڂ̍s��ōX�V
			frame->mTransformMatrix += animation->mpKey[0].mMatrix * mWeight;
		}
		//�Ō�̎��Ԃ��傫���ꍇ
		else if (mTime >= animation->mpKey[animation->mKeyNum - 1].mTime) {
			//�ϊ��s����Ō�̃R�}�̍s��ōX�V
			frame->mTransformMatrix += animation->mpKey[animation->mKeyNum - 1].mMatrix * mWeight;
		}
		else {
			//���Ԃ̓r���̏ꍇ
			for (int k = 1; k < animation->mKeyNum; k++) {
				//�ϊ��s����A���`��ԂɂčX�V
				if (mTime < animation->mpKey[k].mTime &&
					animation->mpKey[k - 1].mTime != animation->mpKey[k].mTime) {

					float r = (animation->mpKey[k].mTime - mTime) /
						(animation->mpKey[k].mTime - animation->mpKey[k - 1].mTime);

					frame->mTransformMatrix +=
						(animation->mpKey[k - 1].mMatrix * r +
							animation->mpKey[k].mMatrix * (1 - r)) * mWeight;
					break;
				}
			}
		}
	}
}
/*
AnimateFrame
�t���[���̕ϊ��s����A�j���[�V�����f�[�^�ōX�V����
*/
void CModelX::AnimateFrame() {
	//�A�j���[�V�����œK�p�����t���[��
	//�ϊ��s����[���N���A����
	for (size_t i = 0; i < mAnimationSet.size(); i++) {
		CAnimationSet* animSet = mAnimationSet[i];
		//�d�݂��O�͔�΂�
		if (animSet->mWeight == 0)continue;
		//�t���[�����iAnimation���j�J��Ԃ�
		for (size_t j = 0;
			j < animSet->Animation().size(); j++)
		{
			CAnimation* animation =
				animSet->Animation()[j];
			//�Y������t���[���̕ϊ��s����[���N���A����
			memset(
				&mFrame[animation->mFrameIndex]
				->mTransformMatrix,
				0, sizeof(CMatrix));
		}
	}
	//�A�j���[�V�����ɊY������t���[���̕ϊ��s���
	//�A�j���[�V�����̃f�[�^�Őݒ肷��
	for (size_t i = 0; i < mAnimationSet.size(); i++) {
		CAnimationSet* animSet = mAnimationSet[i];
		//�d�݂��O�͔�΂�
		if (animSet->mWeight == 0)continue;
		animSet->AnimateMatrix(this);
	}
#ifdef _DEBUG
	for (int j =1; j < 5; j++)
	{
		printf("Frame:""%s\n", mFrame[j]->mpName);
		printf("%f\t", mFrame[j]->mTransformMatrix.M()[0]);
		printf("%f\t", mFrame[j]->mTransformMatrix.M()[1]);
		printf("%f\t", mFrame[j]->mTransformMatrix.M()[2]);
		printf("%f\n", mFrame[j]->mTransformMatrix.M()[3]);
		printf("%f\t", mFrame[j]->mTransformMatrix.M()[4]);
		printf("%f\t", mFrame[j]->mTransformMatrix.M()[5]);
		printf("%f\t", mFrame[j]->mTransformMatrix.M()[6]);
		printf("%f\n", mFrame[j]->mTransformMatrix.M()[7]);
		printf("%f\t", mFrame[j]->mTransformMatrix.M()[8]);
		printf("%f\t", mFrame[j]->mTransformMatrix.M()[9]);
		printf("%f\t", mFrame[j]->mTransformMatrix.M()[10]);
		printf("%f\n", mFrame[j]->mTransformMatrix.M()[11]);
		printf("%f\t", mFrame[j]->mTransformMatrix.M()[12]);
		printf("%f\t", mFrame[j]->mTransformMatrix.M()[13]);
		printf("%f\t", mFrame[j]->mTransformMatrix.M()[14]);
		printf("%f\n", mFrame[j]->mTransformMatrix.M()[15]);
		if (j == 4)
		{
			printf("");
		}
	}
#endif
}

std::vector<CAnimation*>& CAnimationSet::Animation()
{
	return mAnimation;
}

//�R���X�g���N�^
CMesh::CMesh()
	:mVertexNum(0)
	,mpVertex(nullptr)
	,mFaceNum(0)
	,mpVertexIndex(nullptr)
	,mNormalNum(0)
	,mpNormal(nullptr)
	,mMaterialNum(0)
	,mMaterialIndexNum(0)
	,mpMaterialIndex(nullptr)
{}
//�f�X�g���N�^
CMesh::~CMesh() {
	SAFE_DELETE_ARRAY(mpVertex);
	SAFE_DELETE_ARRAY(mpVertexIndex);
	SAFE_DELETE_ARRAY(mpNormal);
	SAFE_DELETE_ARRAY(mpMaterialIndex);
	//�X�L���E�F�C�g�̍폜
	for (size_t i = 0; i < mSkinWeights.size(); i++)
	{
		delete mSkinWeights[i];
	}
}

CSkinWeights::~CSkinWeights()
{
	SAFE_DELETE_ARRAY(mpFrameName);
	SAFE_DELETE_ARRAY(mpIndex);
	SAFE_DELETE_ARRAY(mpWeight);
}

//bool CModelXFrame::Index()
//{
//	return CModelXFrame::mIndex;
//}

/*
FinedFrame(�t���[�����j
�t���[�����ɊY������t���[���̃A�h���X��Ԃ�
*/
CModelXFrame* CModelX::FindFrame(char* name) {
	//�C�e���[�^�̍쐬
	std::vector<CModelXFrame*>::iterator itr;
	//�擪����Ō�܂ŌJ��Ԃ�
	for (itr = mFrame.begin(); itr != mFrame.end(); itr++) {
		//���O����v�������H
		if (strcmp(name, (*itr)->mpName) == 0) {
			//��v�����炻�̃A�h���X��Ԃ�
			return *itr;
		}
	}
	//��v����t���[���������ꍇ��nullptr��Ԃ�
	return nullptr;
}

int CModelXFrame::Index()
{
	return mIndex;
}

CAnimation::CAnimation(CModelX* model)
	:mpFrameName(0)
	,mFrameIndex(0)
	,mKeyNum(0)
	,mpKey(nullptr)
{
	model->GetToken();//{orAnimation Name
	if (strchr(model->Token(), '{')) {
		model->GetToken();//{
	}
	else {
		model->GetToken();//{
		model->GetToken();//{
	}

	model->GetToken();//FrameName
	mpFrameName = new char[strlen(model->Token()) + 1];
	strcpy(mpFrameName, model->Token());
	mFrameIndex = 
		model->FindFrame(model->Token())->Index();
	model->GetToken();//}
	//�L�[�̔z���ۑ����Ă����z��
	CMatrix* key[4] = { 0,0,0,0 };
	//���Ԃ̔z���ۑ����Ă����z��
	float* time[4] = { 0,0,0,0 };
	while (!model->EOT()) {
		model->GetToken();//}orAnimationKey
		if (strchr(model->Token(), '}'))break;
		if (strcmp(model->Token(), "AnimationKey") == 0) {
			model->GetToken(); //{
			//�f�[�^�̃^�C�v�擾
			int type = atoi(model->GetToken());
			//���Ԑ��擾
			mKeyNum = atoi(model->GetToken());
			switch (type) {
			case 0://Rotaion Quaternion
				//�s��̔z������Ԑ����m��
				key[type] = new CMatrix[mKeyNum];
				//���Ԃ̔z������Ԑ����m��
				time[type] = new float[mKeyNum];
				//���Ԑ����J��Ԃ�
				for (int i = 0; i < mKeyNum; i++) {
					//���Ԏ擾
					time[type][i] = atof(model->GetToken());
					model->GetToken();//4��ǂݔ�΂�
					//w,x,y,z���擾
					float w = atof(model->GetToken());
					float x = atof(model->GetToken());
					float y = atof(model->GetToken());
					float z = atof(model->GetToken());
					//�N�H�[�^�j�I�������]�s��ɕϊ�
					key[type][i].Quaternion(x, y, z, w);
				}
				break;
			case 1://�g��E�k���̍s��쐬
				key[type] = new CMatrix[mKeyNum];
				time[type] = new float[mKeyNum];
				for (int i = 0; i < mKeyNum; i++) {
					time[type][i] = atof(model->GetToken());
					model->GetToken();//3
					float x = atof(model->GetToken());
					float y = atof(model->GetToken());
					float z = atof(model->GetToken());
					key[type][i].Scale(x, y, z);
				}
				break;
			case 2://�ړ��̍s��쐬
				key[type] = new CMatrix[mKeyNum];
				time[type] = new float[mKeyNum];
				for (int i = 0; i < mKeyNum; i++) {
					time[type][i] = atof(model->GetToken());
					model->GetToken();//3
					float x = atof(model->GetToken());
					float y = atof(model->GetToken());
					float z = atof(model->GetToken());
					key[type][i].Translate(x, y, z);
				}
				break;
			case 4://�s��f�[�^���擾
				mpKey = new CAnimationKey[mKeyNum];
				for (int i = 0; i < mKeyNum; i++) {
					mpKey[i].mTime = atof(model->GetToken()); //Time
					model->GetToken();//16
					for (int j = 0; j < 16; j++) {
						mpKey[i].mMatrix.M()[j] = atof(model->GetToken());
					}
				}
				break;
			}
			model->GetToken();//}
		}else{
			model->SkipNode();
		}//while�̏I���
	}
	//�s��f�[�^�ł͂Ȃ���
	if (mpKey == 0) {
		//���Ԑ����L�[���쐬
		mpKey = new CAnimationKey[mKeyNum];
		for (int i = 0; i < mKeyNum; i++) {
			//���Ԑݒ�
			mpKey[i].mTime = time[2][i]; //Time
			//�s��쐬�@Size * Rotation * Position
			mpKey[i].mMatrix = key[1][i] * key[0][i] * key[2][i];
		}
	}
	//�m�ۂ����G���A���
	for (int i = 0; i < ARRAY_SIZE(key); i++) {
		SAFE_DELETE_ARRAY(time[i]);
		SAFE_DELETE_ARRAY(key[i]);
	}
#ifdef _DEBUG
	//printf("Animation:%s\n", mpFrameName);
	/*for (int i = 0; i <= mKeyNum; i++)
	{
		printf("%f\t", mpKey[0].mMatrix.M()[i]);
		if (i == 3 || i == 7 || i == 11)
		{
			printf("\n");
		}
		if (i == 15 || strchr(model->Token(), ';;'))
		{
			printf("\n");
			break;
		}*/
		/*printf("%f\t", mpKey[10].mMatrix.M()[0]);
		printf("%f\t", mpKey[350].mMatrix.M()[1]);
		printf("%f\t", mpKey[50].mMatrix.M()[2]);
		printf("%f\n", mpKey[0].mMatrix.M()[3]);
		printf("%f\t", mpKey[453].mMatrix.M()[4]);
		printf("%f\t", mpKey[22].mMatrix.M()[5]);
		printf("%f\t", mpKey[8534].mMatrix.M()[6]);
		printf("%f\n", mpKey[2].mMatrix.M()[7]);
		printf("%f\t", mpKey[567].mMatrix.M()[8]);
		printf("%f\t", mpKey[8].mMatrix.M()[9]);
		printf("%f\t", mpKey[9].mMatrix.M()[10]);
		printf("%f\n", mpKey[10].mMatrix.M()[11]);
		printf("%f\t", mpKey[111110].mMatrix.M()[12]);
		printf("%f\t", mpKey[120].mMatrix.M()[13]);
		printf("%f\t", mpKey[014].mMatrix.M()[14]);
		printf("%f\n", mpKey[999].mMatrix.M()[15]);*/
	//}
#endif
}

/*
CAnimationSet
*/
CAnimationSet::CAnimationSet(CModelX* model)
	:mpName(nullptr)
	,mTime(0.0f)
	,mWeight(0.0f)
	,mMaxTime(0.0f)
{
	model->mAnimationSet.push_back(this);
	model->GetToken(); //Animation Name
	//�A�j���[�V�����Z�b�g����ޔ�
	mpName = new char[strlen(model->Token()) + 1];
	strcpy(mpName, model->Token());
	model->GetToken();//{
	while (!model->EOT()) {
		model->GetToken();//}or Animation
		if (strchr(model->Token(), '}'))break;
		if (strcmp(model->Token(), "Animation") == 0) {
			//Animation�v�f�ǂݍ���
			mAnimation.push_back(new CAnimation(model));
		}
	}
//#ifdef _DEBUG
//	printf("AnimationSet:%s\n", mpName);
//#endif
}

/*
CSkinWeight
�X�L���E�F�C�g�̓ǂݍ���
*/
CSkinWeights::CSkinWeights(CModelX* model)
	:mpFrameName(0)
	, mFrameIndex(0)
	, mIndexNum(0)
	, mpIndex(nullptr)
	, mpWeight(nullptr)
{
	int n;
	n = 0;
	model->GetToken(); //{
	model->GetToken(); //FrameName
	//�t���[�����G���A�m�ہA�ݒ�
	mpFrameName = new char[strlen(model->Token()) + 1];
	strcpy(mpFrameName, model->Token());

	//���_�ԍ����擾
	mIndexNum = atoi(model->GetToken());
	//���_�ԍ������O�𒴂���
	if (mIndexNum > 0) {
		//���_�ԍ��ƒ��_�E�F�C�g�̃G���A�m��
		mpIndex = new int[mIndexNum];
		mpWeight = new float[mIndexNum];
		//���_�ԍ��擾
		for (int i = 0; i < mIndexNum; i++)
			mpIndex[i] = atoi(model->GetToken());
		//���_�E�F�C�g�擾
		for (int i = 0; i < mIndexNum; i++)
			mpWeight[i] = atof(model->GetToken());
	}
	//�I�t�Z�b�g�s��擾
	for (int i = 0; i < 16; i++) {
		mOffset.M()[i] = atof(model->GetToken());
	}
	model->GetToken(); //}
#ifdef _DEBUG
	/*printf("SkinWeights:%s\n", mpFrameName);
	while (n != mIndexNum)
	{
		printf("%i\t", mpIndex[0 + n]);
		printf("%f\n", mpWeight[0 + n]);
		n++;
	}
	printf("%f\t",mOffset.M()[0]);
	printf("%f\t", mOffset.M()[1]);
	printf("%f\t", mOffset.M()[2]);
	printf("%f\n", mOffset.M()[3]);
	printf("%f\t", mOffset.M()[4]);
	printf("%f\t", mOffset.M()[5]);
	printf("%f\t", mOffset.M()[6]);
	printf("%f\n", mOffset.M()[7]);
	printf("%f\t", mOffset.M()[8]);
	printf("%f\t", mOffset.M()[9]);
	printf("%f\t", mOffset.M()[10]);
	printf("%f\n", mOffset.M()[11]);
	printf("%f\t", mOffset.M()[12]);
	printf("%f\t", mOffset.M()[13]);
	printf("%f\t", mOffset.M()[14]);
	printf("%f\n", mOffset.M()[15]);*/

#endif
}

void CModelX::Load(char* file) {
	//
	//�t�@�C���T�C�Y���擾����
	//
	FILE* fp; //�t�@�C���|�C���^�ϐ��̍쐬
	fp = fopen(file, "rb"); //�t�@�C�����I�[�v������
	if (fp == NULL) { //�G���[�`�F�b�N
		printf("fopen error:%s\n", file);
		return;
	}
	//�t�@�C���̍Ō�ֈړ�
	fseek(fp, 0L, SEEK_END);
	//�t�@�C���T�C�Y�̎擾
	int size = ftell(fp);
	//�t�@�C���T�C�Y+�P�o�C�g���̗̈���m��
	char* buf = mpPointer = new char[size + 1];
	//
	//�t�@�C������RD���f���̃f�[�^��ǂݍ���
	//
	//�t�@�C���̐擪�ֈړ�
	fseek(fp, 0L, SEEK_SET);
	//�m�ۂ����̈�Ƀt�@�C���T�C�Y���f�[�^��ǂݍ���
	fread(buf, size, 1, fp);
	//�Ō��\0��ݒ肷��i������̏I�[�j
	buf[size] = '\0';
	fclose(fp); //�t�@�C�����N���[�Y����
	//printf("%s", buf);
	//������̍Ō�܂ŌJ��Ԃ�
	while (*mpPointer != '\0') {
		GetToken(); //�P��̎擾
		//�P�ꂪFrame�̏ꍇ
		if (strcmp(mToken, "Frame") == 0) {
		   //�t���[�����쐬����
			new CModelXFrame(this);
		}
		//�P�ꂪAnimationSet�̏ꍇ
		else if (strcmp(mToken, "AnimationSet") == 0) {
			new CAnimationSet(this);
		}
	}
	SAFE_DELETE_ARRAY(buf); //�m�ۂ����̈���J������
}

/*
SkipNode
�m�[�h��ǂݔ�΂�
*/
void CModelX::SkipNode() {
	//�������I�������I��
	while (*mpPointer != '\0') {
		GetToken(); //���̒P��擾
		//{�����������烋�[�v�I��
		if (strchr(mToken, '{'))break;
	}
	int count = 1;
	//�������I��邩�A�J�E���g���O�ɂȂ�����I��
	while (*mpPointer != '\0' && count > 0) {
		GetToken(); //���̒P��擾
		//{��������ƃJ�E���g�A�b�v
		if (strchr(mToken, '{'))count++;
		//}��������ƃJ�E���g�_�E��
		else if (strchr(mToken, '}'))count--;
	}
}

char* CModelX::Token()
{
	return mToken;
}


bool CModelX::EOT()
{
	if (*mpPointer == '\0')
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
CModelXFrame
model:CModelX�C���X�^���X�ւ̃|�C���^
�t���[�����쐬����
�ǂݍ��ݒ���Frame��������΁A�t���[�����쐬���A
�q�t���[���ɒǉ�����
*/
CModelXFrame::CModelXFrame(CModelX* model)
	:mpName(nullptr)
	,mpMesh(nullptr)
	, mIndex(0)
{
	//���݂̃t���[���z��̗v�f�����擾���ݒ肷��
	mIndex = model->mFrame.size();
	//CModelX�̃t���[���z��ɒǉ�����
	model->mFrame.push_back(this);
	//�ϊ��s���P�ʍs��ɂ���
	mTransformMatrix.Identity();
	//���̒P��i�t���[�����̗\��j���擾����
	model->GetToken(); //frame name
	//�t���[�������G���A���m�ۂ���
	mpName = new char[strlen(model->mToken) + 1];
	//�t���[�������R�s�[����
	strcpy(mpName, model->mToken);
	//���̒P��({�̗\��j���擾����
	model->GetToken(); //�o
	//�����������Ȃ�����I���
	while (*model->mpPointer != '\0') {
		//���̒P��擾
		model->GetToken(); //Frame
		//�p�������̏ꍇ�͏I��
		if (strchr(model->mToken, '}'))break;
		//�V���ȃt���[���̏ꍇ�́A�q�t���[���ɒǉ�
		if (strcmp(model->mToken, "Frame") == 0) {
			//�t���[�����쐬���A�q�t���[���̔z��ɒǉ�
			mChild.push_back(new CModelXFrame(model));
		}
		else if(strcmp(model->mToken, "FrameTransformMatrix") == 0) {
			model->GetToken(); //{
				for (int i = 0; i < mTransformMatrix.Size(); i++) {
					mTransformMatrix.M()[i] = atof(model->GetToken());
				}
				model->GetToken();//}
		}
		else if (strcmp(model->mToken, "Mesh") == 0) {
			mpMesh = new CMesh();
			mpMesh->Init(model);
		}
		else {
			//��L�ȊO�̗v�f�͓ǂݔ�΂�
			model->SkipNode();
		}
	}
	//�f�o�b�O�o�[�W�����̂ݗL��
#ifdef _DEBUG
	//printf("SkinWeights:%s\n",mpName);
	//printf("%s\n", mpName);
	/*printf("%f\t", mTransformMatrix.M()[0]);
	printf("%f\t", mTransformMatrix.M()[1]);
	printf("%f\t", mTransformMatrix.M()[2]);
	printf("%f\n", mTransformMatrix.M()[3]);
	printf("%f\t", mTransformMatrix.M()[4]);
	printf("%f\t", mTransformMatrix.M()[5]);
	printf("%f\t", mTransformMatrix.M()[6]);
	printf("%f\n", mTransformMatrix.M()[7]);
	printf("%f\t", mTransformMatrix.M()[8]);
	printf("%f\t", mTransformMatrix.M()[9]);
	printf("%f\t", mTransformMatrix.M()[10]);
	printf("%f\n", mTransformMatrix.M()[11]);
	printf("%f\t", mTransformMatrix.M()[12]);
	printf("%f\t", mTransformMatrix.M()[13]);
	printf("%f\t", mTransformMatrix.M()[14]);
	printf("%f\n", mTransformMatrix.M()[15]);*/
#endif
}

/*
Init
Mesh�̃f�[�^����荞��
*/
void CMesh::Init(CModelX* model) {
	int n;
	n = 0;
	model->GetToken(); //{or���O
	if (!strchr(model->Token(), '{')) {
		//���O�̏ꍇ,�����o
		model->GetToken();//�o
	}

	//���_���̎擾
	mVertexNum = atoi(model->GetToken());
	//���_�����G���A�m��
	mpVertex = new CVector[mVertexNum];
	//���_�����f�[�^����荞��
	for (int i = 0; i < mVertexNum; i++) {
		mpVertex[i].X(atof(model->GetToken()));
		mpVertex[i].Y(atof(model->GetToken()));
		mpVertex[i].Z(atof(model->GetToken()));
	}
	//�ʐ��ǂݍ���
	mFaceNum = atoi(model->GetToken());
	//���_����1�ʂɂR���_
	mpVertexIndex = new int[mFaceNum * 3];
	for (int i = 0; i < mFaceNum * 3; i += 3) {
		model->GetToken(); //;���_���ǂݔ�΂�
		mpVertexIndex[i] = atoi(model->GetToken());
		mpVertexIndex[i + 1] = atoi(model->GetToken());
		mpVertexIndex[i + 2] = atoi(model->GetToken());
	}
	//�P�ꂪ����ԌJ��Ԃ�
	while (!model->EOT()) {
		model->GetToken(); //MeshNormals
		//}�������̏ꍇ�͏I��
		if (strchr(model->Token(), '}'))
			break;
		if (strcmp(model->Token(), "MeshNormals") == 0) {
			model->GetToken(); //{
			//�@���f�[�^�����擾
			mNormalNum = atoi(model->GetToken());
			//�@���f�[�^��z��Ɏ�荞��
			CVector* pNormal = new CVector[mNormalNum];
			for (int i = 0; i < mNormalNum; i++) {
				pNormal[i].X(atof(model->GetToken()));
				pNormal[i].Y(atof(model->GetToken()));
				pNormal[i].Z(atof(model->GetToken()));
			}
			//�@�������搔�~�R
			mNormalNum = atoi(model->GetToken()) * 3; //FaceNum
			int ni;
			//���_���ɖ@���f�[�^��ݒ肷��
			mpNormal = new CVector[mNormalNum];
			for (int i = 0; i < mNormalNum; i += 3) {
				model->GetToken(); //3
				ni = atoi(model->GetToken());
				mpNormal[i] = pNormal[ni];
				ni = atoi(model->GetToken());
				mpNormal[i + 1] = pNormal[ni];
				ni = atoi(model->GetToken());
				mpNormal[i + 2] = pNormal[ni];
			}
			delete[] pNormal;
			model->GetToken(); //}
		}//End ofMeshNormals
		//MeshMaterialList�̂Ƃ�
		else if (strcmp(model->Token(), "MeshMaterialList") == 0) {
			model->GetToken(); //{
			//Material�̐�
			mMaterialNum = atoi(model->GetToken());
			//FaceNum
			mMaterialIndexNum = atoi(model->GetToken());
			//�}�e���A���C���f�b�N�X�̍쐬
			mpMaterialIndex = new int[mMaterialIndexNum];
			for (int i = 0; i < mMaterialIndexNum; i++) {
				mpMaterialIndex[i] = atoi(model->GetToken());
			}
			//�}�e���A���f�[�^�̍쐬
			for (int i = 0; i < mMaterialNum; i++) {
				model->GetToken(); //Material
				if (strcmp(model->Token(), "Material") == 0) {
					mMaterial.push_back(new CMaterial(model));
				}
			}
			model->GetToken(); //}//End of MeshMaterialList
		}//End of MeshMaterialList
		//SkinWeights�̂Ƃ�
		else if (strcmp(model->Token(), "SkinWeights") == 0) {
			//CSkinWeights�N���X�̃C���X�^���X���쐬���A�z��ɒǉ�
			mSkinWeights.push_back(new CSkinWeights(model));
		}
		else {
			//�ȊO�̃m�[�h�͓ǂݔ�΂�
			model->SkipNode();
		}
	}
#ifdef _DEBUG
	//printf("SkinWeights:%f\n", mFrameIndex);
	/*while (n != mNormalNum)
	{
		printf("%f\t", mpNormal[n].X());
		printf("%f\t", mpNormal[n + 1].Y());
		printf("%f\n", mpNormal[n + 2].Z());
		printf("%f\t", mpNormal[n].X());
		printf("%f\t", mpNormal[n + 1].Y());
		printf("%f\n", mpNormal[n + 2].Z());
		printf("%f\t", mpNormal[n].X());
		printf("%f\t", mpNormal[n + 1].Y());
		printf("%f\n", mpNormal[n + 2].Z());
		n = n + 3;

	}*/
	/*printf("VertexNum:%i\n", mVertexNum);
	while (n != mVertexNum)
	{
		printf("%f\t", mpVertex[n].X());
		printf("%f\t", mpVertex[n].Y());
		printf("%f\n", mpVertex[n].Z());
		n = n + 1;
	}*/
#endif
}

CAnimation::~CAnimation() {
	SAFE_DELETE_ARRAY(mpFrameName);
	SAFE_DELETE_ARRAY(mpKey);
}

CAnimationSet::~CAnimationSet()
{
	SAFE_DELETE_ARRAY(mpName);
	//�A�j���[�V�����v�f�̍폜
	for (size_t i = 0; i < mAnimation.size(); i++) {
		delete mAnimation[i];
	}
}

/*
Render
��ʂɕ`�悷��
*/
void CMesh::Render() {
	/* ���_�f�[�^�A�@���f�[�^�̔z���L���ɂ���*/
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	/*���_�f�[�^�A�@���f�[�^�̏ꏊ���w�肷��*/
	glVertexPointer(3, GL_FLOAT, 0, mpVertex);
	glNormalPointer(GL_FLOAT, 0, mpNormal);
	/*���_�̃C���f�b�N�X�̏ꏊ���w�肵�Đ}�`��`�悷��*/
	for (int i = 0; i < mFaceNum; i++) {
		//�}�e���A����K�p����
		mMaterial[mpMaterialIndex[i]]->Enabled();
		glDrawElements(GL_TRIANGLES, 3,
			GL_UNSIGNED_INT, (mpVertexIndex + i * 3));
	}

	/*���_�f�[�^�A�@���f�[�^�̔z��𖳌��ɂ���*/
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
}

/*
Render
���b�V�������݂���Ε`�悷��
*/
void CModelXFrame::Render() {
	if (mpMesh != nullptr)
		mpMesh->Render();
}

/*
Render
�S�Ẵt���[���̕`�揈�����Ăяo��
*/
void CModelX::Render() {
	for (size_t i = 0; i < mFrame.size(); i++) {
		mFrame[i]->Render();
	}
}

std::vector<CAnimationSet*>& CModelX::AnimationSet()
{
	return CModelX::mAnimationSet;
}