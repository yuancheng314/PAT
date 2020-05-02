#include<iostream>
#include<string>
using namespace std;

int main(){
    int N,j;
    string now;
    cin>>now>>N;
    for(int i=0;i<N-1;i++){
        string next;
        for(int i=0;i<now.length();i=j){
        /*注意这里i在每次循环之后的增加量为j在下一个循环中的增量，而初始i==j,故i一轮循环之后也将再次等于j*/
            for( j=i;j<now.length() && now[i]==now[j];j++);
            next+=now[i]+to_string(j-i);
        }
        now=next;
    }
    cout<<now;

    return 0;
}