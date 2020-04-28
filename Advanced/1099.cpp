#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int origin[101],cnt=0;
struct Node{
    int val,left,right;
}node[100];

void inorder(int root){
    if(root==-1)    return;
    inorder(node[root].left); 
    node[root].val=origin[cnt++];
    inorder(node[root].right);
}
void BFS(int root){
    queue<int> q;
    q.push(root);
    int num=0,cur;
    while(!q.empty()){
        cur=q.front();
        q.pop();
        if(num++!=0) printf(" ");
        printf("%d",node[cur].val);
        if(node[cur].left!=-1)  q.push(node[cur].left);
        if(node[cur].right!=-1)  q.push(node[cur].right);
    }
}

int main(){
   int N;
   cin>>N;
   for(int i=0;i<N;i++) scanf("%d %d",&node[i].left,&node[i].right);
   for(int i=0;i<N;i++) scanf("%d",&origin[i]);
   sort(origin,origin+N);
   inorder(0); //以0号节点为根节点进行中序遍历，填入整数
   BFS(0);

    return 0;
}
