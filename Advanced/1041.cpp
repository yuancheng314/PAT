#include<iostream>
using namespace std;

int main(){
    int N,val[100001],times[10001]={0};
    cin>>N;
    for(int i=0;i<N;i++)
    {   scanf("%d",&val[i]);
        times[val[i]]++;
    }
    for(int i=0;i<N;i++){
        if(times[val[i]]==1){
            printf("%d",val[i]);
            return 0;
        }
    }  
    printf("None");
    return 0;
}
