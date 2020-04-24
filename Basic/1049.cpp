#include<iostream>
using namespace std;

int main()
{   int n,now;
    double sum=0.0
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lf",&now);
        sum+=now*i*(n+1-i);
    }
    printf("%.2f",sum);
    return 0;
}