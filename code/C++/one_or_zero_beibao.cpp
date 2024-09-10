#include<bits/stdc++.h>
using namespace std;
int v[1005][1005];   // v[i][j], j体积下前i个物品的最大价值
int k[1005];   //价值
int zhantiji[1005]; //体积
int main(){
    int x,y;cin>>x>>y;
    for (int i=1;i<=x;i++){
        int meiwei,tiji;cin>>meiwei>>tiji;
        k[i]=meiwei;
        zhantiji[i]=tiji;
    }
    for (int i=1;i<=x;i++){
        for (int j=1;j<=y;j++){
            //  当前背包容量装不进第i个物品，则价值等于前i-1个物品
            if (j<zhantiji[i])v[i][j]=v[i-1][j];
            else {
                //当背包容量装的进第i个物品时，需要考虑价值大小,考虑是否选择第i个物品
            v[i][j]=max(v[i-1][j],v[i-1][j-zhantiji[i]]+k[i]);
                }
        }
    }
    cout<<v[x][y];




    return 0;
}