#include<iostream>
#include<algorithm>
using namespace std;

struct Node{
    int val,height;
    Node *left,*right;
};

int getHeight(Node*  root){
    if(root==NULL)  return 0;
    return root->height;
}

void updateHeight(Node* root){
    root->height=max(getHeight(root->left),getHeight(root->right))+1;
}

int getBalanceFactor(Node* root){//左子树高度减右子树高度
    return getHeight(root->left)-getHeight(root->right);
}

void RightRotation(Node* &root){
    Node* temp=root->left;
    root->left=temp->right;
    temp->right=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}

void LeftRotation(Node* &root){
    Node* temp=root->right;
    root->right=temp->left;
    temp->left=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}

void insert(Node* &root,int val){
    if(root==NULL){//到达空节点，则新建一个
        root=new Node();
        root->val=val;
      	root->height=1;
        root->left=root->right=NULL;
        return;
    }else if(val<root->val) {//要插入的的节点值比根节点小，往左子树插
        insert(root->left,val);
        updateHeight(root);//更新树高
        if(getBalanceFactor(root)==2){
            if(getBalanceFactor(root->left)==1) //LL
                RightRotation(root);
            else if(getBalanceFactor(root->left)==-1){ //LR
                LeftRotation(root->left);
                RightRotation(root);
            }
        }
    }else{//要插入的的节点值比根节点大，往右子树插
         insert(root->right,val);
        updateHeight(root);//更新树高
        if(getBalanceFactor(root)==-2){
            if(getBalanceFactor(root->right)==-1) //RR
                LeftRotation(root);
            else if(getBalanceFactor(root->right)==1){ //RL
                RightRotation(root->right);
                LeftRotation(root);
            }
        }
    }
}
Node* create(int *a,int n){
    Node *root=NULL;
    for(int i=0;i<n;i++)
        insert(root,a[i]);
    return root;
}
int main(){
    int N,val,a[30];
    cin>>N;
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    Node* root=create(a,N);
    printf("%d",root->val);
    return 0;
}
