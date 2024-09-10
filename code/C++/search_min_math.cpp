#include<bits/stdc++.h>
using namespace std;
int zhuanhuan(int n){
    vector<int>C;
    int time=0;
    while (n){
        C.push_back(n%2);
        n/=2;
    }
    for (int i=0;i<C.size();i++)if (C[i]==1)time++;
    return time;
}





int main(){
    int zhi;
    whlie (cin>>zhi){
        int yuan=zhuanhuan(zhi);
        for (int i=zhi+1;;i++){
            int h=zhuanhuan(i);
            if (h==yuan){
                    cout<<i<<endl;
                    break;
            }
        }
    }



    return 0;
}