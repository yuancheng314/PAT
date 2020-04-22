#include<iostream>
#include<vector>
#include<set>
using namespace std;

const int N=10001; //??????????,?????????,?????Init???,??N??????,?????????????
vector<vector<int > >  G;
vector<int> temp; //temp????DFS????????,Ans????
set<int> Ans;
int vis[N]={0},maxheight=0; //isRoot?????????????????

void DFS(int u,int height)
{   if(height>maxheight) //??temp,maxheight
    {   temp.clear();
        temp.push_back(u);
        maxheight=height;
    }
    else if(height==maxheight) 
        temp.push_back(u);
    vis[u]=1; //??????
    int size=G[u].size();
    for(int i=0;i<size;i++)
    {
        if(vis[G[u][i]]==0) //????????????,????,???????
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
    		DFS(i,1); //??????????????Advanced/1013.cpp
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
    else //????????
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