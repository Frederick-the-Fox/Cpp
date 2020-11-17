#include<iostream>
#include<math.h>

using namespace std;

int result[20] = { 0 };
int mark[21] = { 0 };

void dfs(int position);
bool IsPrime(int num);
bool Canset(int position, int num);
void PrintAll();
int judge = 0;

int main()
{
	dfs(0);
	return 0;
}

void dfs(int position)
{
	int i = 0;
	if (position == 20)
	{
		if (IsPrime(result[19] + result[0]))
		{
			PrintAll();
			judge = 1;
			return;
		}

	}
	else
	{
		if (judge == 1)
		{
			return;
		}
		for (i = 1; i < 21; i++)
		{
			if (Canset(position, i))
			{
				result[position] = i;
				mark[i] = 1;
				dfs(position + 1);
				mark[i] = 0;
				result[position] = 0;
			}
		}
		return;
	}
}

bool IsPrime(int num)
{
	int i = 2;
	int s = 0;
	s = (int)sqrt(num);
	for (int i = 2; i <= s; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool Canset(int position, int num)
{
	if (mark[num] == 1)
	{
		return false;
	}

	if (IsPrime(result[position - 1] + num))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PrintAll()
{
	int i = 0;
	for (i = 0; i < 19; i++)
	{
		cout << result[i] << " ";
	}
	cout << result[19];
	cout << endl;
}