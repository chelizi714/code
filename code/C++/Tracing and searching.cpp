//回溯和搜索的经典题型
# include<iostream>

# include<cstring>

using namespace std;

const int maxn=26;

int r,s;  //r,s是长宽的范围

int g[maxn][maxn];

string ss;

int Max;

bool vis_le[maxn];  //标记字母，26个字母

bool vis_[maxn][maxn];//标记点

int dr[]={1,0,-1,0};//dr和dc一同作用,意为向右移动，向左移动，向上移动，向下移动

int dc[]={0,-1,0,1};

void search(int x,int y,int step)

{

       if(step>Max)Max=step;    //如果step更大，则变化大小

       for(int i=0;i<4;i++)

       {

                     int newx=x+dr[i];

                     int newy=y+dc[i];

              if(newx>=0 && newx<r && newy>=0 && newy<s && !vis_le[g[newx][newy]] && !vis_[newx][newy]) //!vis_le[g[newx][newy]]意为此处的字母没有出现过 
                                                                                                         //!vis_[newx][newy]意为在newx这一层的newy的位置没有出现这个字母

                     {

                     vis_le[g[newx][newy]]=vis_[newx][newy]=1;     //记录搜索之后的状态

                     search(newx,newy,step+1);

                     vis_le[g[newx][newy]]=vis_[newx][newy]=0;   //回溯没有搜索之前的状态

                     }

       }

      

}

int main()

{

       cin>>r>>s;

       for(int i=0;i<r;i++)

       {

              cin>>ss;

              for(int j=0;j<ss.size();j++)

              {

                     g[i][j]=ss[j]-'A';

              }

       }

       memset(vis_le,0,sizeof(vis_le));//初始化vis_le数组

       memset(vis_,0,sizeof(vis_));//初始化vis_数组

       vis_le[g[0][0]]=1;vis_[0][0]=1;  //站在第一个点去向四周做选择，并把第一个点死锁

       search(0,0,1);   //因为第一个点有一个字母，故已访问一个字母，所以第三个参数为1

       cout<<Max<<endl;

       return 0;

}
