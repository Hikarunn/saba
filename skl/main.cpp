#include<DxLib.h>
#include<cassert>
#include<string>
#include<sstream>
#include<iomanip>
#include"Debug.h"
#include"Singleton.h"
#include"Game.h"
#include"Scene.h"
#include"Player.h"
#include"Enemy.h"
#include"Geometry.h"

struct Vector2 {
	float x, y;
};

using Position2 = Vector2;


struct Rect {
	Position2 center;
	float w, h;

	float
		 Left()const {
		return center.x - w;
	}
	float
		Top()const {
		return center.y - h;
	}
	float
		Right()const {
		return center.x + w;
	}
	float
		Bottom()const {
		return center.y + h;
	}
	float
		Width()const {
		return w * 2.0f;
	}
	float
		Height() const {
		return h * 2.0f;
	}
};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetGraphMode(1280, 720, 32);
	SetWindowText(L"2016008_è¨î®ós");
	ChangeWindowMode(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	Rect rcA = { 200,200,50,50 };
	char keystate[256];

	
	int graphH[6] = {};
	//wchar_t path[100];
	for (int i = 0; i < 6; i++) {
		std::wostringstream pathOss;
		pathOss << L"Asset/Adventurer-1.5/Individual Sprites/adventurer-attack2-";
		pathOss << std::setw(2) << std::setfill(L"0");
		pathOss << i << L".png";
			
		//auto graphH = DxLib::LoadGraph(L"../../../Asset/Adventurer-1.5/idle.png");//Individual Sprites/adventurer-idle-00.png");
		/*wsprintf(path, L"Asset/Adventurer-1.5/Individual Sprites/adventurer-attack2-%02d.png", i);
		
		graphH[i] = DxLib::LoadGraph(path);*/
		graphH[i] = DxLib::LoadGraph(pathOss.str(). c_str());
		assert(graphH[i] != -1);
	}
	

	unsigned int frame = 0;
	int lastMouseInput = GetMouseInput();
	bool flipFlg = false;
	

	while (ProcessMessage() != -1) {
		
		ClearDrawScreen();
		DrawString(100, 100, L"Hello World", 0xffffff);

		GetHitKeyStateAll(keystate);
		constexpr float speed = 4.0f;
		if (keystate[KEY_INPUT_LEFT]) {
			rcA.center.x -= speed;
		}

		if (keystate[KEY_INPUT_RIGHT]) {
			rcA.center.x += speed;
		}
		if (keystate[KEY_INPUT_UP]) {
			rcA.center.y -= speed;
		}
		if (keystate[KEY_INPUT_DOWN]) {
			rcA.center.y += speed;
		}

		constexpr size_t block_size = 32;
		const auto count = 1080 / block_size;
		int x = 0;
		int y = 240;
		Position2 p0(x. y);
		for (int i = 1; i <= count; i++)
		{
			auto nextX = block_size * i;
			auto nextY = 240 + 100 * sinf(0.5f * (float)nextX * DX_PI_F / 180.0f);
			x = nextX;
			y = nextY;
		}

		DrawBox(rcA.Left(), rcA.Top(),
			rcA.Right(), rcA.Bottom(), 0xffffff, true);
		DrawFormatString(10, 10, 0xffffaa, L"x=%d, y=%d",(int) rcA.center.x,(int) rcA.center.y);
		
		int srcX = 51 * (frame / 10);
		int srcY = 0;
	/*	DrawRectRotaGraph(rcA.Right() + 50, rcA.Bottom() + 50,
			srcX,srcY,49,36,3.0f,0.0f, graphH, true);*/

		int mx, my;
		GetMousePoint(&mx, &my);

		auto currentMouseInput = GetMouseInput();
		if ((currentMouseInput & MOUSE_INPUT_LEFT)  &&
			!(lastMouseInput & MOUSE_INPUT_LEFT)) {
			flipFlg = !flipFlg;
		}

		lastMouseInput = currentMouseInput;

		Vector2 dir = { static_cast<float>(mx) - rcA.center.x,
		static_cast<float>(my) - rcA.center.y };

		float angle = atan2(dir.y, dir.x);

		int cx = 32;
		int gw, gh;
		
		GetGraphSize(graphH[frame / 10], &gw, &gh);
		if (flipFlg) {
			cx = gw - cx;
		}

		DrawRotaGraph2(rcA.center.x , rcA.center.y,cx,35,
			 5.0f, 0.0f, graphH[frame/10], true,flipFlg);
		DrawCircleAA(rcA.center.x, rcA.center.y, 5, 16, 0xff4444);
		std::wostringstream oss;

		oss << L"x=" << rcA.center.x << L", y=" << rcA.center.y << std::endl;

		OutputDebugString(oss. str(). c_str());

		ScreenFlip();

		frame = (frame + 1) % 60;
	}
	++test;
	++test2;
	char outstr[16];
	sprintf_s(outstr, "test=%d\n", test);
	OutputDebugStringA(outstr);
	Debug::Output("Main Loop is end\n");
	sprintf_s(outstr, "test=%d\n", test);
	OutputDebugStringA(outstr);
	Debug::Output("Main Loop is end\n");
	sprintf_s(outstr, "test=%d\n", test);
	OutputDebugStringA(outstr);
	Debug::Output("Main Loop is end\n");
	sprintf_s(outstr, "test=%d\n", test);
	OutputDebugStringA(outstr);
	

	Singleton& singleton = Singleton::Intance();
	singleton.Out();
	Singleton& singleton2 = Singleton::Intance();
	auto& singleton3 = singleton2;
	singleton2.Out();
	singleton2.Out();
	singleton2.Out();
	singleton2.Out();
	singleton2.Out();
	singleton3.Out();
	

	DxLib_End();
	
	return 0;
}