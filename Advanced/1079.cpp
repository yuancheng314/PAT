#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int N,k,child;
double P,r,total=0.0;

struct Node
{
    double val;
    vector<int> child;
};
vector<Node> node;

void dfs(int index,int depth)
{
    if(node[index].child.size()==0) 
    {
        total+=node[index].val*pow(1+r,depth);
        return ;
    }
    for(int i=0;i<node[index].child.size();i++)
        dfs(node[index].child[i],depth+1);
}

int main()
{   
    cin>>N>>P>>r;
    r/=100;
    node.resize(N);
    /*最开始我将node设置为了数组，大小直接设置成了10000
    但是发生了段错误，估计是调用层数太多，遂改为vector,便AC了*/
    for(int i = 0;i<N;i++)
    {   scanf("%d",&k);
        if(k==0)    scanf("%lf",&node[i].val);
        else 
        {
            for(int j=0;j<k;j++)
            {
                scanf("%d",&child);
                node[i].child.push_back(child);
            }
        }
    }

    dfs(0,0);//０号是根节点，直接从０号进去，初始深度为０
    printf("%.1lf",total*P);
    return 0;
}