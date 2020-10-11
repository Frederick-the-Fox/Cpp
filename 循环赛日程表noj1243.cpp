#include<stdio.h>
#include<conio.h>
#define x 10000
int a[x][x]; 
void gamecal(int k,int m);
void main() {
    int i,j,m=1,n;  
    scanf("%d",&n);
    for (i=0;i<n;i++)
    m *=2;
    gamecal(1,m);
    for(i=0;i<m;i++)
    {for(j=0;j<m-1;j++)
    {
        printf("%d ",a[i][j]);
    }
    printf("%d",a[i][j]);
    printf("\n"); 
    } 
} 
void gamecal(int k,int m) {
    int i,j;
    if(m==2) {
        a[k-1][0]=k;
        a[k][0]=k+1;
    } 
    else {
        gamecal(k,m/2);
        gamecal(k+m/2,m/2); 
    } 
    for(i=k-1;i<k-1+m/2;i++)
    {
        for(j=m/2;j<m;j++)
            a[i][j]=a[i+m/2][j-m/2];
    } 
    for(i=k-1+m/2;i<k-1+m;i++)
    {for(j=m/2;j<m;j++)
    a[i][j]=a[i-m/2][j-m/2];
    } 
} 