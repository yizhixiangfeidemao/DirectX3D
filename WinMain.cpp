#pragma comment  (lib,"User32.lib")
#pragma comment  (lib,"Gdi32.lib")
#include "Window.h"
#include <iostream>

int CALLBACK WinMain(
	HINSTANCE	hInstance,
	HINSTANCE	hPrevInstance,
	LPSTR		lpCmdLine,
	int			nCmdShow)
{
	Window wnd( 1280,720, "狼人杀3D");

	// 消息队列
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg,nullptr,0,0))>0)
	{
		TranslateMessage(&msg);				// 在适当的条件下将WM_KEYDOWN 转换为 WM_CHAR
		DispatchMessage(&msg);
	}
	if (gResult==-1)
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}
	
	
}