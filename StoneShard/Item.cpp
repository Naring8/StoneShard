#include "stdafx.h"

Item::Item()
{
	{
		Detail* dragPants = new Detail;
		dragPants->itemName = "DragPants";
		dragPants->itemCol = new ObRect;
		dragPants->itemImg = new ObImage(L"s_player/s_inv_tatteredrags/idle.png");
		dragPants->itemCol->scale = dragPants->itemImg->scale = Vector2((float)dragPants->itemImg->imageSize.x, (float)dragPants->itemImg->imageSize.y) * 2.0f;
		dragPants->itemImg->SetParentRT(*dragPants->itemCol);
		dragPants->itemType = ItemType::ARMOR;

		dragPants->itemCol->pivot = OFFSET_LT;
		dragPants->itemImg->pivot = OFFSET_LT;

		dragPants->isClicked = false;
		dragPants->isEquiped = true;

		items.insert(pair<string, Detail*>("DragPants", dragPants));
	}
	{
		Detail* shackles = new Detail;
		shackles->itemName = "RustedShackles";
		shackles->itemCol = new ObRect;
		shackles->itemCol->SetWorldPos(Vector2(-500.0f, 0.0f));
		shackles->itemImg = new ObImage(L"s_player/s_inv_rustedshackles/idle.png");
		shackles->itemCol->scale = shackles->itemImg->scale = Vector2((float)shackles->itemImg->imageSize.x, (float)shackles->itemImg->imageSize.y) * 2.0f;
		shackles->itemImg->SetParentRT(*shackles->itemCol);
		shackles->itemType = ItemType::SHOES;

		shackles->itemCol->pivot = OFFSET_LT;
		shackles->itemImg->pivot = OFFSET_LT;

		shackles->isClicked = false;
		shackles->isEquiped = true;

		items.insert(pair<string, Detail*>("RustedShackles", shackles));
	}
}

Item::~Item()
{
	for (auto& i : items)
	{
		SafeDelete(i.second->itemCol);
		SafeDelete(i.second->itemImg);
	}
	items.clear();
}

void Detail::Update()
{
	itemCol->Update();
	itemImg->Update();
}

void Detail::LateUpdate()
{
	if (itemCol->Intersect(INPUT->GetMouseWorldPos()))
	{
		if (INPUT->KeyDown(VK_LBUTTON))
		{
			subMouseItem = itemCol->GetWorldPos() - INPUT->GetMouseWorldPos();

			isClicked = !isClicked;
		}
		if (isClicked)
		{
			itemCol->SetWorldPos(INPUT->GetMouseWorldPos() + subMouseItem);
		}
	}
}

void Detail::Render()
{
	itemImg->Render();
}

void Detail::SetItemPos(Vector2 _pos)
{
	itemCol->SetWorldPos(_pos);

	cout << itemCol->GetWorldPos().x << ", " << itemCol->GetWorldPos().y << endl;
	cout << itemImg->GetWorldPos().x << ", " << itemImg->GetWorldPos().y << endl;
}
