#include<bits/stdc++.h>
using namespace std;
bool vis[8][8];
bool queen[8][8];
vector<string>v2;
int cn;
void dfs(int n){
    if (n==8){
        string str;
        //cout << "No. " << ++cn << endl;
        for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                if (queen[i][j]==true)str.append(to_string(j+1));
            }
            
        }

        v2.push_back(str);
        return ;
    }
    bool backup[8][8];
    int dx[]={-1,1,0,0,-1,-1,1,1};
    int dy[]={0,0,-1,1,-1,1,-1,1};
    for (int i=0;i<8;i++){
        if (vis[n][i])continue;    //vis[i][n]和vis[n][i]在此处表达的含义是不同的，输出的结果也会不相同，要注意题目输出的顺序
                                    //n表示层数，i表示列数
                                    //如题目输出表示应该以列为检索
        
        queen[n][i]=true;
        memcpy(backup,vis,sizeof(vis));     //备份，为了之后的回溯做准备
        //vis[n][i]=true;
        
        for(int j=1;j<8;j++){
            for (int h=0;h<8;h++){
                int nx,ny;
                nx=n+j*dx[h];
                ny=i+j*dy[h];
                if (nx>=0 && nx<8 && ny>=0 && ny<8){vis[nx][ny]=true;}
                                }
                            }
        dfs(n+1);
        queen[n][i]=false;
        memcpy(vis,backup,sizeof(backup));      //回溯
        }
        
    }










int main(){
    ios::sync_with_stdio(false);    //消除cin的缓冲区，直接读入，节约读入时间
                                    //打消iostream的输入 输出缓存
    dfs(0);
    int n;cin>>n;
    for (int i=0;i<n;i++){
        int time;cin>>time;
        cout<<v2[time-1]<<endl;
    }


    return 0;
}