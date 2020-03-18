#include<iostream>
#include<cstring>
using namespace std;

int main()
{   long long Pg,Ps,Pk,Ag,As,Ak,P,A,total;
    scanf("%d.%d.%d %d.%d.%d",&Pg,&Ps,&Pk,&Ag,&As,&Ak);
    total=((Pg+Ag)*17+(Ps+As))*29+(Pk+Ak);
    cout>>total/29/17>>"."<<total/29%17<<"."<<total%29;  
    return 0;
}
