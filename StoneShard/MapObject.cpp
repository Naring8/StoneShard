#include "stdafx.h"

MapObject::MapObject()
{
	// Ã¶Ã¢
	for (int i = 0; i < 3; i++)
	{
		jail[i] = new ObImage(L"s_lattice1.png");
		jail[i]->scale = Vector2(77.0f, 39.0f) * 2.0f;
	}
	{
		jail[0]->SetWorldPos(Vector2(788.0f, 1160.0f));
		jail[1]->SetWorldPos(Vector2(1099.0f, 1160.0f));
		jail[2]->SetWorldPos(Vector2(1879.0f, 1160.0f));

		jail[3] = new ObImage(L"s_lattice2.png");
		jail[3]->scale = Vector2(77.0f, 40.0f) * 2.0f;
		jail[3]->SetWorldPos(Vector2(1567.0f, 1160.0f));

		jail[4] = new ObImage(L"s_lattice3.png");
		jail[4]->scale = Vector2(78.0f, 39.0f) * 2.0f;
		jail[4]->SetWorldPos(Vector2(838.0f, 800.0f));

		jail[5] = new ObImage(L"s_lattice4.png");
		jail[5]->scale = Vector2(78.0f, 39.0f) * 2.0f;
		jail[5]->SetWorldPos(Vector2(1150.0f, 800.0f));

		jail[6] = new ObImage(L"s_lattice5.png");
		jail[6]->scale = Vector2(78.0f, 39.0f) * 2.0f;
		jail[6]->SetWorldPos(Vector2(1618.0f, 800.0f));

		jail[7] = new ObImage(L"s_lattice6.png");
		jail[7]->scale = Vector2(78.0f, 39.0f) * 2.0f;
		jail[7]->SetWorldPos(Vector2(1930.0f, 800.0f));
	}

	// °¨¿Á ¹®
	for (int i = 0; i < 8; i++)
	{
		jailDoor[i].doorCol = new ObRect;
		jailDoor[i].doorImg = new ObImage(L"s_ldoor/JailDoor.png");
		jailDoor[i].doorImg->maxFrame.x = 4;
		jailDoor[i].doorImg->frame.x = 3;
		jailDoor[i].doorCol->scale = jailDoor[i].doorImg->scale = Vector2(28.0f, 52.0f) * 2.0f;
		jailDoor[i].doorImg->SetParentRT(*jailDoor[i].doorCol);
	}
	{
		jailDoor[0].doorCol->SetWorldPos(Vector2(890.0f, 1171.0f));
		jailDoor[1].doorCol->SetWorldPos(Vector2(1202.0f, 1171.0f));
		jailDoor[2].doorCol->SetWorldPos(Vector2(1670.0f, 1172.0f));
		jailDoor[3].doorCol->SetWorldPos(Vector2(1982.0f, 1171.0f));
		jailDoor[4].doorCol->SetWorldPos(Vector2(734.0f, 811.0f));
		jailDoor[5].doorCol->SetWorldPos(Vector2(1046.0f, 811.0f));
		jailDoor[6].doorCol->SetWorldPos(Vector2(1514.0f, 811.0f));
		jailDoor[7].doorCol->SetWorldPos(Vector2(1826.0f, 811.0f));
	}

	// ±âµÕ
	for (int i = 0; i < 4; i++)
	{
		pillar[i].pillarCol = new ObRect;
		pillar[i].pillarImg = new ObImage(L"s_twall7.png");

		pillar[i].pillarCol->scale = pillar[i].pillarImg->scale = Vector2(52.0f, 41.0f) * 2.0f;

		pillar[i].pillarImg->SetParentRT(*pillar[i].pillarCol);
	}
	{
		pillar[0].pillarCol->SetWorldPos(Vector2(656.0f, 1019.0f));
		pillar[1].pillarCol->SetWorldPos(Vector2(968.0f, 1019.0f));
		pillar[2].pillarCol->SetWorldPos(Vector2(1748.0f, 1019.0f));
		pillar[3].pillarCol->SetWorldPos(Vector2(2061.0f, 1019.0f));
	}

	// Å« ±âµÕ
	{
		pillarL.pillarCol = new ObRect;
		pillarL.pillarImg = new ObImage(L"s_twall8.png");
		pillarL.pillarCol->scale = pillarL.pillarImg->scale = Vector2(130.0f, 43.0f) * 2.0f;
		pillarL.pillarCol->SetWorldPos(Vector2(1358.0f, 1017.0f));
		pillarL.pillarImg->SetParentRT(*pillarL.pillarCol);
	}

	for (int i = 0; i < 20; i++)
	{
		wall[i].wallCol = new ObRect;

		if(i < 10)		// 0 ~ 9
			wall[i].wallImg = new ObImage(L"s_dungeon_upwall/ObTile" + to_wstring(i) + L".png");
		else if (i < 14)	// 10 ~ 13 (4°³)
			wall[i].wallImg = new ObImage(L"s_dungeon_upwall/ObTile10.png");
		else if(i < 18)		// 14 ~ 17 (4°³)
			wall[i].wallImg = new ObImage(L"s_dungeon_upwall/ObTile12.png");
		else				// 18 ~ 19 (2°³)
			wall[i].wallImg = new ObImage(L"s_dungeon_upwall/ObTile11.png");

		wall[i].wallCol->scale = wall[i].wallImg->scale = Vector2((float)wall[i].wallImg->imageSize.x, (float)wall[i].wallImg->imageSize.y) * 2.0f;
		wall[i].wallImg->SetParentRT(*wall[i].wallCol);
		wall[i].wallImg->color.w = 0.2f;
	}
	{
		wall[0].wallCol->SetWorldPos(Vector2(1566.0f, 1526.0f));
		wall[1].wallCol->SetWorldPos(Vector2(2242.0f, 797.0f));
		wall[2].wallCol->SetWorldPos(Vector2(1150.0f, 2379.0f));
		wall[3].wallCol->SetWorldPos(Vector2(578.0f, 2384.0f));
		wall[4].wallCol->SetWorldPos(Vector2(1358.0f, 821.0f));
		wall[5].wallCol->SetWorldPos(Vector2(552.0f, 822.0f));
		wall[6].wallCol->SetWorldPos(Vector2(2034.0f, 1640.0f));
		wall[7].wallCol->SetWorldPos(Vector2(1773.0f, 2360.0f));
		wall[8].wallCol->SetWorldPos(Vector2(2215.5f, 1239.0f));
		wall[9].wallCol->SetWorldPos(Vector2(2371.0f, 1240.0f));

		wall[10].wallCol->SetWorldPos(Vector2(812.0f, 642.0f));
		wall[11].wallCol->SetWorldPos(Vector2(1124.0f, 642.0f));
		wall[12].wallCol->SetWorldPos(Vector2(1592.0f, 642.0f));
		wall[13].wallCol->SetWorldPos(Vector2(1904.0f, 642.0f));

		wall[14].wallCol->SetWorldPos(Vector2(968.0f, 822.0f));
		wall[15].wallCol->SetWorldPos(Vector2(1748.0f, 822.0f));
		wall[16].wallCol->SetWorldPos(Vector2(1852.0f, 1704.0f));
		wall[17].wallCol->SetWorldPos(Vector2(552.0f, 2017.0f));

		wall[18].wallCol->SetWorldPos(Vector2(318.0f, 1890.0f));
		wall[19].wallCol->SetWorldPos(Vector2(786.0f, 1890.0f));
	}
}

