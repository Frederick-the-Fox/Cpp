#include<stdio.h>
#include<iostream>

using namespace std;

//划分算法部分，输入数组a、初始值、末端值，划分算法会将小于tmpt的数据放到tmpt左边，将大于tmpt的数据放到右边，并且返回一个位置信息i：
int Partition(int a[], int s, int t)
{
    int i = s;
    int j = t;
    int tmpt = a[s];
    //结束条件：i = j
    while (i != j)
    {
        while (a[j] >= tmpt && j>i)//当i = j的时候就不能再让程序运行下去了。
        {
            j-- ;
        }
        a[i] = a[j];
        while(i<j && a[i] <= tmpt)//道理同上。
        {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = tmpt;//将tmpt定位到中间。
    return i;
}

void QuickSort(int a[], int s, int t)
{
    if(s < t)//递归结束条件：s == t
    {
        int i = Partition(a, s, t);
        QuickSort(a, s, i-1);
        QuickSort(a, i+1, t);
    }
}

int main()
{
    int a[] = {2,5,1,7,10,6,9,4,3,8};
    QuickSort(a,0 ,9);
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}

