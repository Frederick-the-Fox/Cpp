#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    
    int gram[19][524288];
    //输入n
    int n;
    cin >> n;
    //第0列每2^n循环一次，共1次
    //第1列每2^(n-1)循环一次，共2次
    //第k列每2^(n-k)循环一次，共2^k次
    int row = 0;//行
    int k = 0;//第k列的情况
    int t = 0;//循环次数
    int num = 1;//每个循环中有num个一样的操作
    int i, j = 0;
    for(k = 0; k < n; k++)
    {
        for(t = 1; t <= (2^k); t++)
        {
            row = 0;
            for(num = 0; num < n-k; num ++, row++)
            {
                gram[k][row] = 0;
            }
            for(num = 0; num < n-k; num ++, row++)
            {
                gram[k][row] = 1;
            }
        }
    }
    for(i = 0; i < (2^n); i++)
    {
        for(j = 0; j < n; j++)
        {
            cout << gram[i][j];
        }
        cout << endl;
    }
    return 0;
}

