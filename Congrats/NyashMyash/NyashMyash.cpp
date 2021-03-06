#include "stdafx.h"
#include "NyashMyash.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 

	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_NYASHMYASH, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}
	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_NYASHMYASH));
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_NYASHMYASH));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = CreatePatternBrush(LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BackGrd)));
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_NYASHMYASH);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance;
	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPED | WS_MINIMIZEBOX | WS_SYSMENU | WM_MOUSEMOVE,
		CW_USEDEFAULT, CW_USEDEFAULT, 500, 562, nullptr, nullptr, hInstance, nullptr);
	HWND BOT_BUTTON = CreateWindowW(L"BUTTON", L"&Button", WS_VISIBLE | WS_CHILDWINDOW | WS_DLGFRAME | WS_TABSTOP | BS_BITMAP |BS_DEFPUSHBUTTON, 0, 500, 500, 62, hWnd, (HMENU)600, NULL, NULL);
	
	//HANDLE hImg = LoadImageW(NULL, L"bot_button_image.bmp", IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	//SendMessageW(BOT_BUTTON, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hImg);
	SendMessageA(hWnd, WM_SETTEXT, 0, (LPARAM)"CONGRATULATIONS!");
	HBITMAP  PbImg  =LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_Button));
	SendMessage(GetDlgItem(hWnd, 600), BM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(PbImg));
	SetWindowLong(hWnd, GWL_STYLE, 0); //hide window border
	
	if (!hWnd)
	{
		return FALSE;
	}
	//Перемещаем курсор на кнопку.
	RECT rect = { 0 };
	GetWindowRect(hWnd, &rect);
	SetForegroundWindow(hWnd);
	SetActiveWindow(hWnd);
	SetFocus(hWnd);
	Sleep(300);
	SetCursorPos(rect.right - 250, rect.bottom - 25);
	ShowWindow(hWnd, nCmdShow);
	// ^^^
	UpdateWindow(hWnd);
	return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{

		if (LOWORD(wParam) == 600) {
			//выключить монитор :D  TODO: прикрутить анимацию фейерверка, праздник все же.
			SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, 2);
			PostQuitMessage(0);
		}
		
	}
	break;
	case WM_SETCURSOR:  // Set cursor for mainwindow
		if (LOWORD(lParam) == HTCLIENT)
		{
			HCURSOR Cursor = LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR1));
			SetCursor(Cursor);
			SetClassLongPtr(GetDlgItem(hWnd, 600), GCLP_HCURSOR, reinterpret_cast<LONG_PTR>(Cursor));
			if (IsIconic(hWnd))
			{
				SetCursor(Cursor);
				break;
			}
		}
		break;
	case WM_LBUTTONDOWN:
	{
		SendMessage(hWnd, WM_NCLBUTTONDOWN, HTCAPTION, 0); //move b y mouse window
	
	}break;
	case WM_PAINT:
	{

		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 
		EndPaint(hWnd, &ps);
		
					
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

