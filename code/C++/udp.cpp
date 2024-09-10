#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1;

bool cmp(vector<int> &A,vector<int>&B){
  if (A.size()!=B.size())return A.size()>B.size();
  for (int i=A.size()-1;i>=0;i--){
    if (A[i]!=B[i]) return A[i]>B[i];
  }
  return true;
}
vector<int> mes(vector<int>&A,vector<int>&B){
  vector<int>C;
  for (int i=0,t=0;i<A.size();i++){
    t=A[i]-t;
    if (i<B.size())t-=B[i];
    C.push_back((t+10)%10);
    if (t<0)t=1;
    else t=0;
  }
  while (C.size()>1 && C.back()==0)C.pop_back();

  return C;
}







int main()
  {
	string a,b;
  vector<int>v1;
  vector<int>v2;
  cin>>a>>b;
  for (int i=a.size()-1;i>=0;i--)v1.push_back(a[i]-'0');
  for (int i=b.size()-1;i>=0;i--)v2.push_back(b[i]-'0');
  vector<int>u;
  
  for (int i=u.size()-1;i>=0;i--)cout<<u[i];
  if (cmp(v1,v2)){
    u=mes(v1,v2);
    for (int i=u.size()-1;i>=0;i--)cout<<u[i];
  }
  else {
    cout<<"-";
    u=mes(v2,v1);
    for (int i=u.size()-1;i>=0;i--)cout<<u[i];
  }

	return 0;
}
  
  
  
