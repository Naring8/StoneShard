#pragma once
class ModeButton : public ButtonUI
{
public:
	ModeButton();
	~ModeButton();

	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

private:

};

