﻿//-----------------------------------------------------------------------------
// @brief  障害物：動かない.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "ObstructStatic.h"

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
ObstructStatic::ObstructStatic(int ModelHandle)
{
	modelHandle = MV1DuplicateModel(ModelHandle);

	if (modelHandle < 0)
	{
		printfDx("ObstructFloat:データ読み込みに失敗");
	}

	pos = VGet(0, 0, 0);
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
ObstructStatic::~ObstructStatic()
{
	// モデルのアンロード.
	MV1DeleteModel(modelHandle);
}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void ObstructStatic::Update()
{
	// ３Dモデルのポジション設定
	MV1SetPosition(modelHandle, pos);
}

void ObstructStatic::Draw()
{
	// ３Ｄモデルの描画
	MV1DrawModel(modelHandle);
}
