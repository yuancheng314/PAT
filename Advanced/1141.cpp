#include<iostream>
#include<string>
#include<unordered_map>
#include<cctype>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
    string school;
    int TWS,NS;
};
bool cmp(Node a,Node b){
    if(a.TWS!=b.TWS)    return a.TWS>b.TWS;
    else if(a.NS!=b.NS) return a.NS<b.NS;
    else    return a.school<b.school;
}
int main(){
    int N;
    double score;
    string ID,school;
    unordered_map<string,int> count;
    unordered_map<string ,double> sum;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        cin>>ID>>score>>school;
        for(int j=0;j<school.length();j++)   school[j]=tolower(school[j]);
        if(ID[0]=='B')  score/=1.5;
        else if(ID[0]=='T') score*=1.5;

        sum[school]+=score;
        count[school]++;
    }

    vector<Node> ans;
    for(auto it=count.begin();it!=count.end();it++)
        ans.push_back(Node{it->first,(int)sum[it->first],it->second});
    sort(ans.begin(),ans.end(),cmp);
    printf("%d\n",(int)ans.size());
    int rank=1;
    printf("%d %s %d %d\n",rank,ans[0].school.c_str(),ans[0].TWS,ans[0].NS);
    for(int i=1;i<ans.size();i++){
        rank= ans[i].TWS!=ans[i-1].TWS ? i+1 : rank;
        printf("%d %s %d %d\n",rank,ans[i].school.c_str(),ans[i].TWS,ans[i].NS);
    }

    return 0;
}