#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct Student{
    string id;
    int Gp,Gmid,Gfinal,G;
};
bool cmp(Student a,Student b){
    return a.G!=b.G ? a.G>b.G : a.id<b.id;
}
int main(){
    int P,M,N;
    cin>>P>>M>>N;
    vector<Student> stu;
    map<string,int> chcek;

    string id;
    int Gp,Gmid,Gfinal,G,count=1;
    for(int i=0;i<P;i++){
        cin>>id>>Gp;
        if(Gp>=200){
            stu.push_back(Student{id,Gp,-1,-1,0});
            chcek[id]=count++;
        }
    }

    for(int i=0;i<M;i++){
        cin>>id>>Gmid;
        if(chcek[id]!=0)    
            stu[chcek[id]-1].Gmid=Gmid;
    }
    for(int i=0;i<N;i++){
        cin>>id>>Gfinal;
        if(chcek[id]!=0){
            int temp=chcek[id]-1;
            stu[temp].G=stu[temp].Gfinal=Gfinal;
            if(stu[temp].Gmid>stu[temp].Gfinal)
                stu[temp].G=stu[temp].Gmid*0.4+stu[temp].Gfinal*0.6+0.5; //对一double类型数字进行四舍五入的快捷方法则是加0.5后类型转换
        }
    }
    sort(stu.begin(),stu.end(),cmp);
    for(int i=0;i<stu.size() && stu[i].G>=60 ;i++)
        printf("%s %d %d %d %d\n",stu[i].id.c_str(),stu[i].Gp,stu[i].Gmid,stu[i].Gfinal,stu[i].G);

    return 0;
}

