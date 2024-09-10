#include<bits/stdc++.h>
using namespace std;

void divide_zhiyinshu(int x){
    int time=0;
    for (int i=2;i<=x/i;i++){
        int pw=0;
        if (x%i==0)time++;
        while (x%i==0){
            x/=i;
            pw++;
            
        }
        if (pw>1 && time==1)cout<<i<<'^'<<pw;
        else if (pw>1 && time!=1)cout<<'*'<<i<<'^'<<pw;
        else if (pw==1 && time!=1)cout<<'*'<<i;
        else if (pw==1 && time==1)cout<<i;

    }
    if (x>1 && time!=0)cout<<'*'<<x;
    else if (x>1 && time==0)cout<<x;
}


int main(){
    int n;cin>>n;
    divide_zhiyinshu(n);
    return 0;
}   