#include<bits/stdc++.h>
using namespace std;

const int N=1010;


int main(){
  int n,m;cin>>n>>m;
  int v[N]={0};
  int w[N]={0};
  int zhuantai[N][N];

  for (int i=1;i<=n;i++){
    cin>>v[i]>>w[i];
  }
  for (int i=1;i<=n;i++){
    for (int j=0;j<=m;j++){
      
      if (j>=v[i]){
        zhuantai[i][j]=max(zhuantai[i-1][j],zhuantai[i-1][j-v[i]]+w[i]);
      }
      else {
        zhuantai[i][j]=zhuantai[i-1][j];
      }
    }
  }
  int min=zhuantai[n][m];
  for (int i=n;i<=n;i++){
    for (int j=0;j<=m;j++){
      if (min>=zhuantai[i][j])min=zhuantai[i][j];
    }
  }
  cout<<maxs;

  return 0;
}