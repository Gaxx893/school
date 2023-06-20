#pragma once
#include "DxLib.h"

class ObstructBase
{
public:
	ObstructBase();
	virtual ~ObstructBase();

	virtual void Update() = 0;
	virtual void Draw() = 0;

	// モデルハンドルの取得.
	int GetModelHandle() { return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

protected:
	int		modelHandle;	// モデルハンドル.
	VECTOR	pos;			// ポジション.
};

