#include<iostream>
#include<vector>
using namespace std;

const int maxv=505,inf=0x3fffffff;
int C,N,Sp,M,Minneed=inf,Mintake=inf;
int G[maxv][maxv],d[maxv],weight[maxv];
vector<int> pre[maxv],temppath,path;
bool vis[maxv]={false};

void Dijkstra(int start){
    fill(d,d+maxv,inf);
    d[start]=0;

    for(int i=0;i<=N;i++){ 
        //注意总共是有N+1个顶点
        int u=-1,min=inf;
        for(int j=0;j<=N;j++){
            if(vis[j]==false && d[j]<min){
                u=j;
                min=d[j];
            }
        }
        if(u==-1)  return ; //找不到小于inf的d[u],说明剩下的顶点和起点start不联通

        vis[u]=true;
        for(int v=0;v<=N;v++){
            if(vis[v]==false && G[u][v]!=inf){ //节点未被访问且边存在
                if(d[u]+G[u][v]<d[v]){ //可更新最短距离
                    d[v]=d[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u]+G[u][v]==d[v]) //不能更新最短距离，但这个点也是最短路径
                    pre[v].push_back(u);
            }
        }

    }
}

void DFS(int v){
    temppath.push_back(v);
    if(v==0){ //递归边界
        int bring=0,need=0; //need表示从PCMB带来的自行车，bring代表到达当前站点时可以做补给的自行车
        for(int i=temppath.size()-1;i>=0;i--){
            int id=temppath[i];
            if(weight[id]>0){ //当前站点自行车有余
                bring+=weight[id];
            }else{
                if(bring>(-weight[id])) //带来的够补给
                    bring+=weight[id];
                else{//带来的不够补给
                    need+=(-weight[id]-bring);
                    bring=0;
                }
            }
        }
        if(need<Minneed){
            Minneed=need;
            Mintake=bring;
            path=temppath; 
        }else if(need==Minneed && bring<Mintake){
            Mintake=bring;
            path=temppath;
        }
        temppath.pop_back();
        return; 
    }

    for(int i=0;i<pre[v].size();i++)  DFS(pre[v][i]);
    temppath.pop_back();
}

int main(){
    scanf("%d%d%d%d",&C,&N,&Sp,&M);
    for(int i=1;i<=N;i++){ //0号点是PBMC，故点权记录从1开始
        scanf("%d",&weight[i]);
        weight[i]-=C/2; //这样变换后就能够直接通过weight[i]的正负判断应该带来还是带走
    }
    int u,v;
    fill(G[0],G[0]+maxv*maxv,inf); //注意一维数组和二维数组fill填充的不同之处
    for(int i=0;i<M;i++){
        scanf("%d %d",&u,&v);
        scanf("%d",&G[u][v]);
        G[v][u]=G[u][v];
    }
    Dijkstra(0); //寻找从0号点到其他点的最短路径
    DFS(Sp);

    printf("%d 0",Minneed); //在这里先输出0（PBMC）
    for(int i=path.size()-2;i>=0;i--)   printf("->%d",path[i]);
    printf(" %d",Mintake);

    return 0;
}
