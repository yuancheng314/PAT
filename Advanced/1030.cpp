#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Node{
    int v,dis,cost;
    Node(int _v,int _dis,int _cost):v(_v),dis(_dis),cost(_cost){};
};

const int maxn=501,inf=0xfffffff;
int N,M,S,D,c[maxn],d[maxn],vis[maxn]={0},pre[maxn]; //c记录cost,d记录distance
vector<vector< Node > > G; 

void Dijkstra(int start)
{   //初始化
    fill(d,d+maxn,inf);
    fill(c,c+maxn,inf);
    for(int i=0;i<N;i++) pre[i]=i;
    d[start]=0;
    c[start]=0;

    for(int i=0;i<N;i++)
    {
        int u=-1,MIN=inf;
        for(int j=0;j<N;j++)
        {
            if(vis[j]==0 && d[j]<MIN )
            {
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1)   return;

        vis[u]=1;
        
        for(int k=0;k<G[u].size();k++)
        {   int v=G[u][k].v;
            if(vis[v]==0) //当前节点未被访问
            {   //以u为中介点能令d[v]变小
                if(d[u]+G[u][k].dis<d[v])
                {
                    d[v]=d[u]+G[u][k].dis;
                    c[v]=c[u]+G[u][k].cost;
                    pre[v]=u; //令v的前驱为u
                } 
                else if(d[u]+G[u][k].dis==d[v])
                {   //看看能不能优化c[v]
                    if(c[u]+G[u][k].cost<c[v])
                    {
                        c[v]=c[u]+G[u][k].cost;
                        pre[v]=u;
                    } 
                }
            }
        }
    }
}

void DFS(int end) //打印路径
{
    if(end==S) 
    {   printf("%d ",end);
        return;
    }
    DFS(pre[end]);
    printf("%d ",end);
}
int main()
{
    scanf("%d%d%d%d",&N,&M,&S,&D);
    G.resize(N);

    int u,v,cost,dis;
    for(int i=0;i<M;i++)
    {   scanf("%d%d%d%d",&u,&v,&dis,&cost);
        
        G[u].push_back(Node(v,dis,cost));
        G[v].push_back(Node(u,dis,cost));
    }
    
    Dijkstra(S);
    DFS(D);
    printf("%d %d",d[D],c[D]);
    return 0;
}
