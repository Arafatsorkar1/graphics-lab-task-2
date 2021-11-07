#include <windows.h>

#include <cmath>

#define ROUND(a) ((int) (a + 0.5))

/* set window handle */

static HWND sHwnd;

static COLORREF redColor=RGB(255,0,0);

static COLORREF blueColor=RGB(0,0,255);

static COLORREF greenColor=RGB(0,255,0);


void SetWindowHandle(HWND hwnd){

sHwnd=hwnd;

}

/* SetPixel */

void setPixel(int x,int y,COLORREF& color=redColor){

if(sHwnd==NULL){

MessageBox(NULL,"sHwnd was not initialized !","Error",MB_OK|MB_ICONERROR);

exit(0);

}

HDC hdc=GetDC(sHwnd);

SetPixel(hdc,x,y,color);

ReleaseDC(sHwnd,hdc);

return;

// NEVERREACH //

}


void drawLineDDA(int xa, int ya, int xb, int yb){

int dx = xb - xa, dy = yb - ya, steps, k;

float xIncrement, yIncrement, x = xa, y = ya;

if(abs(dx) > abs(dy)) steps = abs(dx);

else steps = abs(dy);

xIncrement = dx / (float) steps;

yIncrement = dy / (float) steps;

setPixel(ROUND(x), ROUND(y));

for(int k = 0; k < steps; k++){

x += xIncrement;

y += yIncrement;

setPixel(x, y);

}

}

/* Window Procedure WndProc */

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam){

switch(message){

case WM_PAINT:

SetWindowHandle(hwnd);






drawLineDDA(550,15,550,62);
drawLineDDA(550,15,575,5);
drawLineDDA(575,5,575,65);
drawLineDDA(575,5,620,13);
drawLineDDA(620,13,620,72);


drawLineDDA(400,40,900,120);
drawLineDDA(400,40,300,300);

drawLineDDA(300,300,315,305);
drawLineDDA(315,305,410,80);
drawLineDDA(410,80,510,240);
drawLineDDA(510,240,980,260);
drawLineDDA(900,120,980,260);



drawLineDDA(390,175,450,165);
drawLineDDA(390,175,390,240);
drawLineDDA(450,165,450,235);
drawLineDDA(390,240,450,235);


drawLineDDA(315,305,315,320);
drawLineDDA(315,320,450,320);
drawLineDDA(450,320,450,560);



drawLineDDA(500,227,500,570);
drawLineDDA(960,260,960,500);

drawLineDDA(450,530,500,530);
drawLineDDA(500,530,960,470);


drawLineDDA(450,560,500,570);
drawLineDDA(500,570,960,500);

drawLineDDA(670,300,720,300);
drawLineDDA(670,300,670,400);
drawLineDDA(720,300,720,400);
drawLineDDA(670,400,720,400);




drawLineDDA(780,310,815,310);
drawLineDDA(780,310,780,390);
drawLineDDA(815,310,815,390);
drawLineDDA(780,390,815,390);


drawLineDDA(960,380,1100,380);



drawLineDDA(450,320,400,360);
drawLineDDA(315,305,275,360);
drawLineDDA(400,360,275,360);

drawLineDDA(285,360,285,500);

drawLineDDA(400,360,400,570);
drawLineDDA(400,570,450,560);

drawLineDDA(285,500,400,570);


drawLineDDA(410,565,410,380);
drawLineDDA(440,563,440,380);
drawLineDDA(410,380,440,380);



drawLineDDA(320,400,360,400);
drawLineDDA(320,400,320,470);
drawLineDDA(360,400,360,475);
drawLineDDA(320,470,360,475);

drawLineDDA(285,400,200,400);

















break;

case WM_CLOSE: // FAIL THROUGH to call DefWindowProc

break;

case WM_DESTROY:

PostQuitMessage(0);

return 0;

default:

break; // FAIL to call DefWindowProc //

}

return DefWindowProc(hwnd,message,wParam,lParam);

}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int iCmdShow){

static TCHAR szAppName[] = TEXT("Straight Line");

WNDCLASS wndclass;

wndclass.style         = CS_HREDRAW|CS_VREDRAW ;

wndclass.lpfnWndProc   = WndProc ;

wndclass.cbClsExtra    = 0 ;

wndclass.cbWndExtra    = 0 ;

wndclass.hInstance     = hInstance ;

wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;

wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;

wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;

wndclass.lpszMenuName  = NULL ;

wndclass.lpszClassName = szAppName ;

// Register the window //

if(!RegisterClass(&wndclass)){

MessageBox(NULL,"Registering the class failled","Error",MB_OK|MB_ICONERROR);

exit(0);

}

// CreateWindow //

HWND hwnd=CreateWindow(szAppName,"DDA - Programming Techniques",

WS_OVERLAPPEDWINDOW,

CW_USEDEFAULT,

CW_USEDEFAULT,

CW_USEDEFAULT,

CW_USEDEFAULT,

NULL,

NULL,

hInstance,

NULL);

if(!hwnd){

MessageBox(NULL,"Window Creation Failed!","Error",MB_OK);

exit(0);

}

// ShowWindow and UpdateWindow //

ShowWindow(hwnd,iCmdShow);

UpdateWindow(hwnd);

// Message Loop //

MSG msg;

while(GetMessage(&msg,NULL,0,0)){

TranslateMessage(&msg);

DispatchMessage(&msg);

}

/* return no error to the operating system */

return 0;

}
