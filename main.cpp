#include <iostream>
#include <Windows.h>

using namespace std;

void a(int time)
{
keybd_event(0x41, 0, 0, 0);
Sleep(time);
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0);
}
void d(int time)
{
keybd_event(0x44, 0, 0, 0);
Sleep(time);
keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0);
}
void MouseMove(int x, int y)//Move the mouse to the specified position
	{
		double fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;//Get the screen resolution width
		double fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;//Get the screen resolution height
		double fx = x*(65535.0f / fScreenWidth);
		double fy = y*(65535.0f / fScreenHeight);
		INPUT  Input = { 0 };
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
		Input.mi.dx = fx;
		Input.mi.dy = fy;
		SendInput(1, &Input, sizeof(INPUT));
	}

void MouseLeftDown()//Press the left mouse button
	{
		INPUT  Input = { 0 };
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		SendInput(1, &Input, sizeof(INPUT));
	}

	void MouseLeftUp()//Release the left mouse button
	{
		INPUT  Input = { 0 };
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
		SendInput(1, &Input, sizeof(INPUT));
	}

void pozitie(){
POINT p;
Sleep(1000);
if (GetCursorPos(&p))
{
    cout<<p.x<<" "<<p.y<<endl;
}


}
int main()
{

HWND GameWindow = FindWindow(0, "Growtopia");
SetForegroundWindow(GameWindow);

if(GameWindow==NULL){
    cout<<"Jocul este inchis"<<endl;
}
else{
    //selecteaza block
        MouseMove(459,758);
        MouseLeftDown();
        Sleep(500);
        MouseLeftUp();
    for(int i=1;i<=20;i++){
        //pozitie 1
        MouseMove(300,367);
        MouseLeftDown();
        Sleep(500);
        MouseLeftUp();
        //pozitie 2
        MouseMove(414,384);
        MouseLeftDown();
        Sleep(500);
        MouseLeftUp();
        //pumn
        MouseMove(932,725);
        MouseLeftDown();
        Sleep(1500);
        MouseLeftUp();
    }
}

    return 0;
}
