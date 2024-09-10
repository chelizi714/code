#include<bits/stdc++.h>
int a[100010];
int main()
{
	int T,i,k,n,sum,max,begin,end,t;
	scanf("%d",&T);
	for(k=1;k<=T;k++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sum=0;
		max=-99999999;
		t=begin=end=1;
		for(i=1;i<=n;i++)
		{
			sum+=a[i];
			if(sum>max)
			{
                
                max=sum;
				begin=t;
				end=i;
			}
			if(sum<0)
			{
				sum=0;
				t=i+1;
			}
		}
		printf("Case %d:\n%d %d %d\n",k,max,begin,end);
		if(k!=T)
			printf("\n");//控制输出格式
	}
	return 0;
}