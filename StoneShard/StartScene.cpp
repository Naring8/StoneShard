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

	// ���� RPG
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
	// �⺻ �̵�
	if (INPUT->KeyDown(VK_LBUTTON) && PlWay.empty() && monster->attackTime <= 0.0f)
	{
		//   �����, ������
		Int2 sour, dest, monsdest;
		//ã�Ҵ°�?
		bool isFind;
		isFind = map->WorldPosToTileIdx(player->GetPlayerPos(), sour);
		isFind &= map->WorldPosToTileIdx(INPUT->GetMouseWorldPos(), dest);

		if (isFind)
		{
			map->WorldPosToTileIdx(monster->GetMonsterPos(), monsdest);
			if ((dest == monsdest) && (costP2M < 15))
			{
				player->attackTime = 0.5f;	// 0.5�� ���� ���� ���
				player->PlayerAttack();
				turn = false;
			}
			else if (map->PathFinding(sour, dest, PlWay))
			{
				// �÷��̾� �̵� ���⿡ ���� ��������Ʈ y�� ��Ī�̵�
				player->ChangePlayerSprite(sour.x, dest.x);

				g = 0.0f;
				plSour = player->GetPlayerPos();
				PlWay.pop_back(); //����� ����
				plDest = PlWay.back()->Pos;
			}
		}
	}

	//���ߵ� ���� ������ ��
	if (!PlWay.empty())
	{
		player->SetPlayerPos(Utility::Lerp(plSour, plDest, g));
		g += DELTA * 3.0f;


		//�������� ��������
		if (g > 1.0f)
		{
			Sleep(100);
			g = 0.0f;
			plSour = plDest;
			PlWay.pop_back(); // �ǵޱ� ����
			costP2M = map->CostFinding(monster->GetMonsterPos(), player->GetPlayerPos());	// �÷��̾�� ���� ��� ��

			if (!PlWay.empty())
				plDest = PlWay.back()->Pos;

			// ���Ͱ� ��ó�� ���� ��
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
		//   �����, ������
		Int2 sour, dest;
		//ã�Ҵ°�?
		bool isFind;
		isFind = map->WorldPosToTileIdx(monster->GetMonsterPos(), sour);
		isFind &= map->WorldPosToTileIdx(player->GetPlayerPos(), dest);

		if (isFind)
		{
			if (costP2M < 15)
			{
				monster->attackTime = 0.5f;	// 0.5�� ���� ���� ���
				monster->MonsterAttack();
				turn = true;
			}
			if (map->PathFinding(sour, dest, MsWay))
			{
				// ���� �̵� ���⿡ ���� ��������Ʈ y�� ��Ī�̵�
				monster->ChangeMonsterSprite(sour.x, dest.x);

				f = 0.0f;
				msSour = monster->GetMonsterPos();
				MsWay.pop_back(); //����� ����
				msDest = MsWay.back()->Pos;
			}
		}
	}

	//���ߵ� ���� ������ ��
	if (!MsWay.empty())
	{
		monster->SetMonsterPos(Utility::Lerp(msSour, msDest, f));
		f += DELTA * 3.0f;

		//�������� ��������
		if (f > 1.0f)
		{
			Sleep(100);
			f = 0.0f;
			msSour = msDest;
			MsWay.clear();
			costP2M = map->CostFinding(monster->GetMonsterPos(), player->GetPlayerPos());	// �÷��̾�� ���� ��� ��

			turn = true;
		}
	}
}
