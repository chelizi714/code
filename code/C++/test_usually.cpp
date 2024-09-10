#include <bits/stdc++.h>
using namespace std;


int main(){
    int time;
    cin>>time;

    map<string,int>v1;


    for (int i=0;i<time;i++){
        string str;
        cin>>str;
        if(v1[str]==0){
            v1[str]++;
            cout<<"OK"<<endl;
        }
        else{
            cout<<str<<v1[str]<<endl;
            v1[str]++;
        }
    }





    return 0;
}