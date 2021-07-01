#pragma once
class Debug
{
public:
	static void Output(const char* str);
};
extern int test;
static int test2;

struct Vector2 {
	float x, y;
};

using Position2 = Vector2;
