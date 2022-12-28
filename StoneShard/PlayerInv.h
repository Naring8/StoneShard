#pragma once
class PlayerInv
{
public:
	PlayerInv();
	~PlayerInv();

	void Update();
	void LateUpdate();
	void Render();

	bool	isInvOpen;

private:
	void SetItemsSlot();

private:
	ObImage* inventory;

	InventorySlot* head;
	InventorySlot* armor;
	InventorySlot* cape;

	InventorySlot* belt;
	InventorySlot* necklace;
	InventorySlot* glove;
	InventorySlot* boots;

	InventorySlot* ring1;
	InventorySlot* ring2;

	InventorySlot* mainWeapon;
	InventorySlot* subWeapon2;

	Item item;
	vector<string> pItems;
};
