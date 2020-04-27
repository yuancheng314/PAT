#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
vector<int> node[110];
int N,M,level[100]={0},lay[100]={0};//题设节点不多于100个，故最多100层，depth[i]记录第i层叶子节点个数
//level[i]记录节点i所在层数，lay[i]记录第i层的节点个数
int max_num=1,max_level=1;

void BFS(int root ){
    queue<int> q;
    q.push(root);
    level[root]=1;

    int cur,num;
    while(!q.empty()){
        cur=q.front();
        num=node[cur].size();
    
        for(int i=0;i<num;i++){//将当前访问节点的所有孩子入队
            q.push(node[cur][i]);
            level[node[cur][i]]=level[cur]+1; //子节点所在层数是父节点所在层数加1；
        }
        lay[level[cur]+1]+=num; //更新当前节点子节点所在层的节点个数
     
        if(lay[level[cur]+1]>max_num){ //判断是否需要更新节点最多的层
            max_num=lay[level[cur]+1];
            max_level=level[cur]+1;
        }
        q.pop(); //当前节点出队
    }
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
    BFS(01); //从根节点开始深度遍历，记根节点的深度为1
    printf("%d %d",max_num,max_level);
   
    return 0;
}
