#include "stdafx.h"

SkillButton::SkillButton()
{
	SetUIButton(L"s_gui_button_skills/", Vector2(-456.0f, -412.0f));
}

SkillButton::~SkillButton()
{
	SafeDelete(imgIdle);
	SafeDelete(imgMouseOn);
	SafeDelete(imgMouseDown);
}

void SkillButton::Update()
{
	ButtonUI::Update();
}

void SkillButton::LateUpdate()
{
	if (ButtonUI::ButtonPressed())
	{
	}
}

void SkillButton::Render()
{
	ButtonUI::Render();
}
