#include "Singleton.h"
#include"DxLib.h"

void 
Singleton::Out(){
	wchar_t outstr[32];
	wsprintf(outstr, L"SinGleton Count=%d\n", counter);
	OutputDebugString(outstr);
	++counter;
}
