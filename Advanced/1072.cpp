#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int N,M,K,D; //N个house，M个备选加油站，K条roads，D为限制距离
const int maxv=1015,inf=0x3fffffff;
int G[maxv][maxv],d[maxv];
bool vis[maxv]={false};

void Dijkstra(int strart){
    fill(vis,vis+maxv,false); //由于进行了多次Dijkstra,故每次都应重置vis
    fill(d,d+maxv,inf);
    d[strart]=0;
    for(int i=1;i<=N+M;i++){//循环N+M次
        int u=-1,min=inf;
        for(int j=1;j<=N+M;j++){
            if(vis[j]==false && d[j]<min){
                u=j;
                min=d[j];
            }
        }

        if(u==-1) return ; //图不连通
        vis[u]=true; //标记选中的节点
        for(int v=1;v<=N+M;v++){
            if(vis[v]==false && G[u][v]!=inf){
                if(d[u]+G[u][v]<d[v])
                    d[v]=d[u]+G[u][v];
            }
        }
    }
}

int main(){
    scanf("%d %d %d %d",&N,&M,&K,&D);
    string a,b;
    int dis,u,v;
    //在录入图的相关信息前应先对图进行初始化
    fill(G[0],G[0]+maxv*maxv,inf);
    for(int i=0;i<K;i++){
        cin>>a>>b;
        scanf("%d",&dis);
        if(a[0]=='G'){
            a=a.substr(1);
            u=N+stoi(a);
        }else u=stoi(a);
        if(b[0]=='G'){
            b=b.substr(1);
            v=N+stoi(b);
        }else v=stoi(b);
        G[u][v]=G[v][u]=dis;
    }
    //对所有待选加油站进行Dijkstra
    int ID;
    double final_min_dis=-1,final_avg=inf;
    for(int i=N+1;i<=N+M;i++){ //顶点是从1开始的，故加油站的编号为N+1到N+M
        Dijkstra(i);
        //检验所有居民房到待选加油站的最短距离不大于D
        bool flag=true;
        double mindis=inf,avg=0;
        for(int j=1;j<=N;j++){
            if(d[j]>D){ //啥也不说了，当场退出
                flag=false;
                break;
            }
            if(d[j]<mindis) mindis=d[j];
            avg+=1.0*d[j];
        }
        if(flag==false) continue;
        
        avg/=N;
        if(mindis>final_min_dis){ //最小距离的最大值
            final_min_dis=mindis;
            final_avg=avg;
            ID=i;
        }else if(mindis==final_min_dis && avg<final_avg){
            ID=i;
            final_avg=avg;
        }
    }
    if(final_min_dis==-1)
        printf("No Solution");
    else
        printf("G%d\n%.1f %.1f",ID-N,final_min_dis,final_avg);

    return 0;
}
