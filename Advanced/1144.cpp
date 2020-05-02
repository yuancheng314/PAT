#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> num(N);
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }
    sort(num.begin(),num.end());
    for(int i=0;i<N-1;i++){
        if(num[i]>=0 && num[i+1]>num[i]+1){
            printf("%d",num[i]+1);
            return 0;
        }
    }
    if(num[N-1]>=0) printf("%d",num[N-1]+1);
    else    printf("1");
    return 0;
}