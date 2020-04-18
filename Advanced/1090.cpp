#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int N,father,root,maxdepth=0,maxdepth_num=0;
double P,r;

struct Node
{   int father=-1;
    vector<int> child; 
};

vector<Node> node;

void dfs(int index,int depth)
{   if(node[index].child.size()==0)
    {   //到叶节点了，考虑是否更新最大深度
        if(depth>maxdepth)
        {
            maxdepth=depth;
            maxdepth_num=1; //重置最大深度的叶子节点的个数
        }
        else if(depth==maxdepth)    maxdepth_num++;
        
        return;
    }
    
    for(int i=0;i<node[index].child.size();i++)
        dfs(node[index].child[i],depth+1);

}

int main()
{   cin>>N>>P>>r;

    r/=100;
    node.resize(N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&father);
        if(father==-1)  root=i;
        else
        {
            node[i].father=father;
            node[father].child.push_back(i);
        }
    }

    dfs(root,0);
    printf("%.2lf %d",P*pow(1+r,maxdepth),maxdepth_num);
    return 0;
}