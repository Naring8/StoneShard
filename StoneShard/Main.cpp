#include "stdafx.h"
#include "Main.h"

void Main::Init()
{
	{
		StartScene* temp = new StartScene();
		SCENE->AddScene("StartScene", temp);
	}
	SCENE->ChangeScene("StartScene");
}

void Main::Release()
{
}

void Main::Update()
{
	SCENE->Update();
}

void Main::LateUpdate()
{
	SCENE->LateUpdate();
}

void Main::Render()
{
	SCENE->Render();
}

void Main::ResizeScreen()
{
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
	app.SetAppName(L"StoneShard");
	app.SetInstance(instance);
	app.InitWidthHeight(1600.0f, 900.0f);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	SafeDelete(main);
	return wParam;
}

