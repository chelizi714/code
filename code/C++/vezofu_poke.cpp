#include<bits/stdc++.h>
using namespace std;
bool dfs(int a, int b){
    if(a < b)  swap(a, b);      //保证多的石子在前
    if(a >= 2*b || a==b) return true;  //当前处于局面1、局面3，获胜
    return  !dfs(a-b, b);      //局面2，对方只能取a-b,因为是看先手，所以要加个非
}
int main(){
    int a,b;
    while(cin>>a>>b && (a+b)) {
        if(dfs(a, b)) cout<<"win" <<endl;
        else          cout<<"lose"<<endl;
    }
    return 0;
}

