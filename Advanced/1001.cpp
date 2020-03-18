#include<iostream>
using namespace std;

int main()
{
    int a,b,res[10]={0},count=0;
    scanf("%d %d",&a,&b);
    a+=b;
    if(a<0) { printf("-"); a=-a; }
   
    while(a/1000)
    {   res[count++]=a%1000;
        a/=1000;
    }
    cout<<a;
    for(int i=count-1;i>=0;i--)
    printf(",%03d",res[i]);

}
