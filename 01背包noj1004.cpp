#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

vector<int>maxl;
vector<int>::iterator maxli;

int n, c = 0;
int w[100] = { 0 };
int p[100] = { 0 };
int put[100] = { 0 };
int max = 0;

void Search(int position);
void Check();

int main()
{
	int i = 0;
	cin >> n >> c;
	while (n != 0 || c != 0)
	{
		for (i = 0; i < n; i++)
		{
			cin >> w[i];
		}
		for (i = 0; i < n; i++)
		{
			cin >> p[i];
		}
		Search(0);
		maxl.push_back(max);
		for (i = 0; i < n; i++)
		{
			w[i] = 0;
			p[i] = 0;
		}
		max = 0;
		cin >> n >> c;
	}
	for (maxli = maxl.begin(); maxli != maxl.end() ; ++maxli)
	{
		cout << *maxli << endl;
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
	int weight = 0;
	int price = 0;
	for (i = 0; i < n; i++)
	{
		weight += w[i] * put[i];
	}
	if (weight <= c)
	{
		for (i = 0; i < n; i++)
		{
			price += p[i] * put[i];
		}
		if (price > max)
		{
			max = price;
		}
	}
}