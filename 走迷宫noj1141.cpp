#include <iostream>
using namespace std;
 
int m,n;
int map[25][25];
int vis[25][25];
int start_x,start_y,end_x,end_y;
int action[2][4]={-1, 1, 0, 0,	//上、下、左、右
				  0, 0, -1, 1};
 
bool canmoveto(int x,int y, int i)
{
	x += action[0][i];
	y += action[1][i];
	if(x<0 || x>=m)	return false;
	if(y<0 || y>=n)	return false;
	if(vis[x][y] == 1)	return false;
	if(map[x][y] == 1)	return false;
	return true;
}
 
void dfs(int x, int y)
{	
 
	vis[x][y] = 1;
	//cout<<"("<<x<<","<<y<<")"<<endl;
	for (int i = 0; i < 4; ++i)
	{
		if(canmoveto(x,y,i))
		{	
			dfs(x + action[0][i], y + action[1][i]);
		}
	}
}
 
 
int main(int argc, char const *argv[])
{
	cin>>m>>n;
	cin>>start_x>>start_y;
	cin>>end_x>>end_y;
 
	//录入地图
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>map[i][j];
			//初始未被访问过，vis置0
			vis[i][j] = 0;
		}
	}
	//开始搜索
	dfs(start_x,start_y);
	if(vis[end_x][end_y] == 1)	cout<<"Yes"<<endl;
	else	cout<<"No"<<endl;
 
	return 0;
}