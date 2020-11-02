#include<iostream>

using namespace std;

int Binary_search(int left, int right, int key);

int arr[10000];
int keys[5000];

int main()
{
    int n, m;
    int i = 0;
    //第一行输入n
    cin >> n;
    //第二行输入n个数字
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //第三行输入m
    cin >> m;
    //接下来m行输入m个不同的数字
    for (i = 0; i < m; i++)
    {
        cin >> keys[i];
    }
    //二分查找
    //每一行输出一个结果，Yes或者No
    for (i = 0; i < m; i++)
    {
        if (Binary_search(0, n, keys[i]))
        {
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}

int Binary_search(int left, int right, int key)
{
    int mid = (left + right)/2;
    if (left >= right)
    {
        return 0;
    }
    else
    {
        if (arr[mid] == key)
        {
            return 1;
        }
        if (key < arr[mid])
        {
            return Binary_search(left, mid, key);
        }
        else
        {
            return Binary_search(mid + 1, right, key);
        }
    }
}
