#pragma once
class SettingButton : public ButtonUI
{
public:
	SettingButton();
	~SettingButton();

	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

private:

};

