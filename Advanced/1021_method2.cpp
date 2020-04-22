#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int N=10001;
vector<vector<int > >  G;
vector<int> temp,ans; 
int Father[N],isRoot[N]={0},vis[N]={0},maxheight=0; 

int findFather(int x)
{   int a=x;
    while(x!=Father[x])
        x=Father[x];
    while(a!=Father[a])
    {   //路径压缩
        int z=a;
        a=Father[a];
        Father[z]=x;
    }
    return x;
}

void Union(int a,int b)
{
    int father_a=findFather(a),father_b=findFather(b);
    if(father_a!=father_b)
        Father[father_a]=father_b;
}

void Init(int N)
{  
    for(int i=1;i<=N;i++)
        Father[i]=i;
}

int calBlock(int n)
{   int block=0;
    for(int i=1;i<=n;i++)
        isRoot[findFather(i)]=1;
    for(int i=1;i<=n;i++)
        block+=isRoot[i];
    return block;
}

void DFS(int u,int height)
{   if(height>maxheight)
    {   temp.clear(); 
		temp.push_back(u);
        maxheight=height;
    }
    else if(height==maxheight)
        temp.push_back(u);
    vis[u]=1;
    int size=G[u].size();
    for(int i=0;i<size;i++)
    {
        if(vis[G[u][i]]==0)    DFS(G[u][i],height+1);
    }

}
int main()
{   int n,a,b;
    cin>>n;
    G.resize(n+1);
  	Init(n); 
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
        Union(a,b);//可与Advanced/1013_method2.cpp中进行比较，体会两者不同
    }
    
   int Block=calBlock(n);
   if(Block>=2)  printf("Error: %d components\n",Block);
    else 
	{  DFS(1,1);
		
       ans=temp;
       fill(vis,vis+N,0);//这一步千万不能忘
       DFS(ans[0],1);
       
       for(int i=0;i<temp.size();i++)
           ans.push_back(temp[i]);
       sort(ans.begin(),ans.end());
       printf("%d\n",ans[0]);
       for(int i=1;i<ans.size();i++)
       {
           if(ans[i]!=ans[i-1])
                 printf("%d\n",ans[i]);
       }
		
    }

    return 0;
}