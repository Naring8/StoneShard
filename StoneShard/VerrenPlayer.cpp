#include "stdafx.h"

VerrenPlayer::VerrenPlayer()
{
	plCol = new ObRect;
	plCol->pivot = OFFSET_B;

	body = new ObImage(L"s_player/humanStand.png");
	body->SetParentRT(*plCol);

	head = new ObImage(L"s_player/s_VerrenHead/VerrenHeadIdle.png");
	head->maxFrame.x = 5;
	head->ChangeAnim(ANIMSTATE::LOOP, 0.5f);
	head->SetParentRT(*plCol);

	bloodHead = new ObImage(L"s_player/s_VerrenHead/VerrenHeadBlood.png");
	bloodHead->maxFrame.x = 5;
	bloodHead->ChangeAnim(ANIMSTATE::LOOP, 0.5f);
	bloodHead->SetParentRT(*plCol);
	bloodHead->isVisible = false;

	attack = new ObImage(L"s_player/s_VerrenHead/idleAttack.png");
	attack->SetParentRT(*plCol);

	bloodAttack = new ObImage(L"s_player/s_VerrenHead/bloodAttack.png");
	bloodAttack->SetParentRT(*plCol);

	pants = new ObImage(L"s_player/s_char_tatteredrags/dragsStand.png");
	pants->SetParentRT(*plCol);
	shoes = new ObImage(L"s_player/charShackles.png");
	shoes->SetParentRT(*plCol);

	body->pivot = head->pivot = bloodHead->pivot = attack->pivot = bloodAttack->pivot = pants->pivot = shoes->pivot = OFFSET_B;
	body->scale = head->scale = bloodHead->scale = attack->scale = bloodAttack->scale = pants->scale = shoes->scale = Vector2(48.0f, 40.0f) * 2.0f;

	attack->isVisible = bloodAttack->isVisible = false;

	hp = 100;
	mp = 100;

	pState = PlayerState::IDLE;

	VerrenDead = new ObImage(L"s_playerDead.png");
	VerrenDead->scale = Vector2(40.0f, 40.0f) * 2.0f;
	VerrenDead->pivot = OFFSET_B;
	VerrenDead->SetParentRT(*plCol);
	VerrenDead->isVisible = false;

	playerDead = false;
}

VerrenPlayer::~VerrenPlayer()
{
	SafeDelete(plCol);

	SafeDelete(body);
	SafeDelete(head);
	SafeDelete(pants);
	SafeDelete(shoes);

	SafeDelete(VerrenDead);
}

void VerrenPlayer::Update()
{
	if (ImGui::Button("HEAD"))
		head->isVisible = !head->isVisible;
	if (ImGui::Button("PANTS"))
		pants->isVisible = !pants->isVisible;
	if (ImGui::Button("SHOES"))
		shoes->isVisible = !shoes->isVisible;

	SetPlayerState();

	if (pState == PlayerState::ATTACK)
		PlayerAttack();

	ImGui::SliderInt("HP", &hp, 0, 100);
	ImGui::SliderInt("MP", &mp, 0, 100);
	pMenu.SetPlayerHMP(hp, mp);

	pMenu.Update();
	plCol->Update();

	body->Update();
	head->Update();
	pants->Update();
	shoes->Update();

	attack->Update();
	bloodHead->Update();
	bloodAttack->Update();

	VerrenDead->Update();
}

void VerrenPlayer::LateUpdate()
{
	pMenu.LateUpdate();
}

void VerrenPlayer::Render()
{
	pMenu.Render();

	body->Render();
	head->Render();
	pants->Render();
	shoes->Render();

	attack->Render();
	bloodHead->Render();
	bloodAttack->Render();

	VerrenDead->Render();
}

void VerrenPlayer::SetPlayerTile(Int2 tilePos, Int2 scale)
{
	plCol->SetWorldPos(Vector2(-app.GetHalfWidth() + (float)(tilePos.x * scale.x) + scale.x * 0.5f,
		-app.GetHalfHeight() + (float)(tilePos.y * scale.y) + scale.y * 0.5f));
}

void VerrenPlayer::SetPlayerState()
{
	if (hp <= 0)	// »ç¸Á
	{
		bloodHead->isVisible = false;
		body->isVisible = false;
		pants->isVisible = false;
		shoes->isVisible = false;

		VerrenDead->isVisible = true;
	}
	else if (hp < 50)	// ÇÇ Èê¸²
	{
		head->isVisible = false;
		bloodHead->isVisible = true;
	}
	else			// ±âº» »óÅÂ
	{
		head->isVisible = true;
		bloodHead->isVisible = false;
	}
}

void VerrenPlayer::PlayerAttack()
{
	pState = PlayerState::ATTACK;

	if (attackTime > 0)
	{
		plCol->MoveWorldPos(Vector2(1.0f, 0.0f) * 5.0f * (attackTime - 0.25f));
		if (hp < 50)
		{
			bloodHead->isVisible = false;
			bloodAttack->isVisible = true;
		}
		else
		{
			head->isVisible = false;
			attack->isVisible = true;
		}
		attackTime -= DELTA;
	}
	else
	{
		head->isVisible = true;
		attack->isVisible = false;
		bloodAttack->isVisible = false;

		pState = PlayerState::IDLE;
	}
}

void VerrenPlayer::PlayerGetAttack()
{
}

void VerrenPlayer::ChangePlayerSprite(int sourX, int destX)
{
	if (sourX > destX)	// ¿ÞÂÊ
		plCol->rotationY = 0.0f;
	else if (sourX < destX)	// ¿À¸¥ÂÊ
		plCol->rotationY = PI;
}