#include <Windows.h>

//Gloabal Function Declaration 
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

//Gloabal Variabal Declaration

//Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpszCmdLine,int iCmdShow)
{
	//Local Variable Declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[]=TEXT("MyWindow");

	//code
	wndclass.cbSize=sizeof(WNDCLASSEX);
	wndclass.style=CS_HREDRAW|CS_VREDRAW;
	wndclass.lpfnWndProc=WndProc;
	wndclass.cbClsExtra=0;
	wndclass.cbWndExtra=0;
	wndclass.hInstance=hInstance;
	wndclass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);
	wndclass.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName=szAppName;
	wndclass.lpszMenuName=NULL;
	wndclass.hIconSm=LoadIcon(NULL,IDI_APPLICATION);

	RegisterClassEx(&wndclass);	//register class step 2

	//Create Window In Memory
	hwnd = CreateWindow(szAppName,TEXT("RDN: My First Window"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd,iCmdShow);
	UpdateWindow(hwnd);

	//Message Loop
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd,UINT iMsg,WPARAM wParam,LPARAM lParam)
{
	//code
	switch(iMsg)
	{
	case WM_CREATE:
		MessageBox(hwnd,TEXT("WCREATE MESSAGE IS ARIVED"),TEXT("MESSAGE"),MB_OK);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd,TEXT("LEFT MOUSE BUTTON IS PRESS"),TEXT("MESSAGE"),MB_OK);
		break;
	// case WM_RBUTTONDOWN:
	// 	MessageBox(hwnd,TEXT("Right MOUSE BUTTON IS PRESS"),TEXT("MESSAGE"),MB_OK);
	// 	break;
	case WM_KEYDOWN:
		MessageBox(hwnd,TEXT("A Key is press"),TEXT("MESSAGE"),MB_OK);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return(DefWindowProc(hwnd,iMsg,wParam,lParam));
}
