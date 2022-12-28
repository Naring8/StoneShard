#pragma once
class StartScene : public Scene
{
private:
	ObImage* bg;
	ObTileMap* map;
	MapObject* mapOb;
	Sound* bgm;
	VerrenPlayer* player;
	VemMonster*	  monster;

	//��ã��� ����
	vector<Tile*> PlWay;
	vector<Tile*> MsWay;

	//�̵���ų ��ġ
	Vector2 plDest;
	Vector2 plSour;

	Vector2 msDest;
	Vector2 msSour;

	//����
	float   g, f;

	Int2	moveTileIdx;

	int costP2M;
	bool turn;

public:
	StartScene();
	~StartScene();
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;

	void PlayerMove();
	void MonsterMove();
};

