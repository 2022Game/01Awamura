#pragma once
#include <initializer_list>

// �Փ˔��背�C���[
enum class ELayer
{
	eNone = -1,
	eTest,
	eField,
	ePlayer,
	eBadObject,
	eBigBadObject,
	eObject,
	eClearObject,
	eWarpObject,
	eSlopeField,
	eStone,
	eMoveRSwitch,
	eMoveLSwitch,
	eMove,
};
// �Փ˔��背�C���[�̏��������X�g
using Layers = std::initializer_list<ELayer>;
