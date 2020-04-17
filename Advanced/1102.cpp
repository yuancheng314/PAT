#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N,levcount=1,incount=1;

struct Node
{   int left=-1,right=-1,father=-1; };

vector<Node> node(10);

void printlever(int root)
{   queue<int> q;
    int cur;
    q.push(root);
    while(!q.empty())
    {   cur=q.front();
        
        printf("%d",cur);
        if(levcount++<N)  printf(" ");
        else printf("\n");
        
        if(node[cur].left!=-1)    q.push(node[cur].left);
        if(node[cur].right!=-1)   q.push(node[cur].right);
        q.pop();        
    }
    return;
}

void printinorder(int root)
{   if(root==-1)    return;  
    printinorder(node[root].left); 
    printf("%d",root);
    if(incount++<N)  printf(" ");
    else printf("\n");
    printinorder(node[root].right); 
}

int main()
{   
    string lchild,rchild; 

    cin>>N;    
    for(int i=0;i<N;i++)
    {    cin>>lchild>>rchild;
        //构造时便反着构造
        if(lchild!="-") 
        {   node[i].right=stoi(lchild);
            node[stoi(lchild)].father=i;
        }
        if(rchild!="-") 
        {   node[i].left=stoi(rchild);
            node[stoi(rchild)].father=i;
        }
    }
    int root;
    for( root=0;root<N && node[root].father!=-1 ;root++ );  //不要遗忘逗号，之前就搞忘了
    printlever(root);
    printinorder(root);
    
    return 0;
}