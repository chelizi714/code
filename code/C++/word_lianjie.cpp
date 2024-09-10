#include <bits/stdc++.h>
using namespace std;
int n, mark[25]={0}, ans=0;
char c;
string ss[25], s;
string pj(string s1, string s2)
{
    int len1 = s1.length(), len2 = s2.length(); 
    for (int i=1; i<len1 && i<len2; i++) {      
        if (s1.substr(len1-i, i) == s2.substr(0, i)) {
            return s1.substr(0, len1-i)+s2;
        }
    }
    return "0";
}
void dfs(string drag)
{
    if (drag.length()>ans) ans = drag.length();     //更新数据
    for (int i=1; i<=n; i++) {
        if (mark[i]==2) continue;       //判断是否为两次
        s = pj(drag, ss[i]);        
        if (s!="0") {
            mark[i]++;
            dfs(s);
            mark[i]--;
        }
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> ss[i];
    }
    cin >> c;
    for (int i=1; i<=n; i++) {
        if (ss[i][0]==c) {
            mark[i]++;
            dfs(ss[i]);
            mark[i]--;
        }
    }
    cout << ans << endl;
    return 0;
}