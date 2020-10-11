#include<iostream>
#include<windows.h>

using namespace std;


int main()
{
	cout << "Hello, world!";
	HANDLE hout;
	COORD coord;
	coord.X = 10;
	coord.Y = 0;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
	cout << "Hello, World!";
	return 0;
}