#include<iostream>
#include<vector>
#include<set>
using namespace std;
struct Edge{    int u,v;    };

int main(){
    int N,M,K;
    scanf("%d%d",&N,&M);
    vector<Edge> G(M);
    for(int i=0;i<M;i++){
        scanf("%d %d",&G[i].u,&G[i].v);
    }

    scanf("%d",&K);
    for(int i=0;i<K;i++){
        int color[N];
        set<int> type;
        for(int j=0;j<N;j++){
            scanf("%d",&color[j]);
            type.insert(color[j]);
        }
        bool flag=true;
        for(int k=0;k<M;k++){
            if(color[G[k].u]== color[G[k].v]){
                flag=false;
                break;
            }
        }
        if(flag)    printf("%d-coloring\n",type.size());
        else    printf("No\n");
    }

    return 0;
}
