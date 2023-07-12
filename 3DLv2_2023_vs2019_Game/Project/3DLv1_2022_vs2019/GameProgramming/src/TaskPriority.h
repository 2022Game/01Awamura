#pragma once

//Taskの優先順序
enum class TaskPriority
{
	eNone = -1,

	eBackground, //拝啓

	//2D関連
	eSystem,	//システム関連
	eUI,		//UI関連


	//3D半透明
	eEffect,	//エフェクト

	//3D不透明
	ePlayer,	//プレイヤー
	eObstacie,  //障害物
	eMoveObject, //移動オブジェクト
	eDefault,	//デフォルト

	Num
};