#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> node[110];
int N,M,depth[110]={0},maxdepth=1; //题设节点不多于100个，故最多100层，depth[i]记录第i层叶子节点个数

void DFS(int root,int layer){
    int num=node[root].size();
    if(num==0){ //递归边界条件为当前节点没有孩子
        depth[layer]++; //将当前节点所在层的叶子节点个数加1
        return;
    }
    maxdepth= max(maxdepth,layer+1); 
    for(int i=0;i<num;i++)
        DFS(node[root][i],layer+1);
}

int main(){
    cin>>N>>M;
    int father,K,child;
    for(int i=0;i<M;i++){
        scanf("%d %d",&father,&K);
        for(int i=0;i<K;i++){
            scanf("%d",&child);
            node[father].push_back(child);
        }
    }
    DFS(01,1); //从根节点开始深度遍历，记根节点的深度为1

    for(int i=1;i<=maxdepth;i++){
        printf("%d",depth[i]);
        if(i!=maxdepth)     printf(" ");
    }

    return 0;
}
