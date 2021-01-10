#include "../include/common.h"
#include "../include/lguibase.h"
#include "../include/lgui.h"
#include "../include/app.h"

static LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
static void WinMain(void *args);
#define  ID_BUTTON 100
struct AppCfg Art={
	WinMain,
	"art",
	"art.bmp"
};


static void WinMain(void *args)
{

	int iStatus;
	HANDLE hWnd;
	WNDCLASSEX wcex;
	MSG msg;
	SCROLLINFO si;
	if(!InitGUIClient())
		return 0;

	wcex.cbSize			= sizeof(WNDCLASSEX);
	wcex.style			= 0;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= 0;
	wcex.hIcon			= 0;
	wcex.hCursor		= 0;
	wcex.hbrBackground	= CreateSolidBrush(RGB(147,222,252));
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= "artwin";
	wcex.hIconSm		= 0;

	RegisterClass(&wcex);

	hWnd = CreateWindow("artwin", "��������", WS_MAIN | WS_VISIBLE | 
			WS_THINBORDER|WS_CAPTION | WS_OKBUTTON |WS_CLOSEBOX,
			 1, 20,240, 200, NULL, NULL, NULL, NULL);	



	if (!hWnd)  return false;
	ShowWindow(hWnd, true);

	while (GetMessage(&msg,hWnd)){

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	TerminateGUIClient();
}

static LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HDC hDC;
	static RECT rc;
	static PAINTSTRUCT ps;
	int x,y,x1,y1;
	float realMin,realMax,imagMin,imagMax;
	int d;
	
	static HWND hWndCtr1,hWndCtr2,hWndNewWin;
	int i=0;

	switch(message)
	{
		case LMSG_CREATE:
			hWndCtr1 = CreateWindow("static", "�ر�", WS_CONTROL  | BS_PUSHBUTTON | WS_BORDER | WS_VISIBLE | BS_CHECKBOX,
				40, 150, 80 , 20, hWnd, (HMENU)0, NULL, NULL);
			hWndCtr2 = CreateWindow("listbox", "How are you? Are you ok?", WS_CONTROL | WS_BORDER | WS_VISIBLE
				 ,
				10,10, 130 , 80, hWnd, (HMENU)1, NULL, NULL);
			break;
		case LMSG_COMMAND:
			break;
		case LMSG_PENDOWN:/*�����mouse�¼�*/
			CaptureMouse(hWnd,BYCLIENT);
			break;
		case LMSG_PENMOVE:
			break;
		case LMSG_PENUP:
			DisCaptureMouse();
			break;
		case LMSG_TIMER:
			break;
		case LMSG_PAINT:
		{
			HPEN hPen;
			HBRUSH hBrush;
			POINT point;
			ps.bPaintDirect=false;

			hDC=BeginPaint(hWnd, &ps);
			if(!hDC){
				return true;
			}
			EndPaint(hWnd, &ps);
			break;
		}
		case LMSG_CLOSE:
			PostQuitMessage(hWnd);
			break;		
		case LMSG_DESTROY:
			PostQuitMessage(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return true;
}
