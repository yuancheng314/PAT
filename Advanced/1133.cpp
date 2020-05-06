#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data,next;
}node[100010];

int main(){
    int start_add,N,K,address,data,next;
    vector<int> ans[3];

    scanf("%d %d %d",&start_add,&N,&K);
    for(int i=0;i<N;i++){
        scanf("%d %d %d",&address,&data,&next);
        node[address].data=data;
        node[address].next=next;
    }

    for(int i=start_add;i!=-1;i=node[i].next){

        if(node[i].data>K){ 
           ans[2].push_back(i);
        }else if(node[i].data>=0){
            ans[1].push_back(i);
        }else
            ans[0].push_back(i);
    }

    int first=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<ans[i].size();j++){
            if(first==1){
                printf("%05d %d ",ans[i][j],node[ans[i][j]].data);
                first=0;
            }else   printf("%05d\n%05d %d ",ans[i][j],ans[i][j],node[ans[i][j]].data); 
        }
    }
    printf("-1");
    
    return 0;
}