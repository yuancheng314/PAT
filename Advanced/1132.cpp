#include<iostream>
#include<string>
using namespace std;

int main(){
    int N,left,right,len;
    string  num;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        len=num.length();
        left=stoi(num.substr(0,len/2));
        right=stoi(num.substr(len/2,len-len/2));
        if((left*right!=0) && stoi(num)%(left*right)==0 )
            printf("Yes\n");
        else printf("No\n");

    }
    return 0;
}

