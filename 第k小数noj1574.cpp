#include<stdio.h>
#include<iostream>

using namespace std;

int datas[10000];

int Place(int low, int high);
void QuickSort(int low, int high);

int main()
{
	int n;
	int k;
	int i = 0;
	//输入n
	cin >> n;
	//输入n个数
	for (i = 0; i < n; i++)
	{
		cin >> datas[i];
	}
	//输入k
	cin >> k;
	//快排
		//把数据分成左右两部分
		//快排左部分
		//快排右部分
	//输出第k小数
	QuickSort(0, n - 1);
	cout << datas[k - 1];
	return 0;
}

void QuickSort(int low, int high)
{
	if (low >= high)
	{
		return;
	}
	int p;
	p = Place(low, high);
	QuickSort(low, p);
	QuickSort(p + 1, high);
}

int Place(int low, int high)
{
	int cmp = 0;
	int i ,j= 0;
	i = low;
	j = high;
	cmp = datas[low];
	while (i != j)
	{
		while (datas[j] >= cmp && j > i)
		{
			j--;
		}
		datas[i] = datas[j];
		while (datas[i] <= cmp && i < j)
		{
			i++;
		}
		datas[j] = datas[i];
	}
	datas[i] = cmp;
	return i;
}
