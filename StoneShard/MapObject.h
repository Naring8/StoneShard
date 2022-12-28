#pragma once
struct JailDoor
{
	ObRect* doorCol;
	ObImage* doorImg;
};
struct Pillar
{
	ObRect*	 pillarCol;
	ObImage* pillarImg;
};
struct Wall
{
	ObRect*	 wallCol;
	ObImage* wallImg;
};

class MapObject
{
public:
	MapObject();
	~MapObject();

	void Update();
	void LateUpdate();
	void Render();

	void SetPlayerCol(VerrenPlayer* _player) { this->playerCol = _player->GetPlayerRect(); }
private:
	// �浹 ��ü
	ObRect*  playerCol;

	// �� ������Ʈ
	ObImage* jail[8];
	JailDoor jailDoor[8];

	Pillar pillar[4];
	Pillar pillarL;

	Wall wall[20];

	Vector2 pos;
};
