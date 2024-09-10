#include <iostream>
using namespace std;
 
int main(){
	int a, b, n, i;
	int f[50];
	f[1] = f[2] = 1;
	while (cin >> a >> b >> n && (a || b || n)) {
		for (i = 3;i < 50;i++){
			f[i] = (a * f[i - 1] + b * f[i - 2]) % 7;
			if (f[i] == 1 && f[i - 1] == 1)  //此时为一次循环;
				break;
		}
		n = n % (i - 2);   //对循环次数（循环次数要去掉最后两次）取余表示第几个
		f[0] = f[i - 2];
		cout << f[n];
	}
	return 0;
}