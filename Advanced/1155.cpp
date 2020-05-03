#include<iostream>
#include<vector>
using namespace std;

int N,tree[1010];
bool MinHeapFlag=true,MaxHeapFlag=true;
vector<int> path;
void DFSprintTree(int index){
    if(2*index>N ){ //递归边界
        if(index<=N){ //这个判断条件不能，否则会多输出一行
            for(int i=0;i<path.size();i++)
                printf("%d%s",path[i],i==path.size()-1 ? "\n" : " ");
        }
    }
    else{ //记得路径维护
        path.push_back(tree[2*index+1]);
        DFSprintTree(2*index+1);
        path.pop_back();
        path.push_back(tree[2*index]);
        DFSprintTree(2*index);
        path.pop_back();
    }
}

int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        scanf("%d",&tree[i]);
    }
    path.push_back(tree[1]);
    DFSprintTree(1);

    for(int i=2;i<=N;i++){ //注意循环的初始条件写法
        if(tree[i]<tree[i/2])   MinHeapFlag=false; //最小堆的情况被排除
        if(tree[i]>tree[i/2])   MaxHeapFlag=false; //最大堆的情况被排除
    }
    if(MaxHeapFlag) cout<<"Max Heap";
    else if(MinHeapFlag) cout<<"Min Heap";
    else cout<<"Not Heap";

    return 0;
}