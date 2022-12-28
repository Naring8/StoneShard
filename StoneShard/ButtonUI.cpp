#include "stdafx.h"

void ButtonUI::Update()
{
	imgCol.Update();

	imgIdle->Update();
	imgMouseOn->Update();
	imgMouseDown->Update();
}

void ButtonUI::Render()
{
	//imgCol.Render();

	imgIdle->Render();
	imgMouseOn->Render();
	imgMouseDown->Render();
}

void ButtonUI::SetUIButton(wstring path, Vector2 pos)
{
	// Init
	imgCol.isFilled = false;
	imgCol.isVisible = false;

	imgIdle = new ObImage(path + L"idle.png");
	imgMouseOn = new ObImage(path + L"on.png");
	imgMouseDown = new ObImage(path + L"down.png");

	imgMouseOn->isVisible = false;
	imgMouseDown->isVisible = false;

	// Space
	imgCol.space = SPACE::SCREEN;
	imgIdle->space = SPACE::SCREEN;
	imgMouseOn->space = SPACE::SCREEN;
	imgMouseDown->space = SPACE::SCREEN;

	// Position
	imgCol.SetWorldPos(pos);

	// Scale
	
	imgCol.scale = Vector2((float)imgIdle->imageSize.x, (float)imgIdle->imageSize.y) * 2.0f;

	imgIdle->scale = imgCol.scale;
	imgMouseOn->scale = imgCol.scale;
	imgMouseDown->scale = imgCol.scale;

	// SetParent
	imgIdle->SetParentRT(imgCol);
	imgMouseOn->SetParentRT(imgCol);
	imgMouseDown->SetParentRT(imgCol);
}

bool ButtonUI::ButtonPressed()
{
	if (imgCol.IntersectScreenMouse(INPUT->GetMouseScreenPos()))
	{
		if (INPUT->KeyDown(VK_LBUTTON))
			rangeDown = true;
		else if (INPUT->KeyPress(VK_LBUTTON) && rangeDown)
		{
			imgIdle->isVisible = false;
			imgMouseOn->isVisible = false;
			imgMouseDown->isVisible = true;
		}
		else if (INPUT->KeyUp(VK_LBUTTON) && rangeDown)
		{
			// 각자가 원하는 곳으로 이동
			return true;
		}
		else
		{
			imgIdle->isVisible = false;
			imgMouseOn->isVisible = true;
			imgMouseDown->isVisible = false;
		}
	}
	else
	{
		imgIdle->isVisible = true;
		imgMouseOn->isVisible = false;
		imgMouseDown->isVisible = false;

		rangeDown = false;
	}

	return false;
}