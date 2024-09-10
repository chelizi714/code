#include<bits/stdc++.h>
using namespace std;
int W,H;
//int cnt=0;
int a[30][30];
int cnt;
int maxs=1;
int begin_x,begin_y;
int dict[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
void dfs(int x,int y){
    
    for(int i=0;i<4;i++){
        int nx=x+dict[i][0];    //下一个点的纵坐标,第几行
        int ny=y+dict[i][1];    //下一个点的横坐标，第几列
        if (nx>=0 && nx<H && ny>=0 && ny<W && a[nx][ny]==1){
            a[nx][ny]=0;
            cnt++;
            if (cnt>maxs)maxs=cnt;
            dfs(nx,ny);
            //maxs=time;
            
        }
        
    }
    //return cnt; 
    //v1.push_back()
}


int main(){
    while(cin>>W>>H){
        if (W==0 && H==0)break;
        memset(a,0,sizeof(a));          //初始化a数组
        
        //maxs=0;
        for (int i=0;i<H;i++){
            string str;cin>>str;
            for (int j=0;j<W;j++){
                if (str[j]=='.')a[i][j]=1;
                else if (str[j]=='@'){
                    begin_x=i,
                    begin_y=j;
                    a[i][j]=1;
                }
                else a[i][j]=0;
            }
        }
        cnt=0;
        maxs=1;
        dfs(begin_x,begin_y);
        cout<<maxs<<endl;
    }



    return 0;
}