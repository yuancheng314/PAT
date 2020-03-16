#include<cstdio>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main()
{   int  N,M,K,ele,b,c;
    scanf("%d",&N);
    set<int> a[N+1];

    for(int i=1;i<=N;i++)
    {   scanf("%d",&M);
        for(int j=1;j<=M;j++)
        {   scanf("%d",&ele); 
            a[i].insert(ele);
        }
    }
    
    scanf("%d",&K);
    double ans[K];
    for(int i=0;i<K;i++)
    {   scanf("%d%d",&b,&c);
        set<int>  un,in;
        set_intersection(a[b].begin(),a[b].end(),a[c].begin(),a[c].end(),inserter(in,in.begin() ) );
       // set_union(a[b].begin(),a[b].end(),a[c].begin(),a[c].end(),inserter(un,un.begin() ) );
        ans[i]=in.size()*100.0/(a[b].size()+a[c].size()-in.size());
        //在这道题中，如果同时使用求交集和求并集的两个函数，有个测试点会超时  
    }
    
    for(int i=0;i<K;i++)
        printf("%.1f%%\n",ans[i]);

    return 0;
}
