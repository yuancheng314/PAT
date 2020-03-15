#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{   int k=3;
    double a,b,c,max,res=1.0;
    while(k--)
    {   cin>>a>>b>>c;
        if( a>b && a>c )
        {   cout<<'W'<<" ";
            max=a;
        }
        else if(b>a && b>c)
        {   cout<<'T'<<" ";
            max=b;
        }
        else if(c>a && c>a)
        {   cout<<'L'<<" ";
            max=c;
        }
        res*=max;
    }
    printf("%.2f",(res*0.65-1)*2);
   
    return 0;
}
