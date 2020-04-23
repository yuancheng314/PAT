#include<iostream>
#include <algorithm>
using namespace std;

const int maxn=501,inf=0x3fffffff;
int N,M,c1,c2; //G为图，weight记录点权，dis记录起始点到每一个点的最短距离，vis记录点是否被访问
int G[maxn][maxn],weight[maxn]={0},dis[maxn],vis[maxn]={0},num[maxn]={0},w[maxn]={0};
//num记录起始点到每一个点最短路径条数，w记录最大点权和

void Dijkstra(int start)
{   fill(dis,dis+maxn,inf); //初始化距离为无穷大
   // fill(vis,vis+maxn,0);
    dis[start]=0; //更新起始点信息
    num[start]=1;
    w[start]=weight[start];

    for(int i=0;i<N;i++) //循环n次
    {
        int u=-1,MIN=inf; //u使d[u]最小，MIN存放该最小的d[u]
        for(int j=0;j<N;j++)
        {   //找到未访问的顶点中d[]最小的
            if(vis[j]==0&&dis[j]<MIN)
            {
                u=j;
                MIN=dis[j];
            }
        }
        
        //找不到小于inf的d[u],说明剩下的顶点和起点不连通
        if(u==-1) return;
        vis[u]=1; //更改u的访问标识

        for(int v=0;v<N;v++)
        {   //如果k未被访问 且u能到达v 且 以u为中介点可以使d[v]更优
            if(vis[v]==0 && G[u][v]!=inf)
            {
                if(dis[u]+G[u][v]<dis[v])   //以u为中介点时能令d[v]变小
                {   dis[v]=dis[u]+G[u][v]; //覆盖d[v]
                    w[v]=w[u]+weight[v]; //覆盖w[v]
                    num[v]=num[u]; //覆盖num[v]
                }
                else if(dis[u]+G[u][v]==dis[v]) //找到一条长度相同的路径
                {    num[v]+=num[u];
                    //看能不能更新点权和,可以的话便更新
                    if(w[u]+weight[v]>w[v]) 
                        w[v]=w[u]+weight[v];
                } 
            } 
        }
        }
    }
}

int main()
{   scanf("%d%d%d%d",&N,&M,&c1,&c2);
    for(int i=0;i<N;i++) //读入点权
        scanf("%d",&weight[i]);
    fill(G[0],G[0]+maxn*maxn,inf); //初始化图,注意二维数组与一维数组fill函数调用的不同
    
    int u,v,edge_weight;
    for(int i=0;i<M;i++)
    {   //读入边权信息
        scanf("%d%d%d",&u,&v,&edge_weight);
        G[u][v]=G[v][u]=edge_weight;
    }
    Dijkstra(c1);
    printf("%d %d",num[c2],w[c2]);
    return 0;
}
