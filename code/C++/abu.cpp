#include<bits/stdc++.h>
#include<iostream>
using namespace std;
char s[8];
 
void move(char s[],int a,int b)//将s[a]插入到下标为b的位置（s[b]及之后的元素后移）
{
	char temp=s[a];
    for(int i=a-1;i>=b;--i)
    	s[i+1]=s[i];
	s[b]=temp;
}
 
void rmove(char s[],int a,int b)//复原移动之前的数组
{
	char temp=s[b];
	for(int i=b;i<a;++i)
	s[i]=s[i+1];
	s[a]=temp;
}
 
void perm(char s[],int k,int m)// s代表进行全排列的数组，
{                              // k代表将下标为k之前的数固定并对剩下的元素进行全排列，
    if(k==m)                   // m代表数组最后一个元素的下标
    {
        for(int i=0;i<=m;++i)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
    else 
    {
        for(int i=k;i<=m;++i)
        {
            move(s,i,k);
            perm(s,k+1,m);
            rmove(s,i,k);       //每次进行下一种开头的全排列前要将数组恢复原顺序
        }
    }
}
 
int main()
{
    cin>>s;
    int m=strlen(s)-1;
    perm(s,0,m);
}

//整体思路:每次将下标为第0，1，2 ··· 的数组元素插到第一位（注意使后面的数组元素保持要求的顺序），
//然后对其中后面的元素进行下一层的全排列。< 不用按字母序排列的问题看下面 >