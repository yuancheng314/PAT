#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
struct Student
{
    string name,id;
    char gender;    
    int score;
};

int main()
{   int N,f_high=0,m_low=0,countf=0,countm=0;
    cin>>N;
    Student stu[N];
    for(int i=0;i<N;i++)
    {   cin>>stu[i].name>>stu[i].gender>>stu[i].id>>stu[i].score;
        if(stu[i].gender=='F' && ( !countf || stu[i].score>stu[f_high].score) )
        {  f_high=i;    countf++;   }
        if(stu[i].gender=='M' && (!countm || stu[i].score<stu[m_low].score) )
        {   m_low=i;    countm++;   }
    }

    if(countf)  {   cout<<stu[f_high].name<<" "<<stu[f_high].id<<endl;}
    else    {   cout<<"Absent"<<endl;   }
    if(countm)  {   cout<<stu[m_low].name<<" "<<stu[m_low].id<<endl;}
    else    {   cout<<"Absent"<<endl;   }
    if(countf && countm)    
    {   cout<<stu[f_high].score-stu[m_low].score<<endl;}
    else    cout<<"NA";
    
    return 0;
}
