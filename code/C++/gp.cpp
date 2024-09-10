#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
  long long  n,k;
  cin>>n>>k;
  //long long sum=pow(n,k);
  long long  sum=n;
  //cout<<sum<<endl;
  long long res=1;
  map<long long,long long>v1;
  for (int i=2;i<=sum/i;i++){
    while (sum%i==0){
      sum/=i;
      v1[i]+=k;
    }
    res=res*(v1[i]+1)%mod;
  }
  if (sum>1){
	  v1[sum]+=k;
  	res=res*(v1[sum]+1)%mod;	
  }


  //for (auto x:v1)cout<<x.first<<" "<<x.second<<endl;

  //int res=1;
  //for (auto x:v1){
  //  int y=x.second;
  //  res=res*(y+1)%mod;
  //}
  
  
 
  cout<<res%mod;
  return 0;
}

/**
* @runId: 861
* @language: C++
* @author: 车厘子
* @submitTime: 2024-06-03 10:49:48
*/