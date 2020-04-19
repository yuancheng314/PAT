#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string,int> string2int,Gang; //姓名转编号
map<int,string> int2string ; //编号转姓名

int N,K,person_number=0,G[2001][2001],weight[2001]={0},vis[2001]={0};

int change(string s)
{
    if(string2int.find(s)!=string2int.end()) //s已经出现过
        return string2int[s];
    else //s第一次出现
    {   string2int[s]=person_number;
        int2string[person_number]=s;
        return person_number++;
    }
}

void DFS(int now_visit,int& head,int& numMenber,int& totalweight)
{   numMenber++;
    vis[now_visit]=1;
    if(weight[now_visit]>weight[head])  head=now_visit;
    for(int i=0;i<person_number;i++)
    {
        if(G[now_visit][i]>0) //now_visit到i可达
        {
            totalweight+=G[now_visit][i];
            G[now_visit][i]=G[i][now_visit]=0; //删边以防回头
            if(vis[i]==0) //如果i未被访问，则递归访问i
                DFS(i,head,numMenber,totalweight);
        }
    }
}

void DFSTrave()
{
    for(int i=0;i<person_number;i++)
    {
        if(vis[i]==0) //当前节点尚未被访问
        {
            int head=i,numMenber=0,totalweight=0; //头目，成员数，当前团伙总权重
            DFS(i,head,numMenber,totalweight); //遍历i所在的连通块
            if(numMenber>2 && totalweight>K) //保存团伙信息
               Gang[int2string[head]] = numMenber; 
        }
    }
}

int main()
{   string s1,s2;
    int w;
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++)
    {   cin>>s1>>s2>>w;
        int id1=change(s1);
        int id2=change(s2);
        weight[id1]+=w; //增加id1的点权值
        weight[id2]+=w; //增加id2的点权值
        G[id1][id2]+=w; //增加边id1->id2的权值
        G[id2][id1]+=w; //增加边id1->id1的权值
    }
    DFSTrave(); //遍历整个图的所有连通快
    cout<<Gang.size()<<endl;
    for(auto it=Gang.begin(); it!=Gang.end(); it++)
        cout<<it->first<<" "<<it->second<<endl;
    return 0;   
}