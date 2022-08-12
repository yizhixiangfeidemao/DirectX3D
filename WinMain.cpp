#pragma comment  (lib,"User32.lib")
#pragma comment  (lib,"Gdi32.lib")
#include<Windows.h>
#include<string>
#include<sstream>
using namespace std;

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	case WM_KEYDOWN:			// wParamΪ���̵�����ֵ
		if (wParam=='F')
		{
			SetWindowText(hWnd, "����ɱ��Ϸ��ʼ");
		}
		break;
	case WM_KEYUP:
		if (wParam=='F')
		{
			SetWindowText(hWnd, "����ɱ��Ϸ����");
		}
		break;
	case WM_CHAR:
		{
			static std::string title;
			title.push_back((char)wParam);
			SetWindowText(hWnd, title.c_str());
		}
		break;
	case WM_LBUTTONDOWN:
		{
			const POINTS pt = MAKEPOINTS(lParam);
			std::ostringstream oss;
			oss << "(" << pt.x << "," << pt.y << ")";
			SetWindowText(hWnd, oss.str().c_str());
		}
		break;
	}

	
		
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
	HINSTANCE	hInstance,
	HINSTANCE	hPrevInstance,
	LPSTR		lpCmdLine,
	int			nCmdShow)
{
	const auto pClassName = "hw3dbutts";
	// ע�ᴰ����
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);

	// ��������ʵ��
	HWND hwnd = CreateWindowEx(
		0, pClassName, "����ɱ3D",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 30,  840,640,
		nullptr, nullptr, hInstance, nullptr
	);

	// ��ʾ����
	ShowWindow(hwnd, SW_SHOW);

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