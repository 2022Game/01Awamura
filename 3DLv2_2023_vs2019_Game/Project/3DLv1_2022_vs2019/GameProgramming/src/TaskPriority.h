#pragma once

//Task�̗D�揇��
enum class TaskPriority
{
	eNone = -1,

	eBackground, //�q�[

	//2D�֘A
	eSystem,	//�V�X�e���֘A
	eUI,		//UI�֘A


	//3D������
	eEffect,	//�G�t�F�N�g

	//3D�s����
	ePlayer,	//�v���C���[
	eObstacie,  //��Q��
	eMoveObject, //�ړ��I�u�W�F�N�g
	eDefault,	//�f�t�H���g

	Num
};