#include "CRideableObject.h"
#include "CPlayer.h"

CRideableObject::CRideableObject(ETaskPriority prio)
	: CObjectBase(ETag::eRideableObject,prio, 0, ETaskPauseType::eGame)
{
}

CRideableObject::~CRideableObject()
{
	//�v���C���[�����݂����,
	//�������g���폜����邱�Ƃ��v���C���[�ɓ`����
	CPlayer* player = CPlayer::Instance();
	if (player != nullptr)
	{
		player->DeleteRideableObject(this);
	}
}