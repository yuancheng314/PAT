/* 测试输入：
6 10
0 1 4 
0 4 1
0 5 2
1 2 1
1 5 3
2 3 6
2 5 5
3 4 5
3 5 4
4 5 3
预期输出：
11
*/

#include<iostream>
#include<algorithm>
using namespace std;

const int MAXV=105,MAXE=10010;
//边集定义部分
struct  edge{
    int u,v;//边的两个端点编号
    int cost; //边权
}E[MAXE];

bool cmp(edge a,edge b){
    return a.cost<b.cost;
}

//并查集部分
int Father[MAXV];
int findFather(int x){
    int a=x;
    while(x!=Father[x]) x=Father[x];
    //路径压缩
    while(a!=Father[a]){
        int z=a;
        a=Father[a];
        Father[z]=x;
    }
    return x;
}

//kruskal部分，返回最小生成树的边权之和，参数为n个顶点个数，m为图的边数
int kurskal(int n,int m){
    //ans为所求边权之和，Num_Edge为当前生成的边数
    int ans=0,Num_Edge=0;
    for(int i=0;i<n;i++){
        Father[i]=i;
    }
    sort(E,E+m,cmp);//所有边按边权从小到大排序

    int FaU,FaV;
    for(int i=0;i<m;i++){// 枚举所有边
        FaU=findFather(E[i].u);
        FaV=findFather(E[i].v);
        if(FaU!=FaV){ //不在一个集合之中
            Father[FaU]=FaV; //认别人做爸爸
            ans+=E[i].cost;
            Num_Edge++; //边的个数加1
            if(Num_Edge==n-1)  break; //边的条数已经够了，那么结束吧
        }
    }
    if(Num_Edge!=n-1) return -1; //无法连通 
    else return ans;
}

int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d %d %d",&E[i].u,&E[i].v,&E[i].cost);
    }
    int ans=kurskal(N,M);
    printf("%d\n",ans);
    return 0;
}
