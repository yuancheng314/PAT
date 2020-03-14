#include<cstdio>
#include<iostream>

using namespace std;

int main()
{   long long A,B,C,sum;
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        scanf("%lld %lld %lld",&A,&B,&C);
        sum=A+B;
        if(A>0 && B>0 && sum<0 ) //正溢出，A+B必然大于C 
        {   printf("Case #%d: true\n",i);  }
        else if(A<0 && B<0 && sum>=0 ) //负溢出，A+B必然小于C
        {   printf("Case #%d: false\n",i);  }
        else if(sum>C)
        {   printf("Case #%d: true\n",i);  }   
        else
        {   printf("Case #%d: false\n",i);  }
         
    }

    return 0;
}
