#include<iostream>
#include<algorithm>
#define maxn 1005

using namespace std;
 
int father[maxn],isroot[maxn],course[maxn]={0};

int Init(int N)
{   for(int i=1;i<=N;i++)
    {    father[i]=i;
         isroot[i]=false;
    }
}

int findfather(int x)
{   int a=x;
    while(x!=father[x])
        x=father[x];
    //路径压缩
    int z;
    while(a!=father[a])
    {   z=a;   
        a=father[a];
        father[z]=x;
    }

    return x;
}

int Union(int a,int b)
{   int fa_a=findfather(a);
    int fa_b=findfather(b);
    if(fa_a!=fa_b)
        father[fa_a]=fa_b;
}

int cmp(int a,int b)    {   return a>b; }

int main()
{   
    int N,K,h,count=0;
    scanf("%d",&N);
    Init(N);
    for(int i=1;i<=N;i++)  //对于第i个人
    {   scanf("%d:",&K);
        for(int j=0;j<K;j++) //对于i喜欢的的第k项活动
        {   scanf("%d",&h);
            if(course[h]==0) //还没有人喜欢活动h
                course[h]=i;
            else Union(i,findfather(course[h]));
        }
    }

    for(int i=1;i<=N;i++)
       isroot[findfather(i)]++; //找到i的根节点，人数+1
    for(int i=1;i<=N;i++)
        if(isroot[i]!=0)
            count++;

    printf("%d\n",count);
    sort(isroot,isroot+maxn,cmp);
    cout<<isroot[0];
    for(int i=1;i<count;i++)
        cout<<" "<<isroot[i];

    return 0;
}