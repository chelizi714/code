#include<bits/stdc++.h>
using namespace std;
void judge(int n)   //返回最大项是2的多少次幂
{
    //结尾可能是2或者1 若为2 直接输出2 若为1 直接输出2(0) 且最后不需要任何符号
    if (n==1){
        cout<<2<<"("<<0<<")";
    }
    //若直接n已经为零了 就不需要再进行任何输出直接返回 
    else if (n==0) {
        return ;
    }
    else if (n==2){
        cout<<2;
    }
    else {
        int i,j;
        for (int i=1;i<=14;i++){    //i为2的多少次幂
            int sum=2;
            for (int j=2;j<=i;j++){
                sum*=2; 
            }
        if ((n-sum)>=0 && (n-sum)<sum){ //若为2次幂可直接输出 因为零次幂已经在上面输出了 
            n=n-sum;
            if (i==2){
                cout<<2<<"("<<i<<")";
                //如果n不为0 即后面还有项 要输出加号
                if (n!=0)cout<<"+";
            }
            else if (i==1){
                cout<<2;
                //和上面一样 如果n不为0 即后面还有项 要输出加号 
                if (n!=0)cout<<"+";
            }
            else {
                cout<<2<<"(";
                judge(i);//将i也输出成上面的模样 小到2时结束 
                cout<<")";
                //和上面一样 如果n不为0 即后面还有项 要输出加号 
                if (n!=0)cout<<"+";
            }
            judge(n);
        }
        }
        
    }
}







int main(){
    int time;cin>>time;
    judge(time);


    return 0;
}