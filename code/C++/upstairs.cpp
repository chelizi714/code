#include<bits/stdc++.h>
using namespace std;
int digui(int n){
    if (n<0)return 0;
    else if (n==0)return 1;
    else return digui(n-1)+digui(n-2);
}
int main(){
    int v;
    while (cin>>v)cout<<digui(v)<<endl;
    return 0;
}