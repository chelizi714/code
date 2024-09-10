//高精度加法
#include<bits/stdc++.h>
using namespace std;
#define LL long long ;

void tianjia(string n,string m){
    vector<int>a;
    vector<int>b;
    vector<int>c;
    //memset(a,0,sizeof(a));
    //memset(b,0,sizeof(b));
    //memset(c,0,sizeof(c));
    int t=0;
    int length=0;
    if (n.size()<m.size())return tianjia(m,n);
    for (int i=n.size()-1;i>=0;i--)a.push_back(n[i]-'0');
    for (int j=m.size()-1;j>=0;j--)b.push_back(m[j]-'0');
    for (int i=0;i<n.size();i++){
        t=t+a[i];
        if (i<m.size())t+=b[i];
        c.push_back(t%10);
        t=t/10;
        length=i;
    }
    if (t>0)cout<<t;
    for (int i=length;i>=0;i--)cout<<c[i];
    
}
int main(){
    
    int time;cin>>time;
    for (int i=1;i<=time;i++){
        string v1,v2;
        cin>>v1>>v2;
        cout<<"Case "<<i<<":"<<endl;
        cout<<v1+" + "+v2<<" = ";
        tianjia(v1,v2);
        cout<<endl;
        if (i!=time){
            cout<<endl;
        }

    }
    //cout<<v1<<endl;
    
    return 0;
}