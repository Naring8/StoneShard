#include "stdafx.h"

VemMonster::VemMonster()
{
	monsCol = new ObRect;
	monsCol->pivot = OFFSET_B;

	monsImg = new ObImage(L"m_Vampire.png");	
	monsCol->scale = monsImg->scale = Vector2((float)monsImg->imageSize.x, (float)monsImg->imageSize.y) * 2.0f;
	monsImg->pivot = OFFSET_B;
	monsImg->SetParentRT(*monsCol);

	hp = 30;
}

VemMonster::~VemMonster()
{
	SafeDelete(monsCol);
	SafeDelete(monsImg);
}

void VemMonster::Update()
{
	if (mState == MonsterState::ATTACK)
		MonsterAttack();
	monsCol->Update();
	monsImg->Update();
}

void VemMonster::LateUpdate()
{
}

void VemMonster::Render()
{
	monsImg->Render();
}

void VemMonster::SetMonsterTile(Int2 tilePos, Int2 scale)
{
	monsCol->SetWorldPos(Vector2(-app.GetHalfWidth() + (float)(tilePos.x * scale.x) + scale.x * 0.5f,
		-app.GetHalfHeight() + (float)(tilePos.y * scale.y) + scale.y * 0.5f));
}

void VemMonster::ChangeMonsterSprite(int sourX, int destX)
{
	if (sourX > destX)	// ¿ÞÂÊ
		monsCol->rotationY = 0.0f;
	else if(sourX < destX)	// ¿À¸¥ÂÊ
		monsCol->rotationY = PI;
}

void VemMonster::MonsterAttack()
{
	mState = MonsterState::ATTACK;

	if (attackTime > 0)
	{
		monsCol->MoveWorldPos(Vector2(1.0f, 0.0f) * 5.0f * (attackTime - 0.25f));

		attackTime -= DELTA;
	}
	else
		mState = MonsterState::IDLE;
}

void VemMonster::MonsterGetAttack(int damage)
{
	hp -= damage;
}
