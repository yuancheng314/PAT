#include<iostream>
#include<vector>
using namespace std;

vector<int> G[1002],vis(1002);
int Father[1002];

int findFather(int x)
{   int a=x;
    while(x != Father[x])
        x=Father[x];
    //while循环过后的x即为最终的father,接下来进行路径压缩
    while(a!=Father[a])
    {
        int z=a;
        a=Father[a];
        Father[z]=x;
    }
    return x;
}
void Union(int a,int b)
{
    int father_a=findFather(a),father_b=findFather(b);
    if(father_a!=father_b)
        Father[father_a]=father_b;
}
void Init(int N)
{   //初始化father数组与hash数组   
    for(int i=1;i<=N;i++)
        Father[i]=i;
    fill(vis.begin(),vis.end(),0);
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

        Init(N); //每次查询都需要这步
        for(int k=1;k<=N;k++)
        {   //枚举每条边
            for(int j=0;j<G[k].size();j++)
            {   if(k==query || G[k][j]==query)  //跳过querry及与其相连的顶点。  
                    continue;
                Union(k,G[k][j]);
            }
        }

        block=0;       
        for(int i=1;i<=N;i++)
        {   //枚举每一个节点，看总共有多少个集合
            if(i==query) continue;
            int father_i=findFather(i);
            if(vis[father_i]==0)
            {   //如果当前连通块的根节点未被访问
                block++;
                vis[father_i]=1;
            }
        }
        printf("%d\n",block-1);//需要添加的边数为连通分量个数减一
    }

    return 0;
}