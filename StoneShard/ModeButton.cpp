#include "stdafx.h"

ModeButton::ModeButton()
{
	SetUIButton(L"s_gui_button_change_modes/", Vector2(445.0f, -412.0f));
}

ModeButton::~ModeButton()
{
	SafeDelete(imgIdle);
	SafeDelete(imgMouseOn);
	SafeDelete(imgMouseDown);
}

void ModeButton::Update()
{
	ButtonUI::Update();
}

void ModeButton::LateUpdate()
{
	if (ButtonUI::ButtonPressed())
	{
	}
}

void ModeButton::Render()
{
	ButtonUI::Render();
}

