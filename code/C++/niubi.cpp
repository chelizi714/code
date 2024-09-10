#include <bits/stdc++.h>
#include<stdlib.h>
using namespace std;
string s;//用字符类型导致只能读取一个字符，超过一位数的数字就只能读第一位 
double f() {
	cin>>s;
	if(s=="+")
		return f()+f();
	else if(s=="-")
		return f()-f();
	else if(s=="*")
		return f()*f();
	else if(s=="/")
		return f()/f();
	else//即输入的为数字，直接转化为浮点型返回
		return atof(s.c_str());//c++中的将字符数组转化为浮点数 
}
int main() {
	printf("%f\n",f());
	return 0;
}




