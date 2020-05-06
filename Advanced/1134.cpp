#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N,M,K,u,v;
    cin>>N>>M;
    vector<int> G[N];
    int edge[M]={0};
    for(int i=0;i<M;i++){
        scanf("%d %d",&u,&v);
        G[u].push_back(i);
        G[v].push_back(i);
    }

    scanf("%d",&K);
    int num,cur;
    for(int i=1;i<=K;i++){
        scanf("%d",&num);
        fill(edge,edge+M,0);
        for(int n=0;n<num;n++){
            scanf("%d",&cur);
            for(int k=0;k<G[cur].size();k++)
                edge[G[cur][k]]=1;
        }
        int flag=0;
        for(int j=0;j<M;j++){
            if(edge[j]==0){
                printf("No\n");
                flag=1;
                break;
            }
        }
        if(flag==0) printf("Yes\n");
    }
    return 0;
}