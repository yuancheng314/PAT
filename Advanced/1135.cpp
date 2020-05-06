#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> arr;
struct Node{
    int data;
    Node *left,*right;
};

bool judge1(Node *root){
    if(root==NULL)   return true;
    if(root->data<0){//当前节点为红色，那么其孩子应均为黑色
        if(root->left!=NULL && root->left->data<0)  return false;
        if(root->right!=NULL && root->right->data<0) return false;
    }
    return judge1(root->left)&&judge1(root->right);
}
int get_black_num(Node *root){
    if(root==NULL)  return 0;
    int l=get_black_num(root->left);
    int r=get_black_num(root->right);
    return root->data>0 ? max(l,r)+1 : max(l,r);
}
bool judge2(Node *root){
    if(root==NULL) return true;
    int l=get_black_num(root->left);
    int r=get_black_num(root->right);
    if(l!=r)    return false;
    return judge2(root->left)&&judge2(root->right);
}
Node* buildTree(Node* root,int v){
    if(root==NULL){
        root = new Node();
        root->data=v;
        root->left=root->right=NULL;
    }else if(abs(v)<=abs(root->data))
        root->left=buildTree(root->left,v);
    else    root->right=buildTree(root->right,v);
    return root;
}

int main(){
    int K,N;
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d",&N);
        arr.resize(N);
        Node *root=NULL;
        for(int j=0;j<N;j++){
            scanf("%d",&arr[j]);
            root=buildTree(root,arr[j]);
        }
        if(arr[0]<0 || judge1(root)==false || judge2(root)==false)
            printf("No\n");
        else    printf("Yes\n");
    }

    return 0;
}
