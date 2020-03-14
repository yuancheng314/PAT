#include<cstdio>
#include<iostream>

using namespace std;

int main()
{   double coe,A[1001]={0.0};
    int K,exp,line=2,count=0;
    while(line--)
    {
        cin>>K;
        while(K--)
        {   cin>>exp>>coe;      
            A[exp]+=coe;    
        }
    }

    for(int i=0;i<=1000;i++)
    {   if(A[i]) count++;
    }    
    cout<<count;
    for(int i=1000;i>=0;i--)
    {   if(A[i])
            printf(" %d %.1f",i,A[i]);
    }
    
    return 0;
}
