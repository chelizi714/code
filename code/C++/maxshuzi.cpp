#include<iostream>
using namespace std;

long long MaxComDivisor(long long m,long long n)
{
    if(m%n==0)
        return n;
    long int a=m%n;
    m=n;
    n=a;
    return MaxComDivisor(m,n);    
}
 
int main()
{
    long long  a,b;
    cin>>a>>b;
    cout<<"gcd="<<MaxComDivisor(a,b);
}
