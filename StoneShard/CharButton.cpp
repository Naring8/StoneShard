#include "stdafx.h"

CharButton::CharButton()
{
	SetUIButton(L"s_gui_button_char/", Vector2(-498.0f, -412.0f));

	charUI = new ObImage(L"s_gui_button_char/character_menu.png");
	charUI->scale = Vector2(342.0f, 450.0f) * 2.0f;
	charUI->pivot = OFFSET_L;
	charUI->SetWorldPosX(-app.GetHalfWidth());
	charUI->space = SPACE::SCREEN;

	charUI->isVisible = false;
}

CharButton::~CharButton()
{
	SafeDelete(imgIdle);
	SafeDelete(imgMouseOn);
	SafeDelete(imgMouseDown);

	SafeDelete(charUI);
}

void CharButton::Update()
{
	ButtonUI::Update();
	charUI->Update();
	if (INPUT->KeyDown(VK_ESCAPE))
		charUI->isVisible = false;
}

void CharButton::LateUpdate()
{
	if (ButtonUI::ButtonPressed())
		charUI->isVisible = !charUI->isVisible;
}

void CharButton::Render()
{
	charUI->Render();
	ButtonUI::Render();
}
