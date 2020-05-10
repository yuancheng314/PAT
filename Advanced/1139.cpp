#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct Node{
    int a,b;
};
bool cmp(Node x,Node y){
    return x.a != y.a ? x.a<y.a : x.b<y.b;
}
unordered_map<int,bool> friends;
int N,M,K;
vector<int> same_gender_friends[10000];
int main(){
    scanf("%d%d",&N,&M);

    string a,b;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        if(a.length()==b.length()) { //长度相同则性别相同
            same_gender_friends[abs(stoi(a))].push_back(abs(stoi(b)));
            same_gender_friends[abs(stoi(b))].push_back(abs(stoi(a)));
        }
        friends[abs(stoi(a))*10000+abs(stoi(b))]= friends[abs(stoi(b))*10000+abs(stoi(a))]=true;   
    }
    int c,d;
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d %d",&c,&d);
        vector<Node> ans;
        for(int j=0;j<same_gender_friends[abs(c)].size(); j++ ){
            for(int k=0;k<same_gender_friends[abs(d)].size();k++){
                if(same_gender_friends[abs(c)][j]==abs(d) || abs(c)==same_gender_friends[abs(d)][k] )
                    continue; //坑点，两个本身就是好朋友，还有暧昧
                if(friends[same_gender_friends[abs(c)][j]*10000+ same_gender_friends[abs(d)][k]]==true)
                    ans.push_back(Node{same_gender_friends[abs(c)][j],same_gender_friends[abs(d)][k]} );
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        printf("%d\n",(int)ans.size() );
        for(int j=0;j<ans.size();j++)
            printf("%04d %04d\n",ans[j].a,ans[j].b);
    }
    return 0;
}