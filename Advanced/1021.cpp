#include<iostream>
#include<vector>
#include<set>
using namespace std;

const int N=10001; //一开始我使用了宏定义，然而发现如果使用宏，在后续构造Init函数时，形参N也会被替换掉，所以这种还是最好不要使用宏
vector<vector<int > >  G;
vector<int> temp; //temp临时存放DFS的最远结果点结果,Ans保存答案
set<int> Ans;
int vis[N]={0},maxheight=0; //isRoot记录每个节点是否为某个集合的根节点

void DFS(int u,int height)
{   if(height>maxheight) //更新temp,maxheight
    {   temp.clear();
        temp.push_back(u);
        maxheight=height;
    }
    else if(height==maxheight) 
        temp.push_back(u);
    vis[u]=1; //更新访问标识
    int size=G[u].size();
    for(int i=0;i<size;i++)
    {
        if(vis[G[u][i]]==0) //一开始这句后面加了个分号，当场毙命，找了很久才发现
            DFS(G[u][i],height+1);
    }

}
int main()
{   int n,a,b;
    cin>>n;
    G.resize(n+1);
  
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    int count=0,s1=0;
    for(int i=1;i<=n;i++)
    {
    	if(vis[i]==0)
    	{
    		DFS(i,1); //这里关于图的深度优先可以参考Advanced/1013.cpp
    		if(i==1)
    		{
    			if(temp.size()!=0) s1=temp[0];
    			for(int j=0;j<temp.size();j++)
    				Ans.insert(temp[j]);
			}
			count++;
		}
	}
    
    if(count>=2)  printf("Error: %d components\n",count);
    else //联通分量只有一个
    {   
		temp.clear();
		maxheight=0;
		fill(vis,vis+N,0);
        DFS(s1,1);
         for(int i=0;i<temp.size();i++)
             Ans.insert(temp[i]);
          for(auto it = Ans.begin();it!=Ans.end();it++)
              printf("%d\n",*it);    
    }
    return 0;
}
