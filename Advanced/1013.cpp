#include<iostream>
#include<vector>
using namespace std;

vector<int> G[1002],vis(1001);
void DFS(int i,int query) //对于图Ｇ，删除顶点query及其连接的边，遍历顶点i所在连通分量
{   if(i==query) return; //递归调用的边界条件，这一步很关键
    vis[i]=1;
    int size=G[i].size();
    for(int j=0;j<size;j++)
        if(vis[G[i][j]]==0) //当与顶点i所连接的顶点j没有被访问时,对j进行深度有限访问
            DFS(G[i][j],query);
}

int main()
{   int N,M,K,a,b,query,block; //a和b为两个顶点,block为连通分量的个数
    cin>>N>>M>>K;

    for(int i=0;i<M;i++)
    {   
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i=0;i<K;i++)
    {
        scanf("%d",&query);
        //查询
        fill(vis.begin(),vis.end(),0); //每次查询都需要这步
        block=0;
        for(int i=1;i<=N;i++)   //枚举每一个节点
        {   //如果未被删除且未被访问
            if(i!=query && vis[i]==0) 
            {
                 DFS(i,query);
                 block++;
            }
        }
        //需要添加的边数为连通分量个数减一
        printf("%d\n",block-1);
    }

    return 0;
}