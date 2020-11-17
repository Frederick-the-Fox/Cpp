#include<iostream>
#include<queue>
#include<stdio.h>

using namespace std;

queue<int> positions;//表示当前节点的位置
int map[144];//0到143分别代表一个点的位置
int sy0, sx0, ey0, ex0;
int sy, sx, ey, ex;

int bfs();
int canmoveto(int po);
void moveto(int po);
int New(int y, int x, int i);
int turnNum(int y, int x);


int main()
{
	int in,out = 0;
	int start;
	int result;
	char tempt;
	//输入 sy,sx
	//输入 ey,ex
	cin >> sy0 >> sx0 >> ey0 >> ex0;
	sy = sy0 - 1;
	sx = sx0 - 1;
	ey = ey0 - 1;
	ex = ex0 - 1;
	start = turnNum(sy, sx);
	//循环输入map，当打够12个以后输入一个\n
	for (out = 0; out < 12; out++)
	{
		for (in = 0; in < 12; in++)
		{
			cin >> tempt;
			if (tempt == 'X')
			{
				map[in + 12 * out] = -2;
			}
			else
			{
				map[in + 12 * out] = -1;
			}
		}
	}
	for (out = 0; out < 12; out++)
	{
		for (in = 0; in < 12; in++)
		{
			cout << map[in + 12 * out];
		}
		cout << endl;
	}
	positions.push(start);
	map[turnNum(sx, sx)
] = 0;
	//cout << "safe" << endl;//测试输入用	
	//bfs
	result = bfs();
	//输出结果
	cout << result << endl;
	return 0;
}

int bfs()
{
	int current;
	int y, x;
	int i = 0;
	int newpo, newy, newx;
	while (!positions.empty())
	{
		current = positions.front();
		positions.pop();
		y = current % 12;
		x = current / 12;
		if (y == ey && x == ex)
		{
			return map[current];
		}
		else
		{
			for (i = 0; i < 4; i++)
			{
				newpo = New(y, x, i);
				newy = newpo % 12;
				newx = newpo / 12;
				if (canmoveto(newpo))
				{
					moveto(newpo);
					map[newpo] = map[current] + 1;
					cout << newy << " " << newx << " " << map[newpo] << endl;
				}
			}
		}
	}
}

int canmoveto(int po)
{
	if (map[po] == -2 || map[po] > 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void moveto(int po)
{
	positions.push(po);
}

int turnNum(int y, int x)
{
	return 12 * y + x;
}

int New(int y, int x, int i)
{
	int ny, nx;
	switch (i)
	{
		case 0:
		{
			ny = y;
			nx = x - 1;
			return turnNum(ny, nx);
		}
		case 1:
		{
			ny = y - 1;
			nx = x;
			return turnNum(ny, nx);
		}
		case 2:
		{
			ny = y;
			nx = x + 1;
			return turnNum(ny, nx);
		}
		case 3:
		{
			ny = y + 1;
			nx = x;
			return turnNum(ny, nx);
		}
	}
}



