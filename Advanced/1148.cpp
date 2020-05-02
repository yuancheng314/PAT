#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int N,count=0;
    cin>>N;
    vector<int> word(N+1),charecter(N+1);
    for(int i=1;i<=N;i++)   scanf("%d",&word[i]);
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            fill(charecter.begin(),charecter.end(),1); //每次做出新的假设前都应该重新赋值
            charecter[i]=charecter[j]=-1; //标记i和j是狼人
            vector<int> lie;
            for(int k=1;k<=N;k++){ //看谁在说谎 
                 if(word[k]*charecter[abs(word[k])]<0){
                     //如果k说的话与k评论的人的实际情况不符合，则k在说谎
                     lie.push_back(k);
                 }
            }
            if(lie.size()==2 && charecter[lie[0]]*charecter[lie[1]]<0 ){//如果恰有两个人说谎，且这两个人中只有一个狼人，那么最开始的假设是正确的那么
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    cout<<"No Solution";
}