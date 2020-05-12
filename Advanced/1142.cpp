#include<bits/stdc++.h>
using namespace std;

int G[205][205],vis[205]={0};

int main(){
    int Nv,Ne,M,K,u,v;
    fill(G[0],G[0]+205*205,0);
    scanf("%d %d",&Nv,&Ne);
    for(int i=0;i<Ne;i++){
        scanf("%d %d",&u,&v);
        G[u][v]=G[v][u]=1;
    }

    scanf("%d",&M);
    for(int i=0;i<M;i++){
        scanf("%d",&K);
        fill(vis,vis+205,0);
        vector<int> v(K);
        int isclique=1,isMaximal=1;

        for(int j=0;j<K;j++){
            scanf("%d",&v[j]);
            vis[v[j]]=1; //标记已访问
        }

        for(int j=0;j<K;j++){
            if(isclique==0) break;
            for(int l=j+1;l<K;l++){
                if( G[v[j]][v[l]]==0){
                    isclique=0;
                    printf("Not a Clique\n");
                    break;
                }
            }
        }
        //判断是不是maximal
        if(isclique==0)     continue;
        for(int j=1;j<=Nv;j++){
            if(vis[j]==0){//试一试
                int l;
                for( l=0;l<K;l++)
                    if(G[v[l]][j]==0)   break;
                if(l==K) isMaximal=0; //说明存在一个点与其他点都相连
            }
            if(isMaximal==0){
                printf("Not Maximal\n");
                break;
            }
        }
        if(isMaximal==1)    printf("Yes\n");
    }
    return 0;
}