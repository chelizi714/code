#include<bits/stdc++.h>
using namespace std;
int group[15];
vector<int>groupend[15];
int groupcount=0;
int n;
int gcd(int a,int b){
    if (a<b)return gcd(b,a);
    return b ?  gcd(b,a%b): a;
}
void dfs(int index){//现在正在处理第index个数（第index还没处理）
    if (index==n)return ;
    int t=0;
    int flag2=0;
    for (int i=0;i<groupcount;i++){
            int flag1=0;
            for (int j=0;j<groupend[i].size();j++){
                t=gcd(group[index],groupend[i][j]);
            if (t!=1){
                flag1=1;
                break;
            }
            
            }
            if (flag1==0){
                flag2=1;
                groupend[i].push_back(group[index]);
                break;
            }
    }
    if (flag2==0){
        groupend[groupcount++].push_back(group[index]);
    }

    dfs(index+1);
    return ;





}


int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=0;i<n;i++)cin>>group[i];
    dfs(0);
    cout<<groupcount<<endl;

    return 0;
}