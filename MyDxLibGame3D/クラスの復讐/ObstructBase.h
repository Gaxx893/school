#pragma once
#include "DxLib.h"

class ObstructBase
{
public:
	ObstructBase();
	virtual ~ObstructBase();

	virtual void Update() = 0;
	virtual void Draw() = 0;

	// ���f���n���h���̎擾.
	int GetModelHandle() { return modelHandle; }

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

protected:
	int		modelHandle;	// ���f���n���h��.
	VECTOR	pos;			// �|�W�V����.
};

