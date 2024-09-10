#include<bits/stdc++.h>
using namespace std;
int sum=0;

int main(){
    int time;
    while (cin>>time && time){
        vector<int>v1;
        sum=0;
        int cengshu=0;
        for (int i=0;i<time;i++){
            int n;cin>>n;
            v1.push_back(n);
        }
        for (int i=0;i<time;i++){
            if (v1[i]>cengshu){
                sum+=6*(v1[i]-cengshu)+5;
                cengshu=v1[i];
            }
            else if (v1[i]<cengshu){
                sum+=4*(cengshu-v1[i])+5;
                cengshu=v1[i];
            }
            else sum+=5;
        }
        cout<<sum<<endl;
    }





    return 0;
}