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
	//����һ��ȫ�����������ڼ�¼ÿһ��·���е��������
	//����n
	cin >> n;
	//����dfs����������num�������֣�floor����ڼ��㡣ÿ��floor == n��ʱ���������
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