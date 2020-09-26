#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

void Arrange(vector<int>a, unsigned long num);//函数声明

int main()
{
    vector<int>data;//使用vector容器储存元素数据。
    vector<int>::iterator datait;
    int temp = 0;
    cout << "please input the numbers you want me to arrange" << endl ;
    //动态输入元素到容器中：
    for (temp = 0; ;cin >> temp)
    {
        data.push_back(temp);
        if(cin.get() == '\n') break;
    }
    Arrange(data,data.size());
    for(datait = data.begin(); datait < data.end(); ++datait){
        cout << *datait <<' ';
    }
    return 0;
}

void Arrange(vector<int>a, unsigned long num)
{
    //递归结束条件：num=1或2
    int tem;
    if(num == 1){
        return;
    }
    if(num == 2){
        if(a[0] >= a[1]){
            tem = a[0];
            a[0] = a[1];
            a[1] = tem;
        }
        else return;
    }
    //函数主体部分
    //将数据分为前、后两部分
    vector<int>b(a.size()/2);
    vector<int>c(a.size() - a.size()/2);
    unsigned long i=0;
    for(i = 0; i < a.size()/2; i++){
        b[i] = a[i];
    }
    for(i = a.size()/2; i < a.size(); i++){
        b[i] = a[i];
    }
    //将两部分分别排序
    Arrange(b,b.size());
    Arrange(c,c.size());
    //将两部分合并到vector
    for(i = 0; i < a.size()/2; i++){
        a[i] = b[i];
    }
    for(i = a.size()/2; i < a.size(); i++){
        a[i] = c[i];
    }
    //返回
    return;
}

