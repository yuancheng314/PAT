#include<iostream>
#include<vector>
#include<map>
using namespace std;

int N,M;
vector<int> in,pre;
map<int,int> pos;
void foundLCA(int inleft,int inright,int preroot,int u,int v){
    if(inleft>inright)  return;
    int inroot=pos[pre[preroot]],uIn=pos[u],vIn=pos[v];
    
    if(uIn<inroot && vIn<inroot)
        foundLCA(inleft,inroot-1,preroot+1,u,v);
    else if(uIn>inroot && vIn>inroot)
        foundLCA(inroot+1,inright,preroot+1+(inroot-inleft),u,v);
    else if( (uIn<inroot && vIn>inroot) || (uIn>inroot && vIn<inroot) )
        printf("LCA of %d and %d is %d.\n",u,v,in[inroot]);
    else if(uIn==inroot)
        printf("%d is an ancestor of %d.\n",u,v);
    else if(vIn==inroot)
         printf("%d is an ancestor of %d.\n",v,u);
         
}

int main(){
    scanf("%d %d",&M,&N);
    pre.resize(N+1),in.resize(N+1);
    for(int i=1;i<=N;i++){
        scanf("%d",&in[i]);
        pos[in[i]]=i;
    }
    for(int i=1;i<=N;i++)   scanf("%d",&pre[i]);

    int u,v;
    for(int i=0;i<M;i++){
        scanf("%d %d",&u,&v);
        if(pos[u]==0 && pos[v]==0)
            printf("ERROR: %d and %d are not found.\n",u,v);
        else if(pos[u]==0 || pos[v]==0)
            printf("ERROR: %d is not found.\n",pos[u]==0 ? u : v);
        else
            foundLCA(1,N,1,u,v);
    }
    return 0;
}

