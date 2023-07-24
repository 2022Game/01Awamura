#pragma once

//シーンの種類
enum class EScene
{
	eNone, //どのシーンにも所属していない
	eTitle, //タイトルシーン
	eClear, //CLEAR画面
	eGame, //ゲームシーン
	scene, //削除
};