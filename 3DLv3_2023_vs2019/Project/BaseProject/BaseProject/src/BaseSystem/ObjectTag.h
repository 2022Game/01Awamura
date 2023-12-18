#pragma once
#include <initializer_list>

// オブジェクト識別用のタグ
enum class ETag
{
	eNone = -1,

	eField,	// フィールドを構成するオブジェクト
	eRideableObject,	// 乗ることができるオブジェクト
	eItem,	// アイテムのオブジェクト
	eObstacles, //障害物のオブジェクト
	eStone, //岩

	ePlayer,// プレイヤー
	eEnemy,	// エネミー

	eCamera,// カメラ

	Num
};
// オブジェクト識別用のタグの初期化リスト
using Tags = std::initializer_list<ETag>;
