#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

//函数声明：
void Merge(int* a, int low, int mid, int high);
void MergeSort(int a[], int low, int high);

int main()
{
    /*int a[10];//这里简单地认为数据量不超过100个
    int i = 0;
    int counting = 0;
    for (counting = 0; ; cin >> a[i])
    {
        counting++ ;
        if(cin.get() == '\n') break;
    }
    MergeSort(a, 0, counting-1);
    for(i = 0; i < counting; i++)
    {
        cout << a[i] << " ";
    }*/
    int a[] = {10,9,8,7,6,5,4,3,2,1};
    int i = 0;
    MergeSort(a, 0, 9);
    for(i = 0; i < 10; i++)
    {
        cout << a[i]<<' ';
    }
    return 0;
}

//归并两个已经有序的相邻数组：
//注：这里设置了3个形参，是因为这三个参数是数组的下标，直接引过来免去了下标和位次这两个概念之间的逻辑转变。
void Merge(int* a, int low, int mid, int high)
{
    //定义一个临时数组tmpa用来存放排序的数据：
    int *tmpa;
    tmpa = (int *)malloc((high - low + 1) * sizeof(int));
    //定义第一部分的遍历变量i、第二部分的遍历变量j、tmpa的遍历变量k：
    int i = low;
    int j = mid + 1;
    int k = 0;
    //第一部分和第二部分元素一个一个比较，哪个比较小就放到tmpa中：
    while(i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            tmpa[k] = a[i];
            i++ ;
            k++ ;
        }
        else
        {
            tmpa[k] = a[j];
            j++ ;
            k++ ;
        }
    }
        //这个过程结束的时候，势必会有第一部分或者第二部分的元素剩下，那么将剩下的元素添进tmpa中去：
        while (i <= mid)
        {
            tmpa[k] = a[i];
            i++ ;
            k++ ;
        }
        while(j <= high)
        {
            tmpa[k] = a[j];
            j++ ;
            k++ ;
        }
        //最后将tmpa中的数据放回到a的相应位置：
        for (k = 0, i = low; i <=high; k++ , i++ )
        {
            a[i] = tmpa[k];
        }
        //释放临时数组的内存
        free(tmpa);
    }

//归并排序：
void MergeSort(int a[], int low, int high)
{
    int mid;
    if(low < high)//出口条件：还有两个或者两个以上的元素
    {
        mid = (low + high)/2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

