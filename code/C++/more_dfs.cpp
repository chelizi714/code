#include<bits/stdc++.h>
using namespace std;
int k,r,s;
char x[1005][1005];
int a[1005][1005];
bool flag = false;
int vis[30][30];
int dis[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int x1, x2, xx, y2;
void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dis[i][0];//下一个点的横纵坐标
		int ny = y + dis[i][1];
		if (nx >= 0 && nx < r && ny >= 0 && ny < r&&a[nx][ny]==0)
		{
			a[nx][ny] = 1;//避免重复减少运行时间
			if (nx == x2 && ny == y2)//如果搜索到终点，直接输出“YES”
			{
				cout << "YES" << endl;
				flag = true;
				break;
			}
			else//如果没有，继续搜索
				dfs(nx, ny);
		}
	}
}
int main()
{
	cin >> k;//样例组数
	for (int i = 0; i < k; i++)
	{
		flag = false;
		memset(a, 0, sizeof(a));
		cin >> r;
		for (int j = 0; j < r; j++)
		{
			for (int z = 0; z < r; z++)
			{
				cin >> x[j][z];
				if (x[j][z] == '.')
				{
					a[j][z] = 0;
				}
				else
				{
					a[j][z] = 1;
				}
			}
		}//将字母矩阵转化为1，0的数字矩阵
		cin >> x1 >> xx >> x2 >> y2;//输入起始点和终点坐标
		if (a[x1][xx] || a[x2][y2])//如果起始点或终点是‘#’号，直接输出“NO”
		{
			cout << "NO" << endl;
			continue;
		}
		else//进行深搜
			dfs(x1, xx);
		if (!flag)
		{
			cout << "NO" << endl;//没有成功，输出结果
		}
	}
	return 0;
 
}