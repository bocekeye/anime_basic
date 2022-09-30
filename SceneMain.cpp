#include "DxLib.h"
#include <cassert>
#include "SceneMain.h"

namespace
{
	//グラフィックファイル名
	const char* const kPlayerGraphicFikename = "data / char.png";

	//プレイヤーグラフィック分割数
	constexpr int kPlayerGraphicDivX = 3;
	constexpr int kPlayerGraphicDivY = 4;
	constexpr int kPlayerGraphicDivNum = kPlayerGraphicDivX * kPlayerGraphicDivY;

	//プレイヤーグラフィックサイズ
	constexpr int kPlayerGraphicSizeX = 32;
	constexpr int kPlayerGraphicSizeY = 32;
}


SceneMain::SceneMain()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		handle = -1;
	}
}
SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{
	LoadDivGraph("data/char.png", kPlayerGraphicDivNum, 
		kPlayerGraphicDivX, kPlayerGraphicDivY,
		kPlayerGraphicSizeX, kPlayerGraphicSizeY, m_hPlayerGraphic);

	m_player.setHandle(m_hPlayerGraphic[11]);
	m_player.init();
}

// 終了処理
void SceneMain::end()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		DeleteGraph(handle);
	}
	
}

// 毎フレームの処理
void SceneMain::update()
{
	m_player.update();
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();
}