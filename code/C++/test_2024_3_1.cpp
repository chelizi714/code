#include <iostream>
#include <cstdio>


using namespace std;


int main()
{   
    for (int i = 2;i <= 100 ; i ++ )
    {
        bool is_prime = true;
        for (int j = 2 ; j < i ; j ++ )
        {
            if (i % j == 0) 
            {
                is_prime = false;
                break;
            }
        
        }
        if (is_prime){
            printf("%d ",i);
            };
    }
    
    return 0;
}