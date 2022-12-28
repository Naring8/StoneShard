#pragma once
class ButtonUI
{
private:
	bool		rangeDown;

protected:
	ObRect		imgCol;

	ObImage*	imgIdle;
	ObImage*	imgMouseOn;
	ObImage*	imgMouseDown;

public:
	virtual void Update();
	virtual void LateUpdate() = 0;
	virtual void Render();

	void SetUIButton(wstring path, Vector2 pos);
	bool ButtonPressed();
};

