#include "stdafx.h"

QuestButton::QuestButton()
{
	SetUIButton(L"s_gui_button_quests/", Vector2(-414.0f, -412.0f));
}

QuestButton::~QuestButton()
{
	SafeDelete(imgIdle);
	SafeDelete(imgMouseOn);
	SafeDelete(imgMouseDown);
}

void QuestButton::Update()
{
	ButtonUI::Update();
}

void QuestButton::LateUpdate()
{
	if (ButtonUI::ButtonPressed())
	{
	}
}

void QuestButton::Render()
{
	ButtonUI::Render();
}