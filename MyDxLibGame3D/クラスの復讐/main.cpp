//-----------------------------------------------------------------------------
// @brief  メイン処理.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "DxLib.h"
#include "Player.h"
#include "Camera.h"
#include "ObstructStatic.h"
#include "ObstructFloat.h"
#include "ObstructBase.h"

// 障害物の数.
#define OBSTRUCT_NUM 3

//-----------------------------------------------------------------------------
// @brief  メイン関数.
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{
	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)		
	{
		return -1;	// エラーが起きたら直ちに終了
	}

	// 画面モードのセット
	SetGraphMode(640, 480, 16);
	ChangeWindowMode(TRUE);

	int modelHandle = MV1LoadModel("data/model/obstructStatic/obstructStatic.pmd");

	if (modelHandle < 0)
	{
		printfDx("ObstructFloat:データ読み込みに失敗");
	}

	// カメラを生成.
	Camera* camera = new Camera();

	// プレイヤーを生成.
	Player* player = new Player();

	// 障害物を生成.
	ObstructBase* obstructs[1000];

	for (int i = 0; i < 100; i++)
	{
		obstructs[i] = new ObstructStatic(modelHandle);
	}



	// 障害物の位置を初期化.
	float band = 10.0f;

	for (int i = 0; i < 100; i++)
	{
		band++;

		obstructs[i]->SetPos(VGet(-band + (band * 0), 0, -1.0f));
	}
	
	// エスケープキーが押されるかウインドウが閉じられるまでループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// プレイヤー制御.
		player->Update();

		// カメラ制御.
		camera->Update(*player);

		// 障害物制御.
		for (int i = 0; i < 100; i++)
		{
			obstructs[i]->Update();
		}

		// 画面を初期化する
		ClearDrawScreen();

		// プレイヤー描画.
		player->Draw();

		// 障害物描画.
		for (int i = 0; i < 100; i++)
		{
			obstructs[i]->Draw();
		}
		// 裏画面の内容を表画面に反映させる
		ScreenFlip();
	}

	// プレイヤーを削除.
	delete(player);

	// カメラを削除.
	delete(camera);

	// 障害物を削除.
	for (int i = 0; i < 100; i++)
	{
		delete(obstructs[i]);
	}
	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}