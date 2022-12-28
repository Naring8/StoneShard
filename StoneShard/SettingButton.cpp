#include "stdafx.h"

SettingButton::SettingButton()
{
	SetUIButton(L"s_gui_button_settings/", Vector2(540.0f, -412.0f));
}

SettingButton::~SettingButton()
{
	SafeDelete(imgIdle);
	SafeDelete(imgMouseOn);
	SafeDelete(imgMouseDown);
}

void SettingButton::Update()
{
	ButtonUI::Update();
}

void SettingButton::LateUpdate()
{
	if (ButtonUI::ButtonPressed())
	{
	}
}

void SettingButton::Render()
{
	ButtonUI::Render();
}
