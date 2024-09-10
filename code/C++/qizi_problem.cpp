#include<bits/stdc++.h>
using namespace std;
char a[10][10];
int vis[10]; //记录前几层的棋子位置
int cnt=0; //记录种类数
int way=0;  //记录棋子的个数
int m,k;


void dfs(int n){
    if (way==k){
        cnt++;
        return ;
    }
    if (n>=m){
        return ;
    }
    for (int i=0;i<m;i++){
        if (!vis[i] && a[n][i]=='#'){
            vis[i]=1;
            way++;
            dfs(n+1);
            vis[i]=0;
            way--;
        }
    }
    dfs(n+1);		//还需要额外加一个如果这一行不存在可以添加的，直接到下一行
}


int main(){
    
    while (cin>>m>>k){
        if (m==-1 & k==-1)break;
        for (int i=0;i<m;i++){
            for (int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        dfs(0);
        cout<<cnt<<endl;
        memset(a,0,sizeof(a));
        cnt=0;
        way=0;
    }

    return 0;
}



