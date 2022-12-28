#pragma once
class InvButton : public ButtonUI
{
public:
	InvButton();
	~InvButton();

	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
private:
	PlayerInv*		pInv;
};


