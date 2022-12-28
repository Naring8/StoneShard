#pragma once

enum class ItemType
{
	MAINWEAPON,
	SUBWEAPON,
	ARMOR,
	CAPE,
	HAT,
	BELT,
	GLOVE,
	RING,
	NECKLACE,
	SHOES,

	FOOD
};

struct Detail
{
	string		itemName;
	ObImage*	itemImg;
	ObRect*		itemCol;
	ItemType	itemType;

	bool		isClicked;
	bool		isEquiped;
	Vector2		subMouseItem;

	void Update();
	void LateUpdate();
	void Render();

	void SetItemPos(Vector2 _pos);
};

class Item
{
	friend class PlayerInv;
public:
	Item();
	~Item();

private:
	map<string, Detail*> items;
};

