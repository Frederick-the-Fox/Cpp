#include<iostream>
#include<stdio.h>
#include<windows.h>

using namespace std;

/*int main()
{
	//输入n
	//函数Cycle，传入参数：左上角a、第二左上角b，分别生成以后拼到一起
	return 0;
}

void Cycle()
{
	//出口条件：只有一个元素的时候，输出该元素
	//不止一个元素：
		//
}*/

int main()
{
	cout << "Hello," << endl << "World!" << endl;
	HANDLE hout;
	COORD coord;
	coord.X = 10;
	coord.Y = 0;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
	cout << "Hello, World" << endl << "111";
	return 0;
}