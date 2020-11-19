#include<iostream>

using namespace std;

int begin[1000];
int end[1000];
int max = 0;
int n = 0;

void Sort(int low, int high);

int main()
{
	int i = 0;
	int temp = 0;
	int temp2 = 0;
	int num = 1; 
	int en = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> begin[i];
		cin >> end[i];
	}
	Sort(0, n - 1);
	en = end[0];
	for (i = 1; i < n; i++)
	{
		if (begin[i] >= en)
		{
			num += 1;
			en = end[i];
		}
	}
	cout << num << endl;
}

void Sort(int low, int high)
{
	if (low >= high)
	{
		return;
	}
	else
	{
		int i = low;
	int j = high;
	int temp = end[low];
	int tempx = begin[low];
	while(i < j)
	{
		while(end[j] >= temp && j > i)
		{
			j--;
		}
		end[i] = end[j];
		begin[i] = begin[j];
		while(end[i] <= temp && i < j)
		{
			i++;
		}
		end[j] = end[i];
		begin[j] = begin[i];
	}
	end[i] = temp;
	begin[i] = tempx;
	Sort(low, i - 1);
	Sort(i + 1, high);
	return;
	}
	
}