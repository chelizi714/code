#include<bits/stdc++.h>
using namespace std;
string s;
int n,m;
bool b[101];
char c[101];
int k[101];
int main(){
	while(cin>>s){
		m = 0;
		
		n = s.size();
		for(int i=0;i<n;i++){
			if(s[i] == '('){
				m++;
				c[m] = '(';
				k[m] = i;
			}
			if(s[i] == ')'){
				int p = m;
				while(p>=1){
					if(c[p] == '('){
						m--;
						break;
					}
					p--;
				}
				if(p == 0){
					m++;
					c[m] = ')';
					k[m] = i;
				}
			}
		}
		cout<<s<<endl;
		for(int i=1;i<=m;i++){
			if(c[i] == '('){
				s[k[i]] = '$';
			}else	if(c[i] == ')'){
				s[k[i]] = '?';
			}
		}
		for(int i=0;i<n;i++){
			if(s[i] == '$' || s[i] == '?'){
				cout<<s[i];
			}else{
				cout<<" ";
			}
		}
		cout<<endl;
	} 
    return 0;
}