MapObject::~MapObject()
{
	for (int i = 0; i < 8; i++)
		SafeDelete(jail[i]);
	for (int i = 0; i < 8; i++)
	{
		SafeDelete(jailDoor[i].doorCol);
		SafeDelete(jailDoor[i].doorImg);
	}
	for (int i = 0; i < 4; i++)
	{
		SafeDelete(pillar[i].pillarCol);
		SafeDelete(pillar[i].pillarImg);
	}
	SafeDelete(pillarL.pillarCol);
	SafeDelete(pillarL.pillarImg);

	for (int i = 0; i < 20; i++)
	{
		SafeDelete(wall[i].wallCol);
		SafeDelete(wall[i].wallImg);
	}
}

void MapObject::Update()
{
	for (int i = 0; i < 8; i++)
		jail[i]->Update();
	for (int i = 0; i < 8; i++)
	{
		jailDoor[i].doorCol->Update();
		jailDoor[i].doorImg->Update();
	}
	for (int i = 0; i < 4; i++)
	{
		pillar[i].pillarCol->Update();
		pillar[i].pillarImg->Update();
	}
	pillarL.pillarCol->Update();
	pillarL.pillarImg->Update();

	for (int i = 0; i < 20; i++)
	{
		wall[i].wallCol->Update();
		wall[i].wallImg->Update();
	}
}

void MapObject::LateUpdate()
{
	// Small Pillar
	for (int i = 0; i < 4; i++)
	{
		if (pillar[i].pillarCol->Intersect(playerCol))
		{
			if (pillar[i].pillarImg->color.w < 0.0f)
				pillar[i].pillarImg->color.w = 0.0f;

			else if (pillar[i].pillarImg->color.w > 0.0f)
				pillar[i].pillarImg->color.w -= 3.0f * DELTA;
		}
		else if (pillar[i].pillarImg->color.w < 0.5f)
		{
			pillar[i].pillarImg->color.w += 3.0f * DELTA;

			if (pillar[i].pillarImg->color.w > 0.5f)
				pillar[i].pillarImg->color.w = 0.5f;
		}
	}
	// Large Pillar
	if (pillarL.pillarCol->Intersect(playerCol))
	{
		if (pillarL.pillarImg->color.w < 0.0f)
			pillarL.pillarImg->color.w = 0.0f;

		else if (pillarL.pillarImg->color.w > 0.0f)
			pillarL.pillarImg->color.w -= 3.0f * DELTA;
	}
	else if (pillarL.pillarImg->color.w < 0.5f)
	{
		pillarL.pillarImg->color.w += 3.0f * DELTA;

		if (pillarL.pillarImg->color.w > 0.5f)
			pillarL.pillarImg->color.w = 0.5f;
	}
}

void MapObject::Render()
{
	for (int i = 0; i < 8; i++)
		jail[i]->Render();
	for (int i = 0; i < 8; i++)
		jailDoor[i].doorImg->Render();
	for (int i = 0; i < 4; i++)
		pillar[i].pillarImg->Render();
	pillarL.pillarImg->Render();

	for (int i = 0; i < 20; i++)
		wall[i].wallImg->Render();
}