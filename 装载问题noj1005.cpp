#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

vector<int>canl;
vector<int>::iterator canli;

int n = 0;
int w[100] = { 0 };
int c1, c2 = 0;
int put[100] = { -1 };
int can = -1;

void Search(int position);
void Check();
int Reverse(int num);

int main()
{
	int i = 0;
	cin >> c1 >> c2 >> n;
	while (n != 0 )
	{
		can = -1;
		for (i = 0; i < n; i++)
		{
			cin >> w[i];
		}
		Search(0);
		canl.push_back(can);
		for (i = 0; i < n; i++)
		{
			w[i] = 0;
		}
		cin >> c1 >> c2 >> n;
	}
	for (canli = canl.begin(); canli != canl.end() ; ++canli)
	{
		if (*canli == 1)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
}

void Search(int position)
{
	if (position >= n)
	{
		Check();
	}
	else
	{
		put[position] = 0;
		Search(position + 1);
		put[position] = 1;
		Search(position + 1);
	}
}

void Check()
{
	int i = 0;
	int weight1 = 0;
	int weight2 = 0;
	for (i = 0; i < n; i++)
	{
		weight1 += Reverse(put[i]) * w[i];
		weight2 += put[i] * w[i];
	}
	if (weight1 <= c1 && weight2 <= c2)
	{
		can = 1;
	}
}

int Reverse(int num)
{
	if (num == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}