#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main()
{   int N,y,m,d,now=20140906,birth,count=0,old_birth=20140906,young_birth=18140906;
    string old_name,young_name,name;
    cin>>N;
  
    for(int i=0;i<N;i++)
    {   cin>>name;   
        scanf("%d/%d/%d",&y,&m,&d);  
        birth=d+100*m+10000*y;
        if(birth<=now && birth>=now-2000000)
        {   count++;  
            if(birth <old_birth)
            {   
                old_name=name; 
                old_birth=birth;
            }
            if(birth>young_birth)
            {  
                young_name=name;
                young_birth=birth;
            }
        }
    }    
    cout<<count;
    if(count) cout<<" "<<old_name<<" "<<young_name;

    return 0;
}
