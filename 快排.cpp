#include<iostream>
#include<vector>

using namespace std;

int Binary_search(int left, int right, int key);

vector<int> arr;
vector<int> keys;

int main()
{
    int n, m;
	int temp = 0;
    int i = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    //第三行输入m
    cin >> m;
    //接下来m行输入m个不同的数字
    for (i = 0; i < m; i++)
    {
        cin >> temp;
        keys.push_back(temp);
    }
    //二分查找
    //每一行输出一个结果，Yes或者No
    for (i = 0; i < m; i++)
    {
        if (Binary_search(0, n-1, keys[i]))
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
	if (left > right)
	{
		return 0;
	}
    int mid = left+(right - left)/2;
    if (arr[mid] == key || arr[left]==key||arr[right]==key )
    {
    	return 1;
    }
    else 
    {
    	if (key < arr[mid])
    	{
    		return Binary_search(left, mid - 1, key);
    	}
    	else
    	{
    		return Binary_search(mid + 1, right, key);
    	}
    }
    return 0;
}
