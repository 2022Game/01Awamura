#pragma once
#include <initializer_list>

// �Փ˔��背�C���[
enum class ELayer
{
	eNone = -1,
	eField,
	ePlayerSpher,
	eObject,
	eBadObject,
	eBigBadObject,
	eClearObject,
	ePlayer,
};
// �Փ˔��背�C���[�̏��������X�g
using Layers = std::initializer_list<ELayer>;
