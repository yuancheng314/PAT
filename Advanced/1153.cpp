#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct Testee{
    string info;
    int score;
};
bool cmp(Testee &a,Testee &b){
    return a.score != b.score ? a.score>b.score : a.info<b.info;
}

int main(){
    int N,M,type;
    string term;
    scanf("%d %d",&N,&M);
    vector<Testee> testee(N);
    for(int i=0;i<N;i++){
        cin>>testee[i].info>>testee[i].score;
    }
    for(int i=1;i<=M;i++){
        cin>>type>>term;
        printf("Case %d: %d %s\n",i,type,term.c_str());
        vector<Testee> ans;
        
        if(type==1){
            for(int j=0;j<N;j++){
                if(testee[j].info[0]==term[0])
                    ans.push_back(testee[j]);
            }
        }else if(type==2){
            int count=0,sum=0;
            for(int j=0;j<N;j++){
                if(testee[j].info.substr(1,3)==term){
                    count++;
                    sum+=testee[j].score;
                }
            }
            if(count==0) printf("NA\n");
            else    printf("%d %d\n",count,sum);
        }else if(type==3){
            unordered_map<string, int > a;
            for(int j=0;j<N;j++){
                if(testee[j].info.substr(4,6)==term)
                    a[testee[j].info.substr(1,3)]++;
            }
            for(auto it=a.begin();it!=a.end();it++)   ans.push_back({it->first,it->second});
        }

        sort(ans.begin(),ans.end(),cmp);
        if((type==1 || type==3)&& ans.size()==0)  printf("NA\n");
        for(int k=0;k<ans.size();k++)
            printf("%s %d\n",ans[k].info.c_str(),ans[k].score);

    }
    return 0;
}