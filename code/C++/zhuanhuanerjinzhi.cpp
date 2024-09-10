#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

const int N = 1e5 + 10;

int t, a, b, c, a1, b1, c1;

int main() {
	cin >> t;
	while (t--) {
		a1 = 2, b1 = 3, c1 = 4;
		a = b = c = 1;
        for (int i = 0; i<12;i++){
            int x,y;
            cin>>x>>y;
            if (x==1)/*紫色时候*/{
                if (a==1)/*紫色在表层的时候*/{
                    if (a1==b1)b--;/*表示没移动前紫色在绿色上方时*/
                    if (a1==c1)c--;/*表示没移动前紫色在黄色上方时*/
                    a1+=y;
                    if (a1==b1)b++;
                    if (a1==c1)c++;
                }else if (a==2){
                    if (a1==b1 && b==1)/*表示绿色在紫色上方*/
                    {
                        if (a1==c1)c-=2;/*表示没移动之前紫色在黄色上方，移动后黄色变成表层*/
                        a1+=y;
                        b1+=y;
                        if (a1==c1)c+=2;
                    }else if(a1==c1 && c==1)
                    {
                        if (a1==b1)b-=2;/*表示没移动之前紫色在绿色上方，移动后绿色变成表层*/
                        a1+=y;
                        c1+=y;
                        if (a1==b1)b=3;
                    }

                }else{
                    a1+=y;
                    b1+=y;
                    c1+=y;
                }
            }
            else if (x==2)/*绿色的时候*/{
                if (b==1)/*绿色在表层的时候*/{
                    if (b1==a1)a--;
                    if (b1==c1)c--;
                    b1+=y;
                    if (b1==a1)a++;
                    if (b1==c1)c++;
                }else if (b==2){
                    if (b1=a1 && a==1)/*表示紫色在绿色的上方*/
                    {
                        if (b1==c1)c-=2;
                        b1+=y;
                        a1+=y;
                        if (b1==c1)c+=2;
                    }
                    else if (b1==c1 && c==1)
                    {
                        if (b1==c1)c-=2;
                        b1+=y;
                        c1+=y;
                        if (b1==c1)c=3;
                    }
                    
                }
                else {
                    a1+=y;
                    b1+=y;
                    c1+=y;
                }
            }
            else if (x==3)/*黄色的时候*/{
                if (c==1){
                    if (c1==a1)a--;
                    if (c1==b1)b--;
                    c1+=y;
                    if (c1==a1)a++;
                    if (c1==b1)b++;
                }
                else if (c==2){
                    if (c1==a1 && a==1){
                        if (a1==c1)a-=2;
                        a1+=y;
                        c1+=y;
                        if (b1==c1)c+=2;
                    }
                    else if (c1==b1 && b==1){
                        if (c1==b1)b-=2;
                        b1+=y;
                        c1+=y;
                        if (c1==b1)b=3;
                    }
                    else{
                        a1+=y;
                        b1+=y;
                        c1+=y;
                    }
                }
            }
        }













    /*输出*/
    if (a1 == 9 && b1 == 9 && c1 == 9)
			cout << "Y" << endl;
	else cout << "N" << endl;
    }
    
    
    
    

    
    

    return 0;
    }