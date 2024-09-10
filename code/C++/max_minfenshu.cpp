#include<iostream>
using namespace std;
int getdult(int a,int b){
    if(a>b) swap(a,b);
    if(b%a == 0) return b;
    return b*getdult(a,b%a)/(b%a);
}
int getmaxyinshu(int a,int b){
    if (a<b) swap(a,b);
    if (a%b==0)return b;
    return getmaxyinshu(a%b,b);
}
int main(){
    int time;cin>>time;
    int fenmu[10];
    char fuhao[10];
    int fenzi[10];
    for (int i=0;i<time;i++){
        cin>>fenzi[i]>>fuhao[i]>>fenmu[i];
    }
    //for (int i=0;i<time;i++){
    //    cout<<fenzi[i]<<fuhao[i]<<fenmu[i]<<endl;
    //}
    int h;
    for (int i=0;i<time-1;i++){
        int m=getdult(fenmu[i],fenmu[i+1])/fenmu[i+1];
        int n=getdult(fenmu[i],fenmu[i+1])/fenmu[i];
        fenzi[i+1]*=m;
        fenmu[i+1]*=m;
        fenzi[i]*=n;
        fenmu[i]*=n;
        fenzi[i+1]+=fenzi[i];
        
    }
    h=getmaxyinshu(fenzi[time-1],fenmu[time-1]);
    fenzi[time-1]/=h;
    fenmu[time-1]/=h;
    if (fenmu[time-1]==1)cout<<fenzi[time-1];
    else cout<<fenzi[time-1]<<fuhao[time-1]<<fenmu[time-1];




    return 0;
}