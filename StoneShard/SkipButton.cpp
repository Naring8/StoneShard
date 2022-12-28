#include "stdafx.h"

SkipButton::SkipButton()
{
	SetUIButton(L"s_gui_button_skipturn/", Vector2(498.0f, -412.0f));
}

SkipButton::~SkipButton()
{
	SafeDelete(imgIdle);
	SafeDelete(imgMouseOn);
	SafeDelete(imgMouseDown);
}

void SkipButton::Update()
{
	ButtonUI::Update();
}

void SkipButton::LateUpdate()
{
	if (ButtonUI::ButtonPressed())
	{
	}
}

void SkipButton::Render()
{
	ButtonUI::Render();
}