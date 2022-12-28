#pragma once
enum class PlayerState
{
	IDLE,
	MOVE,
	ATTACK,
	DEAD
};

class VerrenPlayer
{
public:
	VerrenPlayer();
	~VerrenPlayer();

	void Update();
	void LateUpdate();
	void Render();

	void SetPlayerTile(Int2 tilePos, Int2 scale);
	void SetPlayerPos(Vector2 pos) { plCol->SetWorldPos(pos); }
	Vector2	GetPlayerPos() { return plCol->GetWorldPos(); }
	ObRect* GetPlayerRect() { return plCol; }

	vector<Vector2>		entire;
	vector<Vector2>		GetPoint()
	{
		entire.resize(4);

		entire[0] = plCol->GetWorldPos() + Vector2(-plCol->scale.x * 0.5f, +plCol->scale.y * 0.5f);
		entire[1] = plCol->GetWorldPos() + Vector2(+plCol->scale.x * 0.5f, +plCol->scale.y * 0.5f);
		entire[2] = plCol->GetWorldPos() + Vector2(-plCol->scale.x * 0.5f, -plCol->scale.y * 0.5f);
		entire[3] = plCol->GetWorldPos() + Vector2(+plCol->scale.x * 0.5f, -plCol->scale.y * 0.5f);

		return entire;
	}

	void SetPlayerState();

	void PlayerAttack();
	void PlayerGetAttack();

	void ChangePlayerSprite(int sourX, int destX);

	bool	playerDead;
	float	attackTime;

private:
	PlayerMenu pMenu;

	ObRect* plCol;

	ObImage* VerrenDead;
	ObImage* body;
	ObImage* head;
	ObImage* pants;
	ObImage* shoes;

	ObImage* attack;
	ObImage* bloodHead;
	ObImage* bloodAttack;

	int hp;
	int mp;

	PlayerState pState;
};


