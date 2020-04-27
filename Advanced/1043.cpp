#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int val;
    Node *left,*right;
};

void insert(Node* &root,int value ){
    if(root == NULL){ //到达空节点时，即为需要插入的位置
        root  = new Node;
        root->val=value;
        root->left=root->right=NULL;
        return ;
    }
    if(value<root->val)     insert(root->left,value); //插在左子树
    else insert(root->right,value); //插在右子树
}

void preOrder(Node* root,vector<int> &pre){
    if(root==NULL)   return;
    //当前访问节点非空
    pre.push_back(root->val);
    preOrder(root->left,pre); //递归左子树
    preOrder(root->right,pre); //递归右子树
}

void preOrderMirror(Node* root,vector<int> &preMirr){
    if(root==NULL)   return;
    //当前访问节点非空
    preMirr.push_back(root->val);
    preOrderMirror(root->right,preMirr); //递归右子树
    preOrderMirror(root->left,preMirr); //递归左子树
}
void postOrder(Node* root,vector<int> &post){
    if(root==NULL)   return;
    //当前访问节点非空
    postOrder(root->left,post); //递归左子树
    postOrder(root->right,post); //递归右子树
    post.push_back(root->val);
}

void postOrderMirror(Node* root,vector<int> &postMirr){
    if(root==NULL)   return;
    //当前访问节点非空
    postOrderMirror(root->right,postMirr); //递归右子树
    postOrderMirror(root->left,postMirr); //递归左子树
    postMirr.push_back(root->val);
}

vector<int> origin,pre,preMirr,post,postMirr;

int main(){
    int N,value;
    Node* root=NULL;
    cin>>N;
    for(int i=0;i<N;i++){
        scanf("%d",&value);
        origin.push_back(value);
        insert(root,value);
    }

    preOrder(root,pre);
    if(origin==pre){
        postOrder(root,post);
        printf("YES\n");
        for(int i=0;i<post.size();i++){
            printf("%d",post[i]);
            if(i!=post.size()-1)    printf(" ");
        }
        return 0;
    }else{
        preOrderMirror(root,preMirr);
        if(origin==preMirr){
            postOrderMirror(root,postMirr);
            printf("YES\n");
            for(int i=0;i<postMirr.size();i++){
                printf("%d",postMirr[i]);
                if(i!=postMirr.size()-1)  printf(" ");
            }
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}
