#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int dtm = 0;
int a[10000];
int b[50000];

int Find(int num, int low, int high);

int main()
{
    int n;
    int i = 0;
    int m;
    
    // input(n)
    cin >> n;
    //input(data)
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //input(m)
    cin >> m;
    //intput(num)
    for(i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    //for(i<m) find(num) output(result)
    for(i = 0; i < m; i++)
    {//find(b[i]);
        if(Find(b[i], 0 , n-1))
        {
            cout << "Yes" <<endl;
        }
        else
        {
            cout << "No" <<endl;
        }
    }
    return 0;
    //return
}

int Find(int num, int low, int high)
{
    if(low == high)
    {
        if(a[low] == num)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int mid;
    mid = (low + high)/2;
    return(Find(num, low, mid)||Find(num, (mid + 1), high));
}

