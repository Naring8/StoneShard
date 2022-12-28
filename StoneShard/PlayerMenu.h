#pragma once
class PlayerMenu
{
public:
	PlayerMenu();
	~PlayerMenu();

	void Update();
	void LateUpdate();
	void Render();

	void SetPlayerHMP(int _hp, int _mp);

private:
	// Menu UI
	ObImage* menuImg;
	CharButton		charButton;
	InvButton		invButton;
	SkillButton		skillButton;
	QuestButton		questButton;
	SkipButton		skipButton;
	SettingButton	settingButton;
	ModeButton		modeButton;

	ObImage*	hpImg;
	ObImage*	mpImg;

	Vector2 hpPos;
	Vector2 mpPos;
};