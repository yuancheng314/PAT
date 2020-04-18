#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,M,W;
struct Node
{   
    int val,father=-1,isleaf=1;
    vector<int> child;
};
vector<Node> node;

void printpath(int leaf)
{   vector<int> res;
    int now_node=leaf;   
    while(node[now_node].father!=-1) //当前处理的节点有父亲节点时继续
    {
        res.push_back(node[now_node].val);
        now_node=node[now_node].father;
    }
    res.push_back(node[now_node].val);
    reverse(res.begin(),res.end());
    printf("%d",res[0]);
    for(int i=1;i<res.size();i++)
        printf(" %d",res[i]);
    printf("\n");
}

void dfs(int root,int sum)
{   //即使路径和达到sum，若当前点不是叶子节点，还是不能输出
    if(sum>W || (sum==W && node[root].isleaf==0) )   return;
    if(sum==W)   printpath(root);
    for(int i=0;i<node[root].child.size();i++)
        dfs(node[root].child[i],sum+node[node[root].child[i]].val);
}
bool cmp(int a,int b)   { return node[a].val>node[b].val;   }

int main()
{   cin>>N>>M>>W;
    node.resize(N);
    int value,cur_node,child,child_num;

    for(int i=0;i<N;i++)
    {   //录入权重信息
        scanf("%d",&value);
        node[i].val=value;
    }
    for(int i=0;i<M;i++)
    {   //录入父子关系构造树
        scanf("%d",&cur_node);
        node[cur_node].isleaf=0; //标记当前节点非叶子节点
        scanf("%d",&child_num);
        for(int i=0;i<child_num;i++)
        {
            scanf("%d",&child);
            node[child].father=cur_node;
            node[cur_node].child.push_back(child);
        }
        sort(node[cur_node].child.begin(),node[cur_node].child.end(),cmp);
        /*反正又不是二叉树，便可对孩子节点进行排序，排序后处理题目的输出要求更方便*/
    }
    dfs(0,node[0].val);
    return 0;
}
