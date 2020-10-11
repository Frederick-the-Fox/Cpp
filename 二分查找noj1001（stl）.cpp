#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    int datas[10000];
    int m;
    int nums[50000];
    int i = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> datas[i];
    }
    cin >> m;
    for (i = 0;i < m; i++)
    {
        cin >> nums[i];
    }
    for (i = 0; i < m; i++)
    {
        if (binary_search(datas, datas + n, nums[i]))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" <<endl;
        }
    }
    return 0;
}
