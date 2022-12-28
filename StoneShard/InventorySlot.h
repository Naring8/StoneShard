#pragma once
class InventorySlot
{
public:
	InventorySlot(wstring imgPath, Vector2 pos);
	~InventorySlot();

	void Update();
	void LateUpdate();
	void Render();

	void SetSlotItem(ObImage* _itemImg);

private:
	ObRect*		slotCol;
	ObImage*	slotImg;

	ObImage*	itemImg;

	ObImage*	idleSlot;
	ObImage*	errorSlot;
	ObImage*	correctSlot;
};
