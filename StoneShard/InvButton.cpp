#include "stdafx.h"

InvButton::InvButton()
{
	SetUIButton(L"s_gui_button_inventory/", Vector2(-540.0f, -412.0f));

	// Init Inventory
	pInv = new PlayerInv;
}

InvButton::~InvButton()
{
	SafeDelete(imgIdle);
	SafeDelete(imgMouseOn);
	SafeDelete(imgMouseDown);

	// Delete Inventory
	SafeDelete(pInv);
}

void InvButton::Update()
{
	ButtonUI::Update();
	pInv->Update();
}

void InvButton::LateUpdate()
{
	if (ButtonUI::ButtonPressed() || INPUT->KeyDown('I'))
	{
		pInv->isInvOpen = !pInv->isInvOpen;
	}
}

void InvButton::Render()
{
	ButtonUI::Render();
	pInv->Render();
}