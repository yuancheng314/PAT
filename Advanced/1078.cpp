#include<bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    if(x<=1)    return false;
    if(x==2)    return true;
    int sqr=sqrt(x);
    for(int i=2;i<=sqr;i++){
        if(x%i==0)  return false;
    }
    return true;
}

int find_suitalbe_prime(int x){
    while(isPrime(x)!=true) x++;
    return x;
}

int main(){
    int n,m,x;
    scanf("%d %d",&m,&n);
    int size=find_suitalbe_prime(m);
    int hash[size];
    fill(hash,hash+size,0);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(i!=0)    printf(" ");
        int step;
        for(step=0;step<size;step++){
            int index=(x+step*step)%size;
            if(hash[index]==0){
                printf("%d",index%size);
                hash[index]=1;
                break;
            }
        }
        if(step==size)     printf("-");
    }

    return 0;
}
