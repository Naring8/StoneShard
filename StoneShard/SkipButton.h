#pragma once
class SkipButton : public ButtonUI
{
public:
	SkipButton();
	~SkipButton();

	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

private:

};
