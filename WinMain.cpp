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
	Window wnd( 1280,720, "����ɱ3D");

	// ��Ϣ����
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg,nullptr,0,0))>0)
	{
		TranslateMessage(&msg);				// ���ʵ��������½�WM_KEYDOWN ת��Ϊ WM_CHAR
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