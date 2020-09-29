#include<stdio.h>
#include<iostream>

using namespace std;
int data[10000];

void MergeSort(int low, int high);
void Merge(int low, int mid, int high);

int main()
{
    int n;
    int i = 0;
    
    //输入n
    cin >> n;
    //循环输入data
    for(i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    //归并排序，给定从几到几，分一半排序完后合并。
    MergeSort(0, n-1);
    //输出排序好的数据
    for(i = 0; i < n; i++)
    {
        cout << data[i] << endl;
    }
    return 0;
}

void MergeSort(int low, int high)//low和high是角标的值。
{
    int mid;
    mid = (low + high)/2;
    if(low == high)
    {
        return;
    }
    else
    {
        MergeSort(low, mid);
        MergeSort(mid + 1, high);
        Merge(low, mid, high);
        return;
    }
}

void Merge(int low, int mid, int high)
{
    //定义数组b
    int b[10000];
    //定义i,j,k,分别为第一部分、第二部分和b的下角标
    int i = low;
    int j = mid + 1;
    int k = 0;
    //遍历i和j，哪个小就放到b里面
    while(i <= mid && j <= high)
    {
        if(data[i] <= data[j])
        {
            b[k] = data[i];
            i++;
            k++;
        }
        else
        {
            b[k] = data[j];
            j++;
            k++;
        }
    }
    //将剩下的放到b里面
    while(i <= mid)
    {
        b[k] = data[i];
        i++;
        k++;
    }
    while(j <= high)
    {
        b[k] = data[j];
        j++;
        k++;
    }
    //将b复制到a的对应位置
    for(i = low, k = 0; i <= high; i++,k++)
    {
        data[i] = b[k];
    }
    return;
}
