#include<iostream>
#include<vector>

using namespace std;

//定义容器用来存放结果输出序列
vector<int>result;

//函数声明
void dfs(int num, int max);
void PrintOut(vector<int>a);

//main函数：输入、运算、输出
int main()
{
    int num = 0;
    cout<<"please input the number you want to dfs with:"<<endl;
    cin>>num;
    dfs(num , 1);
    return 0;
}

//定义结果输出函数printout
void PrintOut(vector<int>a)
{
    vector<int>::iterator ai;
    cout<<a[0];
    for (ai = a.begin()+1; ai != a.end(); ++ai)
    {
        cout<<"+"<<*ai;
    }
    cout<<endl;
    return ;
}

//定义深度搜索函数
void dfs(int num, int max)
{
    int nextmax=1;
    //递归结束条件
    if(!num)
    {
        PrintOut(result);
        return;
    }
    if(num < max)
    {
        return;
    }
    //函数主体
    for( nextmax = max; nextmax <= num; nextmax++)
    {
        result.push_back(nextmax);
        dfs(num - nextmax,nextmax);
        result.pop_back();
    }
    return;
}

