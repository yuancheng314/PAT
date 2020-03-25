#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{   int N,p,max_len=1;
    scanf("%d%d",&N,&p);
    int num[N];
    for(int i=0;i<N;i++)
        scanf("%d",&num[i]);
    sort(num,num+N);
    for(int i=0;i<N;i++)
    {      
        int j=upper_bound(num+i+1,num+N,(long long)num[i]*p)-num;
        max_len=max(j-i,max_len);    
    }    

    printf("%d",max_len); 

    return 0;
}