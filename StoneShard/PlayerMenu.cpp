#include "stdafx.h"

PlayerMenu::PlayerMenu()
{
	menuImg = new ObImage(L"MainMenu.png");
	menuImg->SetWorldPosY(-app.GetHalfHeight());
	menuImg->pivot = OFFSET_B;
	menuImg->scale = Vector2(648.0f, 61.0f) * 2.0f;
	menuImg->space = SPACE::SCREEN;

	hpImg = new ObImage(L"s_healthbar/hp.png");
	mpImg = new ObImage(L"s_hp_n/mp.png");

	hpImg->space = SPACE::SCREEN;
	hpImg->pivot = OFFSET_L;
	hpImg->SetWorldPos(Vector2(-319.0f, -358.5f));

	mpImg->space = SPACE::SCREEN;
	mpImg->pivot = OFFSET_L;
	mpImg->SetWorldPos(Vector2(   6.0f, -358.5f));
}

PlayerMenu::~PlayerMenu()
{
	SafeDelete(menuImg);

	SafeDelete(hpImg);
	SafeDelete(mpImg);
}

void PlayerMenu::Update()
{
	charButton.Update();
	invButton.Update();
	skillButton.Update();
	questButton.Update();
	skipButton.Update();
	settingButton.Update();
	modeButton.Update();

	menuImg->Update();
	hpImg->Update();
	mpImg->Update();
}

void PlayerMenu::LateUpdate()
{
	// 付快胶 面倒 贸府
	charButton.LateUpdate();
	invButton.LateUpdate();
	skillButton.LateUpdate();
	questButton.LateUpdate();
	skipButton.LateUpdate();
	settingButton.LateUpdate();
	modeButton.LateUpdate();
}

void PlayerMenu::Render()
{
	charButton.Render();
	invButton.Render();
	skillButton.Render();
	questButton.Render();
	skipButton.Render();
	settingButton.Render();
	modeButton.Render();

	menuImg->Render();
	hpImg->Render();
	mpImg->Render();
}

void PlayerMenu::SetPlayerHMP(int _hp, int _mp)
{
	hpImg->scale = Vector2(158.0f * _hp / 100, 8.0f) * 2.0f;
	mpImg->scale = Vector2(167.0f * _mp / 100, 8.0f) * 2.0f;
}
