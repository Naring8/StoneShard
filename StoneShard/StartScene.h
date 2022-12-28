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

	//길찾기용 변수
	vector<Tile*> PlWay;
	vector<Tile*> MsWay;

	//이동시킬 위치
	Vector2 plDest;
	Vector2 plSour;

	Vector2 msDest;
	Vector2 msSour;

	//비율
	float   g, f;

	Int2	moveTileIdx;

	int costP2M;
	bool turn;

public:
	StartScene();
	~StartScene();
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;

	void PlayerMove();
	void MonsterMove();
};

