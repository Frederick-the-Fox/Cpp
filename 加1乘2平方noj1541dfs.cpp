#include<iostream>

using namespace std;

int step[10000];
int n;
int m;

void dfs(int num, int stp);

int main()
{
	int i = 0;

	cin >> m >> n;
	for (i = m; i <= n; i++)
	{
		step[i] = n - m;
	}
	dfs(m, 0);
	cout << step[n];
	return 0;
}

void dfs(int num, int stp)
{
	if (num > n)
	{
		return;
	}
	if (stp >= step[num])
	{
		return;
	}
	step[num] = stp;
	dfs(num * 2, stp + 1);
	dfs(num * num, stp + 1);
	dfs(num + 1, stp + 1);
	return;
}