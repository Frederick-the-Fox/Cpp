#include<stdio.h>
#include<iostream>

using namespace std;

int data[10000];

void QuickSort(int low, int high);

int main()
{
    //定义并输入n
    int n;
    cin >> n;
    //循环输入数据
    int i = 0;
    for(i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    //快排序，给定low和high，进行排序操作
    QuickSort(0, n-1);
    //循环输出数据
    for(i = 0; i < n; i++)
    {
        cout << data[i] << endl;
    }
    return 0;
}

void QuickSort(int low, int high)
{
    //出口条件：low == high
    if(low >= high)
    {
        return;
    }
    else
    {
        //定义一个临时变量cmp,保存data【low】，作为参考数据
        int cmp;
        cmp = data[low];
        //定义脚标i和j，用于遍历两边的数据，一个从最左，一个从最右
        int i = low;
        int j = high;
        //先看j，若data[j]小于等于cmp，就将值赋给data[i]
        while (i != j)
        {
            while (j > i && data[j] >= cmp)
            {
                j--;
            }
            data[i] = data[j];
            while(i < j && data[i] <= cmp)
            {
                i++;
            }
            data[j] = data[i];
        }
        //当i == j的时候，将cmp赋给data[i]
        data[i] = cmp;
        //排序low,mid
        QuickSort(low, i);
        QuickSort(i+1, high);
        //排序mid+1,high
        return;
    }
}
