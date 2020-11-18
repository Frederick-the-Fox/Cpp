#include<iostream>
#include<queue>

using namespace std;

queue<int> datas;
int m = 0;
int n = 0;
int mark[10000];

void bfs();
int f(int num, int i);

int main()
{
	int i = 0;
	cin >> m >> n;
	for (i = m; i <= n; i++)
	{
		mark[i] = -1;
	}
	datas.push(m);
	mark[m] = 0;
	bfs();
	cout << mark[n] << endl;
	return 0;
}

void bfs()
{
	int i = 0;
	int result = 0;
	int current = 0;
	while (!datas.empty())
	{
		current = datas.front();
		datas.pop();
		for (i = 0; i < 3; i++)
		{
			result = f(current, i);
			if (result > n)
			{
				continue;
			}
			if (result == n)
			{
				mark[n] = mark[current] + 1;
				return;
			}
			if (mark[result] == -1)
			{
				mark[result] = mark[current] + 1;
				datas.push(result);
			}
		}
	}
}

int f(int num, int i)
{
	if (i == 0)
	{
		return num * num;
	}
	if (i == 1)
	{
		return num * 2;
	}
	if (i == 2)
	{
		return num + 1;
	}
}
