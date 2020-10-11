#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

void dfs(int floor);
void OutPut(vector<int>a);

vector<int>result;
int n;

int main()
{
	//定义一个全局容器，用于记录每一次路径中的输出数据
	//输入n
	cin >> n;
	//定义dfs函数，参数num代表数字，floor代表第几层。每次floor == n的时候将容器输出
	dfs(0);
	return 0;
}

void dfs(int floor)
{
	int num;
	if (floor == (n))
	{
		OutPut(result);
		cout << endl;
		return;
	}
	else
	{
		for (num = 0; num < 2; num ++)
		{
			result.push_back(num);
			dfs(floor + 1);
			result.pop_back();
		}
		return;
	}
}

void OutPut(vector<int>a)
{
	vector<int>::iterator ai;
	for (ai = a.begin(); ai != a.end(); ++ai)
	{
		cout << *ai << " ";
	}
	return;
}