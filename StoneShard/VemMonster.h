#pragma once
enum class MonsterState
{
	IDLE,
	MOVE,
	ATTACK,
	DEAD
};

class VemMonster
{
public:
	VemMonster();
	~VemMonster();

	void Update();
	void LateUpdate();
	void Render();

	void SetMonsterTile(Int2 tilePos, Int2 scale);
	Vector2 GetMonsterPos() { return monsCol->GetWorldPos(); }
	void SetMonsterPos(Vector2 pos) { monsCol->SetWorldPos(pos); }
	void ChangeMonsterSprite(int sourX, int destX);

	void MonsterAttack();
	void MonsterGetAttack(int damage);

	float attackTime;

private:
	ObRect*		monsCol;
	ObImage*	monsImg;

	int hp;
	MonsterState mState;
};
