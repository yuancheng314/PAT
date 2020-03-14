#include<cstdio>
#include<iostream>
using namespace std;

int main()
{   int N,a,b,c,d,count1=0,count2=0;
    scanf("%d",&N);

    for(int i=1;i<=N;i++)
    {   cin>>a>>b>>c>>d;
        if(a+c==b && b!=d) // //甲赢乙喝
        {   count2++;      } 
        if(a+c==d && b!=d) // //乙赢甲喝
        {   count1++;      } 
    }
    cout<<count1<<' '<<count2<<endl;

    return 0;
}
