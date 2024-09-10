#include<bits/stdc++.h>
using namespace std;
void print(int n,char start,char end){
    printf("%c->%d->%c\n",start,n,end);
}
void hanota(int v,char start,char fuzhu,char end){
    if (v==1)print(v,start,end);
    else {
        hanota(v-1,start,end,fuzhu);
        print(v,start,end);
        hanota(v-1,fuzhu,start,end);
    }
}



int main(){
    int geshu;cin>>geshu;
    char number1,number2,number3;
    cin>>number1>>number2>>number3;
    hanota(geshu,number1,number3,number2); 



    return 0;
}