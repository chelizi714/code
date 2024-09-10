#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<iomanip>
using namespace std;
int maxhalf=43200;  //12小时是多少秒
double hm,hs,ms,T_hm,T_hs,T_ms;
void speed()
{
    double h,m,s;
    h=30.0/3600;     //时针的速度 度/秒       时针一小时30度3600秒
    m=360.0/3600;    //分针的速度  度/秒  分针一圈360度为3600秒
    s=360.0/60;      //秒针的速度  度/秒    分针一圈360度60秒
    hm=m-h;            //速度差   时针和分针的速度差
    hs=s-h;         //时针和秒针的速度差
    ms=s-m;         //分针和秒针的速度差
    T_hm=360/hm;        //时针和分支差值为一圈需要多少秒
    T_hs=360/hs;        //时针和秒针差值为一圈需要多少秒
    T_ms=360/ms;        //分针和秒针差值为一圈需要多少秒
}
 
double maximum(double a,double b,double c)     //求最大值 
{
    return max(max(a,b),c);
}
double minmum(double a,double b,double c)       //求最小值 
{
    return min(min(a,b),c);
}
int main()
{
    speed();
    double n;
    while(scanf("%lf",&n)&&n!=-1)
    {
        double a[6],i,j,k,begintime,endtime,result=0;
        a[0]=n/hm;          //时针和分针差值为n度需要多少时间
        a[1]=n/hs;          //时针和秒针差值为n度需要多少时间
        a[2]=n/ms;          //分针和秒针差值为n度需要多少时间
        a[3]=(360-n)/hm;    //时针和分针再重合前n度所需的时间
        a[4]=(360-n)/hs;    //时针和秒针再重合前n度所需的时间
        a[5]=(360-n)/ms;    //分针和秒针再重合前n度所需的时间
        for(i=0;i<=1.0*maxhalf;i+=T_hm)
        {
            for(j=0;j<=1.0*maxhalf;j+=T_hs)
            {
                if(j+a[1]>i+a[3]) break;   //时针和秒针差距到达n度的时间比时针和分针差距到达n度的时间长
                if(i+a[0]>j+a[4]) continue;     //时针和分针差距为n度的时间比时针和秒针差距n度的时间要长
                for(k=0;k<=1.0*maxhalf;k+=T_ms)
                {
                    if(k+a[2]>i+a[3]||k+a[2]>j+a[4]) break;     //分针和秒针差距n度所需的时间比分针和时针的差距n度的时间；分针和秒针差距n度所需的时间比时针和秒针差距n度的时间大
                    if(i+a[0]>k+a[5]||j+a[1]>k+a[5]) continue;      //时针和分针差距n度的时间比（分针和秒针差距n度的时间大）；时针和秒针差距n度的时间分针和秒针差距n度的时间大
                    begintime=maximum(i+a[0],j+a[1],k+a[2]);
                    endtime=minmum(i+a[3],j+a[4],k+a[5]);
                    if(endtime>begintime)
                        result+=(endtime-begintime);
                }
            }
        }
        printf("%.3lf\n",result/432); 
    }
}


