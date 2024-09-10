#include <bits/stdc++.h>

using namespace std;

// m = apple; n = plate;
int apple(int m, int n)
{
	if (m < 0 ) {
		return 0;
	}
	
	if (m == 1 || n == 1) {
		return 1;
	}
	return apple(m, n-1) + apple(m-n, n);
}

int main()
{
	int m = 0, n = 0;
	int time;cin>>time;
    for (int i=0;i<time;i++){
        cin>>m>>n;
        cout<<apple(m,n)<<endl;
    }
	
	
	return 0;
}

