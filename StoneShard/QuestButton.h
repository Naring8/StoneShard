#pragma once
class QuestButton : public ButtonUI
{
public:
	QuestButton();
	~QuestButton();

	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

private:

};

