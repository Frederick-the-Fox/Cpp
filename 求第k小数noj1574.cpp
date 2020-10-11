#include <iostream>
#include <stdlib.h>
using namespace std;
 
int a[10000];
 
int Partition(int i,int j,int a[])
{
    int pivot=a[i];
    while(i<j)
    {
        while(i<j && a[j]>=pivot)   j--;
        a[i] = a[j];
        while(i<j && a[i]<=pivot)   i++;
        a[j] = a[i];
    }
    a[i] = pivot;
    return i;
}
 
 
void find_x(int i,int j,int a[],int x)
{
    if(i<j)
    {
        int pivot = Partition(i,j,a);
        if(pivot == x)  cout<<a[pivot]<<endl;
        else if(pivot>x) find_x(i,pivot-1,a,x);
        else find_x(pivot+1,j,a,x);
    }
}
 
int main()
{
    int n,k;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    cin>>k;
    //QuickSort(0,n-1,a);
    //cout<<a[k-1]<<endl;
    find_x(0,n-1,a,k-1);
    return 0;
}