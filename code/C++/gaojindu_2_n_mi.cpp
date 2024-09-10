#include<iostream>
#include<cmath>
#include<climits>//其中包含常量INT_MAX
using namespace std;
int a[1001],f[1001][1001],s[1001][1001];
int lu(int,int);//计算编号从left到right的村庄的中间学校1的距离。
int main()
{
    int m,n,dis;
    cin>>m>>n;
    for(int i=2;i<=m;i++)
    {
        cin>>dis;
        a[i]=dis+a[i-1];//利用坐标轴表示便于后续计算，第i个村庄在数轴上的坐标，第一个村庄坐标为1。
    }
    for(int i=0;i<m;i++)
        for(int j=i;j<=m;j++)//这里j从i开始的原因时j必须要大于等于i，因为s是从i到j村庄距离和，s[i][j]表示编号为i的村庄到编号为j的村庄之间只建一个小学的最短距离。
    {
        s[i][j]=lu(i,j);
        s[j][i]=s[i][j];	//如s[1][0]的最短距离应当和s[0][1]最短距离相同，但是j从i开始则不会循环到j比i小的情况，所以需要特殊赋值
    }
    for(int i=1;i<=m;i++)
      for(int j=1;j<=i&&j<=n;j++)
        f[i][j]=INT_MAX;	//INT_MAX：intmax是一个编程函数。函数功能是返回指定整数类型所能表示的最大值。(int类型默认32位数字)
    for(int i=1;i<=m;i++) f[i][i]=0;//当学校数目和村庄数目相等时，距离就是0。
    for(int i=1;i<=m;i++)//只建一个学校时，最小距离就是编号为1的存在到编号为m的村庄
        f[i][1]=s[1][i];
    for(int i=2;i<=m;i++)//有几个村庄，这里懒得思考了就把所有可能出现的值全部赋值了。
        for(int j=2;j<=n&&j<=i;j++)//有几个学校，注意j<=i，不可能学校比村庄还多把！！
    {
        for(int k=j;k<=i;k++)//注意这里！k一定要从j开始算起！
       if(i!=j) f[i][j]=min(f[i][j],f[k-1][j-1]+s[k][i]);    
	   //f[k-1][j-1]表示的是：前k-1个村庄中建j-1个学校的最小距离和，s[k][i]表示，第k个村庄到第i个村庄建一所小学所需要的最小距离和
    }
    cout<<f[m][n]<<endl;//输出m个村庄建n所小学的最小的距离。
    return 0;
}
int lu(int left,int right)
{
	//定理：一段区间内所有点到某个地方距离最短的话，那么那个点一定在这个区间的中点
    int mid=(left+right)/2,l=0;
    for(int i=left;i<=right;i++)
    {
        l+=abs(a[mid]-a[i]);
    }
    return l;
}
