#pragma once
#include <initializer_list>

// 衝突判定レイヤー
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
	eStorn,
	eMoveRSwitch,
	eMoveLSwitch,
};
// 衝突判定レイヤーの初期化リスト
using Layers = std::initializer_list<ELayer>;
