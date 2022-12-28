#pragma once
class CharButton : public ButtonUI
{
public:
	CharButton();
	~CharButton();

	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

private:
	ObImage* charUI;
};
