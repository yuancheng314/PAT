#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> postorder(31),inorder(31);

struct Node
{
    int val;
    Node* left;
    Node* right;
};

Node* reBuildTree(int postbegin,int  postend ,int  inbegin, int  inend)
{   if(postbegin>postend)  return NULL;
    Node* root=new Node;
    root->val=postorder[postend];

    int k;
    for(k=inbegin;k<=inend;k++)
    {
        if(inorder[k]==postorder[postend])   break;
    }
   
    int numleft=k-inbegin;
    root->left=reBuildTree(postbegin,postbegin+numleft-1,inbegin ,k-1);
    root->right=reBuildTree(postbegin+numleft ,postend-1 ,k+1 ,inend );
   
    return root;
}

vector<int> Getlevorder(Node* tree)
{  
    vector<int> levorder;
    queue<Node*> q;
    q.push(tree);

    Node* cur;
    while(!q.empty())
    {   cur=q.front();
        levorder.push_back(cur->val);
      
        if(cur->left!=NULL)    q.push(cur->left);
        if(cur->right!=NULL)   q.push(cur->right);
        q.pop();
    }
    return levorder;
}

int main()
{   int N;
    scanf("%d",&N);
   
    for(int i=0;i<N;i++)
        scanf("%d",&postorder[i]);
    for(int i=0;i<N;i++)
        scanf("%d",&inorder[i]); 
    
    Node* tree = reBuildTree(0,N-1,0,N-1);
    vector<int> res=Getlevorder(tree);

    for(int i=0;i<N; i++)
    {
        if(i!=0)    printf(" ");
        printf("%d",res[i]);
    }
        
    return 0;
}