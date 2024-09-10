#include<bits/stdc++.h>
using namespace std;
string print_map(map<string,int>h){
    string str1;
    int max=-1;
    for (auto x:h){
        if (x.second>max){
            str1=x.first;
            max=x.second;
        }
    }
    return str1;
}
int main(){
    int time;
    map<string,int>v1;
    while (1){
        cin>>time;
        if (time){for (int i=0;i<time;i++){
            string str;cin>>str;
            v1[str]++;
        }
        cout<<print_map(v1)<<endl;
        v1.clear();
        }
        else return 0;
        
    }



    return 0;
}