#include<iostream>
#include<queue>

using namespace std;

queue<int>nodes;
int step[10000];
int m, n;

void init();
int bfs();
int New(int current, int i);

int main()
{
	int result;
	//输入m,n
	cin >> m >> n;
	//初始化
	init();
	//bfs,传入某个数和当前步数，返回最小步数
	result = bfs();
	//输出最小步数
	cout << result << endl;
	return 0;
}

void init()
{
	int i = 0;
	for (i = 0; i <= n; i++)
	{
		step[i] = -1;
	}
	nodes.push(m);
	step[m] = 0;
}

int bfs()
{
	int current, newmember;
	int i = 0;
	while (!nodes.empty())
	{
		current = nodes.front();
		nodes.pop();
		if (current > n)
		{
			continue;
		}
		else if (current == n)
		{
			return step[current];
		}
		else if (current < n)
		{	
			for (i = 0; i < 3; i++)
			{
				newmember = New(current, i);
				if (newmember > n)
				{
					continue;
				}
				if (step[newmember] == -1)
				{
					step[newmember] = step[current] + 1;
					nodes.push(newmember);
				}				
			}
		}
	}
}

int New(int current, int i)
{
	switch (i)
	{
		case 0:
		{
			return current + 1;
		}
		case 1:
		{
			return current * 2;
		}
		case 2:
		{
			return current * current;
		}
	}
}