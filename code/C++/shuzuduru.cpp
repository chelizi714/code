#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&v2,int n,int m ){
	if (n<0 || m<0 || m>=v2[0].size() || n>=v2.size() || v2[n][m] != 1)return ;
	v2[n][m]=0;
	dfs (v2,n-1,m);
	dfs (v2,n+1,m);
	dfs (v2,n,m-1);
	dfs (v2,n,m+1);
}




int main(){
	int a,b;cin>>a>>b;
	vector<vector<int>> v1(a,vector<int>(b));

	for (int i=0;i<a;i++){
		for (int j=0;j<b;j++){
			cin>>v1[i][j];
		}
	}
	//cout<<v1[0];


	int count=0;
	for (int i=0;i<a;i++){
		for (int j=0;j<v1[0].size();j++){
			if (v1[i][j]==1){
				count++;
				dfs(v1,i,j);
			}
			}
			
		}
	
	cout<<count;

	return 0;
}