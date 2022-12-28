#include "stdafx.h"

StartScene::StartScene()
{
}

StartScene::~StartScene()
{
}

void StartScene::Init()
{
	// MAP
	map = new ObTileMap;
	bg = new ObImage(L"Dungeon_Map.png");
	bg->pivot = OFFSET_LB;
	bg->scale = Vector2(2080.0f, 2080.0f) * 2.0f;
	mapOb = new MapObject;
	bgm = new Sound;
	bgm->AddSound("prologueDungeon.wav", "DungeonMain", true);
	bgm->SetVolume("DungeonMain", 0.5f);
	bgm->Play("DungeonMain");

	map->SetWorldPos(Vector2(-app.GetHalfWidth(), -app.GetHalfHeight()));
	bg->SetWorldPos(Vector2(-app.GetHalfWidth(), -app.GetHalfHeight()));

	// OBJECTS
	player = new VerrenPlayer;
	player->SetPlayerTile(Int2(38, 32), Int2(52, 52));

	monster = new VemMonster;
	monster->SetMonsterTile(Int2(46, 28), Int2(52, 52));

	map->file = "traffic.txt";
	map->Load();
	map->CreateTileCost();

	mapOb->SetPlayerCol(player);

	costP2M = INT_MAX;
	turn = true;
}

void StartScene::Release()
{
	SafeDelete(map);
	SafeDelete(bg);
	SafeDelete(mapOb);
	bgm->DeleteSound("DungeonMain");
	SafeDelete(bgm);

	SafeDelete(player);
	SafeDelete(monster);
}

void StartScene::Update()
{
	ImGui::Text("FPS : %d", TIMER->GetFramePerSecond());

	// 턴제 RPG
	turn ? PlayerMove() : MonsterMove();

	map->Update();
	bg->Update();
	mapOb->Update();
	bgm->Update();

	player->Update();
	CAM->position = player->GetPlayerPos();

	monster->Update();
}

void StartScene::LateUpdate()
{
	Int2 plTileIdx;
	vector<Vector2> foot = player->GetPoint();

	mapOb->LateUpdate();
	player->LateUpdate();
}

void StartScene::Render()
{
	map->Render();
	bg->Render();
	mapOb->Render();

	player->Render();
	monster->Render();
}

void StartScene::ResizeScreen()
{
}

void StartScene::PlayerMove()
{
	// 기본 이동
	if (INPUT->KeyDown(VK_LBUTTON) && PlWay.empty() && monster->attackTime <= 0.0f)
	{
		//   출발점, 도착점
		Int2 sour, dest, monsdest;
		//찾았는가?
		bool isFind;
		isFind = map->WorldPosToTileIdx(player->GetPlayerPos(), sour);
		isFind &= map->WorldPosToTileIdx(INPUT->GetMouseWorldPos(), dest);

		if (isFind)
		{
			map->WorldPosToTileIdx(monster->GetMonsterPos(), monsdest);
			if ((dest == monsdest) && (costP2M < 15))
			{
				player->attackTime = 0.5f;	// 0.5초 동안 공격 모션
				player->PlayerAttack();
				turn = false;
			}
			else if (map->PathFinding(sour, dest, PlWay))
			{
				// 플레이어 이동 방향에 따른 스프라이트 y축 대칭이동
				player->ChangePlayerSprite(sour.x, dest.x);

				g = 0.0f;
				plSour = player->GetPlayerPos();
				PlWay.pop_back(); //출발지 빼기
				plDest = PlWay.back()->Pos;
			}
		}
	}

	//가야될 길이 존재할 때
	if (!PlWay.empty())
	{
		player->SetPlayerPos(Utility::Lerp(plSour, plDest, g));
		g += DELTA * 3.0f;


		//도착지를 지났을때
		if (g > 1.0f)
		{
			Sleep(100);
			g = 0.0f;
			plSour = plDest;
			PlWay.pop_back(); // 맨뒷길 빼기
			costP2M = map->CostFinding(monster->GetMonsterPos(), player->GetPlayerPos());	// 플레이어와 몬스터 비용 비교

			if (!PlWay.empty())
				plDest = PlWay.back()->Pos;

			// 몬스터가 근처에 있을 때
			if ((costP2M < 70))
			{
				PlWay.clear();
				turn = false;
			}
		}
	}
}

void StartScene::MonsterMove()
{
	if (MsWay.empty() && (costP2M < 70) && player->attackTime <= 0.0f)
	{
		//   출발점, 도착점
		Int2 sour, dest;
		//찾았는가?
		bool isFind;
		isFind = map->WorldPosToTileIdx(monster->GetMonsterPos(), sour);
		isFind &= map->WorldPosToTileIdx(player->GetPlayerPos(), dest);

		if (isFind)
		{
			if (costP2M < 15)
			{
				monster->attackTime = 0.5f;	// 0.5초 동안 공격 모션
				monster->MonsterAttack();
				turn = true;
			}
			if (map->PathFinding(sour, dest, MsWay))
			{
				// 몬스터 이동 방향에 따른 스프라이트 y축 대칭이동
				monster->ChangeMonsterSprite(sour.x, dest.x);

				f = 0.0f;
				msSour = monster->GetMonsterPos();
				MsWay.pop_back(); //출발지 빼기
				msDest = MsWay.back()->Pos;
			}
		}
	}

	//가야될 길이 존재할 때
	if (!MsWay.empty())
	{
		monster->SetMonsterPos(Utility::Lerp(msSour, msDest, f));
		f += DELTA * 3.0f;

		//도착지를 지났을때
		if (f > 1.0f)
		{
			Sleep(100);
			f = 0.0f;
			msSour = msDest;
			MsWay.clear();
			costP2M = map->CostFinding(monster->GetMonsterPos(), player->GetPlayerPos());	// 플레이어와 몬스터 비용 비교

			turn = true;
		}
	}
}
