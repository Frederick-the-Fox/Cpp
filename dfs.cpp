#include<iostream>
#include<vector>

using namespace std;

//��������������Ž���������
vector<int>result;

//��������
void dfs(int num, int max);
void PrintOut(vector<int>a);

//main���������롢���㡢���
int main()
{
    int num = 0;
    cout<<"please input the number you want to dfs with:"<<endl;
    cin>>num;
    dfs(num , 1);
    return 0;
}

//�������������printout
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

//���������������
void dfs(int num, int max)
{
    int nextmax=1;
    //�ݹ��������
    if(!num)
    {
        PrintOut(result);
        return;
    }
    if(num < max)
    {
        return;
    }
    //��������
    for( nextmax = max; nextmax <= num; nextmax++)
    {
        result.push_back(nextmax);
        dfs(num - nextmax,nextmax);
        result.pop_back();
    }
    return;
}

