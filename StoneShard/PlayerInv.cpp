#include "stdafx.h"

PlayerInv::PlayerInv()
{
	inventory = new ObImage(L"s_gui_button_inventory/fasttest.png");
	inventory->SetWorldPosX(app.GetHalfWidth());
	inventory->scale = Vector2(342.0f, 450.0f) * 2.0f;
	inventory->pivot = OFFSET_R;
	inventory->space = SPACE::SCREEN;

	head = new InventorySlot(L"s_gui_button_inventory/s_bghead", Vector2(514.0f, 264.0f));
	armor = new InventorySlot(L"s_gui_button_inventory/s_bgarmor", Vector2(298.0f, 264.0f));
	cape = new InventorySlot(L"s_gui_button_inventory/s_bgcape", Vector2(406.0f, 264.0f));
	belt = new InventorySlot(L"s_gui_button_inventory/s_bgbelt", Vector2(514.0f, 156.0f));
	necklace = new InventorySlot(L"s_gui_button_inventory/s_bgneck", Vector2(460.0f, 102.0f));
	glove = new InventorySlot(L"s_gui_button_inventory/s_bggloves", Vector2(298.0f, 102.0f));
	boots = new InventorySlot(L"s_gui_button_inventory/s_bgboots", Vector2(514.0f, 102.0f));
	ring1 = new InventorySlot(L"s_gui_button_inventory/s_bgring", Vector2(406.0f, 102.0f));
	ring2 = new InventorySlot(L"s_gui_button_inventory/s_bgring", Vector2(406.0f, 48.0f));
	mainWeapon = new InventorySlot(L"s_gui_button_inventory/s_bgweapon1", Vector2(190.0f, 264.0f));
	subWeapon2 = new InventorySlot(L"s_gui_button_inventory/s_bgweapon2", Vector2(622.0f, 264.0f));

	isInvOpen = false;

	pItems.push_back("DragPants");
	pItems.push_back("RustedShackles");
}

PlayerInv::~PlayerInv()
{
	SafeDelete(inventory);

	SafeDelete(head);
	SafeDelete(armor);
	SafeDelete(cape);
	SafeDelete(belt);
	SafeDelete(necklace);
	SafeDelete(glove);
	SafeDelete(boots);
	SafeDelete(ring1);
	SafeDelete(ring2);
	SafeDelete(mainWeapon);
	SafeDelete(subWeapon2);
}

void PlayerInv::Update()
{
	if (!isInvOpen)
		return;
	SetItemsSlot();

	head->Update();
	armor->Update();
	cape->Update();
	belt->Update();
	necklace->Update();
	glove->Update();
	boots->Update();
	ring1->Update();
	ring2->Update();
	mainWeapon->Update();
	subWeapon2->Update();

	inventory->Update();

	for (auto& p : pItems)
	{
		item.items.find(p)->second->Update();
	}
}

void PlayerInv::LateUpdate()
{
	for (auto& p : pItems)
	{
		item.items.find(p)->second->LateUpdate();
	}
}

void PlayerInv::Render()
{
	if (!isInvOpen)
		return;

	inventory->Render();

	head->Render();
	armor->Render();
	cape->Render();
	belt->Render();
	necklace->Render();
	glove->Render();
	boots->Render();
	ring1->Render();
	ring2->Render();
	mainWeapon->Render();
	subWeapon2->Render();

	for (auto& p : pItems)
	{
		item.items.find(p)->second->Render();
	}
}

void PlayerInv::SetItemsSlot()
{
	for (auto& p : pItems)
	{
		if (item.items.find(p)->second->isEquiped)
		{
			switch (item.items.find(p)->second->itemType)
			{
			case ItemType::MAINWEAPON:
				break;
			case ItemType::SUBWEAPON:
				break;
			case ItemType::ARMOR:
				armor->SetSlotItem(item.items.find(p)->second->itemImg);
				break;
			case ItemType::CAPE:
				break;
			case ItemType::HAT:
				break;
			case ItemType::BELT:
				break;
			case ItemType::GLOVE:
				break;
			case ItemType::RING:
				break;
			case ItemType::NECKLACE:
				break;
			case ItemType::SHOES:
				break;
			case ItemType::FOOD:
				break;
			default:
				break;
			}
		}
	}
}

