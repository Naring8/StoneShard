#include "stdafx.h"

InventorySlot::InventorySlot(wstring imgPath, Vector2 pos)
{
	slotCol = new ObRect;
	slotImg = new ObImage(imgPath + L"/idle.png");

	itemImg = nullptr;

	idleSlot = new ObImage(imgPath + L"/idlebg.png");
	errorSlot = new ObImage(imgPath + L"/errorbg.png");
	correctSlot = new ObImage(imgPath + L"/correctbg.png");

	slotCol->pivot = OFFSET_LT;
	slotImg->pivot = OFFSET_LT;

	idleSlot->pivot = OFFSET_LT;
	errorSlot->pivot = OFFSET_LT;
	correctSlot->pivot = OFFSET_LT;

	if (slotImg != nullptr)
	{
		slotCol->scale = slotImg->scale = idleSlot->scale = errorSlot->scale = correctSlot->scale =	
																	Vector2((float)slotImg->imageSize.x, (float)slotImg->imageSize.y) * 2.0f;
		slotCol->SetWorldPos(pos);
		slotImg->SetParentRT(*slotCol);

		idleSlot->SetParentRT(*slotCol);
		errorSlot->SetParentRT(*slotCol);
		correctSlot->SetParentRT(*slotCol);
	}

	slotCol->space = SPACE::SCREEN;
	slotImg->space = SPACE::SCREEN;

	idleSlot->space = SPACE::SCREEN;
	errorSlot->space = SPACE::SCREEN;
	correctSlot->space = SPACE::SCREEN;
}

InventorySlot::~InventorySlot()
{
	SafeDelete(slotCol);
	SafeDelete(slotImg);

	SafeDelete(idleSlot);
	SafeDelete(errorSlot);
	SafeDelete(correctSlot);
}

void InventorySlot::Update()
{
	slotCol->Update();
	slotImg->Update();

	if (itemImg != nullptr)
	{
		//itemImg->Update();

		idleSlot->Update();
		//errorSlot->Update();
		//correctSlot->Update();
	}
}

void InventorySlot::LateUpdate()
{
	if (slotCol->IntersectScreenMouse(INPUT->GetMouseScreenPos()))
	{

	}
}

void InventorySlot::Render()
{
	//slotCol->Render();
	slotImg->Render();
	if (itemImg != nullptr)
	{
		//itemImg->Render();

		idleSlot->Render();
		//errorSlot->Render();
		//correctSlot->Render();
	}
}

void InventorySlot::SetSlotItem(ObImage* _itemImg)
{
	this->itemImg = _itemImg;

	itemImg->pivot = OFFSET_N;
	itemImg->SetParentRT(*slotCol);
	itemImg->space = SPACE::SCREEN;
}
