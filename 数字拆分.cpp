#include<iostream>
using namespace std;

int main()
{
	int n;//数值量
	int i;
	cin >> n >> i;
}

int a = 1;
int b[10] = { 0 };
int count = 0;

int dfs(int num,int i)
{
	if (num == 0) {
		count++;
		cout << '+' << a << endl;
		num = num + a;
		a = 1 + a;
		if(a = num + a)
	}
	else if (num < i) {
		num = num + a;
		a = 1 + a;
	}
	else {
		num = num - a;
		cout << '+' << a;
	}
}