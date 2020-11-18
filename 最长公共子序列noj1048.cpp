#include<iostream>
#include<string.h>
#include<vector>

using namespace std;


string a;
string b;
int dp[201][201];
int na = 0;
int nb = 0;

void Find();

int main()
{
	cin >> a >> b;
	na = a.length();
	nb = b.length();
	Find();
	cout << dp[na][nb] << endl;
	return 0;
}

void Find()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < na + 1; i++)
	{
		dp[0][i] = 0;
	}
	for (i = 0; i < nb + 1; i++)
	{
		dp[i][0] = 0;
	}
	for (i = 1; i < na + 1; i++)
	{
		for (j = 1; j < nb + 1; j++)
		{
			if (a[i - 1] == b[i - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				if (dp[i - 1][j] > dp[i][j - 1])
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
	}
}